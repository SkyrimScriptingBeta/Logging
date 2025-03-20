#include "SkyrimScripting/Logging.h"

#include <SKSE/SKSE.h>
#include <Windows.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

#include <format>

namespace SkyrimScripting::Logging {

    void InitializeLogger(std::string_view pluginName) {
        // Get the logs folder
        auto logsFolder = SKSE::log::log_directory();
        if (!logsFolder) {
            SKSE::stl::report_and_fail("SKSE log_directory not provided, logs disabled.");
            return;
        }

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
