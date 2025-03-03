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
            PrintToConsole(text.c_str());
            PrintToConsole("Data loaded event received!");
            PrintToConsole("One value: {}", 1);
            PrintToConsole("Two values: {}, {}", 1, 2);
            PrintToConsole("Three values: {}, {}, {}", 1, 2, 3);
            PrintToConsole("Four values: {}, {}, {}, {}", 1, 2, 3, 4);
            PrintToConsole("Five values: {}, {}, {}, {}, {}", 1, 2, 3, 4, 5);
            PrintToConsole("Six values: {}, {}, {}, {}, {}, {}", 1, 2, 3, 4, 5, 6);
            PrintToConsole("Seven values: {}, {}, {}, {}, {}, {}, {}", 1, 2, 3, 4, 5, 6, 7);
            PrintToConsole("Eight values: {}, {}, {}, {}, {}, {}, {}, {}", 1, 2, 3, 4, 5, 6, 7, 8);
            PrintToConsole(
                "Nine values: {}, {}, {}, {}, {}, {}, {}, {}, {}", 1, 2, 3, 4, 5, 6, 7, 8, 9
            );
            PrintToConsole(
                "Ten values: {}, {}, {}, {}, {}, {}, {}, {}, {}, {}", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
            );
        }
    });
}
