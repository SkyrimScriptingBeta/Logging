// Include spdlog support for a basic file logger
#include <spdlog/sinks/basic_file_sink.h>

// Allows us to check if a debugger is attached (optional, see below)
#include <SKSE/SKSE.h>
#include <SKSEPluginInfo.h>
#include <Windows.h>
#include <_Log_/Adapters/spdlog/Adapter.h>
#include <spdlog/sinks/msvc_sink.h>

#include <atomic>
#include <filesystem>
#include <format>

#include "SkyrimScripting/Logging/Config.h"
#include "SkyrimScripting/Logging/Logging.h"

namespace SkyrimScripting::Logging {

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
            if (!Config::log_folder_path().empty() && !Config::log_file_name().empty())
                logPath = Config::log_folder_path() / Config::log_file_name();
            else if (!Config::log_folder_path().empty())
                logPath = Config::log_folder_path() /
                          std::format("{}.log", SKSEPluginInfo::GetPluginName());
            else if (!Config::log_file_name().empty())
                logPath = GetSKSELogFolder() / Config::log_file_name();
            else
                logPath =
                    GetSKSELogFolder() / std::format("{}.log", SKSEPluginInfo::GetPluginName());
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

        _Log_::Adapters::Spdlog::SpdlogAdapter::GetSingleton().SetSpdlogLogger(
            spdlog::default_logger()
        );
    }
}