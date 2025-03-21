#pragma once

#include <format>  // IWYU pragma: export

#include "ConsoleLog.h"  // IWYU pragma: export

#define PrintToConsole(...)                                                                                                                     \
    __SkyrimScripting_Logging_ConsoleLog_CAT(__SkyrimScripting_Logging_ConsoleLog_, __SkyrimScripting_Logging_ConsoleLog_PP_NARG(__VA_ARGS__))( \
        __VA_ARGS__                                                                                                                             \
    )

// Macro madness to support variadic arguments (with MSVC support)

// Requires CXX flag /Zc:preprocessor

#define __SkyrimScripting_Logging_ConsoleLog_CAT_IMPL(a, b) a##b
#define __SkyrimScripting_Logging_ConsoleLog_CAT(a, b) \
    __SkyrimScripting_Logging_ConsoleLog_CAT_IMPL(a, b)

#define __SkyrimScripting_Logging_ConsoleLog_PP_RSEQ_N() 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#define __SkyrimScripting_Logging_ConsoleLog_PP_ARG_N(           \
    _dummy, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, N, ... \
)                                                                \
    N
#define __SkyrimScripting_Logging_ConsoleLog_PP_NARG_(...) \
    __SkyrimScripting_Logging_ConsoleLog_PP_ARG_N(__VA_ARGS__)
#define __SkyrimScripting_Logging_ConsoleLog_PP_NARG(...)                    \
    __SkyrimScripting_Logging_ConsoleLog_PP_NARG_(                           \
        dummy, __VA_ARGS__, __SkyrimScripting_Logging_ConsoleLog_PP_RSEQ_N() \
    )

#define __SkyrimScripting_Logging_ConsoleLog_1(arg)                                             \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ = std::format("{}", arg);       \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_2(fmt, arg1)                                       \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ = std::format(fmt, arg1);       \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_3(fmt, arg1, arg2)                                 \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ = std::format(fmt, arg1, arg2); \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_4(fmt, arg1, arg2, arg3)                           \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ =                               \
            std::format(fmt, arg1, arg2, arg3);                                                 \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_5(fmt, arg1, arg2, arg3, arg4)                     \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ =                               \
            std::format(fmt, arg1, arg2, arg3, arg4);                                           \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_6(fmt, arg1, arg2, arg3, arg4, arg5)               \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ =                               \
            std::format(fmt, arg1, arg2, arg3, arg4, arg5);                                     \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_7(fmt, arg1, arg2, arg3, arg4, arg5, arg6)         \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ =                               \
            std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6);                               \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_8(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)   \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ =                               \
            std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7);                         \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_9(                                                 \
    fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8                                         \
)                                                                                               \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ =                               \
            std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);                   \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_10(                                                \
    fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9                                   \
)                                                                                               \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ =                               \
            std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);             \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_11(                                                \
    fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10                            \
)                                                                                               \
    if (auto* __skyrimScripting_PrintToConsole_ConsoleLog__ = RE::ConsoleLog::GetSingleton()) { \
        auto __skyrimScripting_PrintToConsole_ConsoleLog_Text__ =                               \
            std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);      \
        __skyrimScripting_PrintToConsole_ConsoleLog__->Print(                                   \
            __skyrimScripting_PrintToConsole_ConsoleLog_Text__.c_str()                          \
        );                                                                                      \
    }
