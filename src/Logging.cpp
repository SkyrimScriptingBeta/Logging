// Include spdlog support for a basic file logger
#include <spdlog/sinks/basic_file_sink.h>

// TODO remove
#include <RE/Skyrim.h>

// Allows us to check if a debugger is attached (optional, see below)
#include <SKSE/SKSE.h>
#include <SKSEPluginInfo.h>
#include <Windows.h>
#include <spdlog/sinks/msvc_sink.h>

#include <atomic>
#include <filesystem>
#include <format>

namespace SkyrimScripting::Logging::Internal {
    std::atomic<bool> IsLoggerInitialized;

    void InitializeLogger() {
        if (IsLoggerInitialized.exchange(true)) return;

        // return;  // Disable for now!

        // Get the logs folder
        auto logsFolder = SKSE::log::log_directory();
        if (!logsFolder) {
            SKSE::stl::report_and_fail("SKSE log_directory not provided, logs disabled.");
            return;
        }

        // Get the plugin name
#ifdef SKSE_PLUGIN_NAME
        auto* pluginName = SKSE_PLUGIN_NAME;
#elif __has_include(<SKSEPluginInfo.h>)
        auto* pluginName = SKSEPluginInfo::GetPluginName();
#else
    #error \
        "SKSEPluginInfo.h not found and SKSE_PLUGIN_NAME not defined. To use SkyrimScripting.Logging, please either provide a log file name or a log folder path OR define SKSE_PLUGIN_NAME"
#endif

        // Construct the log path
        auto logPath = *logsFolder / std::format("{}.log", pluginName);

        // Create the file logger
        auto fileLoggerPtr =
            std::make_shared<spdlog::sinks::basic_file_sink_mt>(logPath.string(), true);

        // Create the spdlog logger pointer
        //
        // Minor known issue: if logs directory was for some reason not created,
        // this code does not run so the debugger logger is not created in that case
        std::shared_ptr<spdlog::logger> loggerPtr;
        if (IsDebuggerPresent()) {
            auto debugLoggerPtr = std::make_shared<spdlog::sinks::msvc_sink_mt>();
            spdlog::sinks_init_list loggers{std::move(fileLoggerPtr), std::move(debugLoggerPtr)};
            loggerPtr = std::make_shared<spdlog::logger>("log", loggers);
        } else {
            loggerPtr = std::make_shared<spdlog::logger>("log", std::move(fileLoggerPtr));
        }

        // Setup the logger
        spdlog::set_default_logger(std::move(loggerPtr));

        // The default level is the lowest level, trace
        spdlog::set_level(spdlog::level::trace);
        spdlog::flush_on(spdlog::level::trace);

        // Use the default pattern
        //
        // You can override with something like:
        // spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");
    }
}

// Did we build with Entrypoint support built-in?
//
// If so, go ahead and register the logger initialization
// to run as the VERY FIRST thing in the plugin
// #if __has_include(<SkyrimScripting/Entrypoint.h>)
#include <SkyrimScripting/Entrypoint.h>

SKSEPlugin_Entrypoint_PreInit_HighPriority {
    SkyrimScripting::Logging::Internal::InitializeLogger();
    SKSE::log::info("INITIALIZED LOGGER");
    return true;
}

SKSEPlugin_Entrypoint {
    SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message* a_msg) {
        if (a_msg->type == SKSE::MessagingInterface::kDataLoaded) {
            if (auto* consoleLog = RE::ConsoleLog::GetSingleton()) {
                consoleLog->Print("Hello from SkyrimScripting.Logging ENTRYPOINT!");
            }
        }
    });
}
// #endif
