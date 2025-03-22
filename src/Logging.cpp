#include <SKSE/SKSE.h>
#include <Windows.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

#include <format>

#include "SkyrimScripting/Logging/InitializeLogger.h"
#include "SkyrimScripting/Logging/SetLogLevel.h"

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

    void SetLogLevel(LogLevel level, bool alsoFlush) {
        auto default_logger = spdlog::default_logger();
        if (default_logger) {
            switch (level) {
                case LogLevel::Trace:
                    default_logger->set_level(spdlog::level::trace);
                    if (alsoFlush) spdlog::flush_on(spdlog::level::trace);
                    break;
                case LogLevel::Debug:
                    default_logger->set_level(spdlog::level::debug);
                    if (alsoFlush) spdlog::flush_on(spdlog::level::debug);
                    break;
                case LogLevel::Info:
                    default_logger->set_level(spdlog::level::info);
                    if (alsoFlush) spdlog::flush_on(spdlog::level::info);
                    break;
                case LogLevel::Warn:
                    default_logger->set_level(spdlog::level::warn);
                    if (alsoFlush) spdlog::flush_on(spdlog::level::warn);
                    break;
                case LogLevel::Error:
                    default_logger->set_level(spdlog::level::err);
                    if (alsoFlush) spdlog::flush_on(spdlog::level::err);
                    break;
                case LogLevel::Critical:
                    default_logger->set_level(spdlog::level::critical);
                    if (alsoFlush) spdlog::flush_on(spdlog::level::critical);
                    break;
                case LogLevel::Off:
                    default_logger->set_level(spdlog::level::off);
                    if (alsoFlush) spdlog::flush_on(spdlog::level::off);
                    break;
                default:
                    break;
            }
        }
    }
}
