#pragma once

#include <RE/Skyrim.h>

#define ConsoleLog(c_str)                                                        \
    if (auto* __skyrimScripting_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        __skyrimScripting_ConsoleLog__->Print(c_str);                            \
    }
