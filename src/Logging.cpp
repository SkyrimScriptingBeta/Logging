#define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME _SkyrimScripting_Logging_

// Include spdlog support for a basic file logger
#include <spdlog/sinks/basic_file_sink.h>

// Allows us to check if a debugger is attached (optional, see below)
#include <SKSE/SKSE.h>
#include <Windows.h>
#include <spdlog/sinks/msvc_sink.h>

#include <atomic>
#include <filesystem>
#include <format>

#include "SkyrimScripting/Logging/Config.h"
#include "SkyrimScripting/Logging/Logging.h"

// HMM / NOTE: as this is a static library now, this doesn't make as much sense:...

// If SKSEPlugin is available, we'll use it to get the plugin name
// otherwise we'll fall back to a provided name via macro definition
#if __has_include(<SKSEPluginInfo.h>)
    #include <SKSEPluginInfo.h>
#endif

// If _Log_ is available, we'll setup its spdlog adapter
#if __has_include(<_Log_/Adapters/spdlog/Adapter.h>)
    #include <_Log_/Adapters/spdlog/Adapter.h>
#endif

namespace SkyrimScripting::Logging {
    namespace Config {
        static bool                  _logging_disabled     = false;
        static bool                  _log_to_debug_console = false;
        static std::filesystem::path _log_full_path;
        static std::filesystem::path _log_file_name;
        static std::filesystem::path _log_folder_path;

        const bool is_logging_disabled() { return _logging_disabled; }
        void       set_logging_disabled(bool value) { _logging_disabled = value; }

        const bool log_to_debug_console() { return _log_to_debug_console; }
        void       set_log_to_debug_console(bool value) { _log_to_debug_console = value; }

        const std::filesystem::path log_full_path() { return _log_full_path; }
        void set_log_full_path(const std::filesystem::path& value) { _log_full_path = value; }

        const std::filesystem::path log_file_name() { return _log_file_name; }
        void set_log_file_name(const std::filesystem::path& value) { _log_file_name = value; }

        const std::filesystem::path log_folder_path() { return _log_folder_path; }
        void set_log_folder_path(const std::filesystem::path& value) { _log_folder_path = value; }
    }

    std::atomic<bool> IsLoggerInitialized;

    const std::filesystem::path GetSKSELogFolder() {
        auto logsFolder = SKSE::log::log_directory();
        if (!logsFolder)
            SKSE::stl::report_and_fail("SKSE log_directory not provided, logs disabled.");
        return *logsFolder;
    }

    void InitializeLogger() {
        if (IsLoggerInitialized.exchange(true)) return;
        if (Config::is_logging_disabled()) return;

        std::filesystem::path logPath = Config::log_full_path();

        if (logPath.empty()) {
            if (!Config::log_folder_path().empty() && !Config::log_file_name().empty()) {
                logPath = Config::log_folder_path() / Config::log_file_name();
            } else if (!Config::log_folder_path().empty()) {
#if __has_include(<SKSEPluginInfo.h>)
                auto* pluginName = SKSEPluginInfo::GetPluginName();
#elifdef SKSE_PLUGIN_NAME
                auto* pluginName = SKSE_PLUGIN_NAME;
#else
    #error \
        "SKSEPluginInfo.h not found and SKSE_PLUGIN_NAME not defined. To use SkyrimScripting.Logging, please either provide a log file name or a log folder path OR define SKSE_PLUGIN_NAME"
#endif
                logPath = Config::log_folder_path() / std::format("{}.log", pluginName);
            } else if (!Config::log_file_name().empty()) {
                logPath = GetSKSELogFolder() / Config::log_file_name();
            } else {
#if __has_include(<SKSEPluginInfo.h>)
                auto* pluginName = SKSEPluginInfo::GetPluginName();
#elifdef SKSE_PLUGIN_NAME
                auto* pluginName = SKSE_PLUGIN_NAME;
#else
    #error \
        "SKSEPluginInfo.h not found and SKSE_PLUGIN_NAME not defined. To use SkyrimScripting.Logging, please either provide a log file name or a log folder path OR define SKSE_PLUGIN_NAME"
#endif
                logPath = GetSKSELogFolder() / std::format("{}.log", pluginName);
            }
        }

        auto fileLoggerPtr =
            std::make_shared<spdlog::sinks::basic_file_sink_mt>(logPath.string(), true);

        std::shared_ptr<spdlog::logger> loggerPtr;
        if (Config::log_to_debug_console() && IsDebuggerPresent()) {
            auto debugLoggerPtr = std::make_shared<spdlog::sinks::msvc_sink_mt>();
            spdlog::sinks_init_list loggers{std::move(fileLoggerPtr), std::move(debugLoggerPtr)};
            loggerPtr = std::make_shared<spdlog::logger>("log", loggers);
        } else {
            loggerPtr = std::make_shared<spdlog::logger>("log", std::move(fileLoggerPtr));
        }

        spdlog::set_default_logger(std::move(loggerPtr));
        spdlog::set_level(spdlog::level::trace);
        spdlog::flush_on(spdlog::level::trace);

#if __has_include(<_Log_/Adapters/spdlog/Adapter.h>)
        _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().SetSpdlogLogger(
            spdlog::default_logger()
        );
#endif
    }
}