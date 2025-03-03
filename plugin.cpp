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
            ConsoleLog(text.c_str());
            ConsoleLog("Data loaded event received!");
            ConsoleLog("One value: {}", 1);
            ConsoleLog("Two values: {}, {}", 1, 2);
            ConsoleLog("Three values: {}, {}, {}", 1, 2, 3);
            ConsoleLog("Four values: {}, {}, {}, {}", 1, 2, 3, 4);
            ConsoleLog("Five values: {}, {}, {}, {}, {}", 1, 2, 3, 4, 5);
            ConsoleLog("Six values: {}, {}, {}, {}, {}, {}", 1, 2, 3, 4, 5, 6);
            ConsoleLog("Seven values: {}, {}, {}, {}, {}, {}, {}", 1, 2, 3, 4, 5, 6, 7);
            ConsoleLog("Eight values: {}, {}, {}, {}, {}, {}, {}, {}", 1, 2, 3, 4, 5, 6, 7, 8);
            ConsoleLog(
                "Nine values: {}, {}, {}, {}, {}, {}, {}, {}, {}", 1, 2, 3, 4, 5, 6, 7, 8, 9
            );
            ConsoleLog(
                "Ten values: {}, {}, {}, {}, {}, {}, {}, {}, {}, {}", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
            );
        }
    });
}
