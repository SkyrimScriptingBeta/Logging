#include <SkyrimScripting/Entrypoint.h>
#include <SkyrimScripting/Logging.h>
#include <_Log_.h>

#include <format>

Logging_SetLogFileName("MyCustomFileName.log");
Logging_SetLogFolder("D:/temp/");

_SKSEPlugin_Init_ {
    _Log_("Hello from SkyrimScripting Logger example plugin!");

    SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message* msg) {
        if (msg->type == SKSE::MessagingInterface::kDataLoaded) {
            auto text = std::format("Hello {}", 123);
            // ConsoleLog(text.c_str());
            // ConsoleLog("Data loaded event received!");

            // Directly test std::format
            if (auto* consoleLog = RE::ConsoleLog::GetSingleton()) {
                auto _theConsoleLogText =
                    std::format("test test new test TEST My favorite number is: {}", 22);
                consoleLog->Print(_theConsoleLogText.c_str());
            }

            ConsoleLog("CHANGED HERE HERE HERE I also like the numbers: {} and {}", 69, 420);
        }
    });
}
