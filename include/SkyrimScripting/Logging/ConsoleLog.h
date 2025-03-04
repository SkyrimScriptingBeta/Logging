#pragma once

#include <RE/Skyrim.h>

#include <format>  // IWYU pragma: export

#define PrintToConsole(...)                                                                                                                     \
    __SkyrimScripting_Logging_ConsoleLog_CAT(__SkyrimScripting_Logging_ConsoleLog_, __SkyrimScripting_Logging_ConsoleLog_PP_NARG(__VA_ARGS__))( \
        __VA_ARGS__                                                                                                                             \
    )

// Macro madness to support variadic arguments (with MSVC support)

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

#define __SkyrimScripting_Logging_ConsoleLog_1(arg)                          \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) { \
        auto txt = std::format("{}", arg);                                   \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_2(fmt, arg1)                    \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) { \
        auto txt = std::format(fmt, arg1);                                   \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_3(fmt, arg1, arg2)              \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) { \
        auto txt = std::format(fmt, arg1, arg2);                             \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_4(fmt, arg1, arg2, arg3)        \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) { \
        auto txt = std::format(fmt, arg1, arg2, arg3);                       \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_5(fmt, arg1, arg2, arg3, arg4)  \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) { \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4);                 \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                      \
    }

#define __SkyrimScripting_Logging_ConsoleLog_6(fmt, arg1, arg2, arg3, arg4, arg5) \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) {      \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5);                \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                           \
    }

#define __SkyrimScripting_Logging_ConsoleLog_7(fmt, arg1, arg2, arg3, arg4, arg5, arg6) \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) {            \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6);                \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                                 \
    }

#define __SkyrimScripting_Logging_ConsoleLog_8(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) {                  \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7);                \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                                       \
    }

#define __SkyrimScripting_Logging_ConsoleLog_9(                                      \
    fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8                              \
)                                                                                    \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) {         \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                              \
    }

#define __SkyrimScripting_Logging_ConsoleLog_10(                                           \
    fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9                              \
)                                                                                          \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) {               \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                                    \
    }

#define __SkyrimScripting_Logging_ConsoleLog_11(                                                  \
    fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10                              \
)                                                                                                 \
    if (auto* _skyrimScriptingConsoleLog = RE::ConsoleLog::GetSingleton()) {                      \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10); \
        _skyrimScriptingConsoleLog->Print(txt.c_str());                                           \
    }
