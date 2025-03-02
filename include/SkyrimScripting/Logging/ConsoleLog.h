#pragma once

#include <RE/Skyrim.h>

#include <format>

// 1) Reverse sequence for up to 11 user args
#define PP_RSEQ_N() 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

// 2) We'll define PP_ARG_N with 12 placeholders:
//    (1 dummy + up to 11 real user arguments).  The last param is N.
#define PP_ARG_N(_dummy, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, N, ...) N
#define PP_NARG_(...) PP_ARG_N(__VA_ARGS__)
#define PP_NARG(...) PP_NARG_(dummy, __VA_ARGS__, PP_RSEQ_N())

#define CAT_IMPL(a, b) a##b
#define CAT(a, b) CAT_IMPL(a, b)

// 3) The main macro.
//    If you call ConsoleLog(), that expands to ConsoleLog_0(dummy).
//    If you call ConsoleLog("foo", 123), that expands to
//      => PP_NARG("foo",123) => 2
//      => ConsoleLog_2(dummy,"foo",123).
#define ConsoleLog(...) CAT(ConsoleLog_, PP_NARG(__VA_ARGS__))(__VA_ARGS__)

// 4) Implementation macros for 0..11 arguments (note the _dummy param):
#define ConsoleLog_0(_dummy)                             \
    if (auto* c = RE::ConsoleLog::GetSingleton()) {      \
        c->Print("ConsoleLog called with no arguments"); \
    }

#define ConsoleLog_1(_dummy, arg)                   \
    if (auto* c = RE::ConsoleLog::GetSingleton()) { \
        auto txt = std::format("ONE ARG {}", arg);  \
        c->Print(txt.c_str());                      \
    }

#define ConsoleLog_2(_dummy, fmt, arg1)             \
    if (auto* c = RE::ConsoleLog::GetSingleton()) { \
        auto txt = std::format(fmt, arg1);          \
        c->Print(txt.c_str());                      \
    }

#define ConsoleLog_3(fmt, arg1, arg2)               \
    if (auto* c = RE::ConsoleLog::GetSingleton()) { \
        auto txt = std::format(fmt, arg1, arg2);    \
        c->Print(txt.c_str());                      \
    }

#define ConsoleLog_4(fmt, arg1, arg2, arg3)            \
    if (auto* c = RE::ConsoleLog::GetSingleton()) {    \
        auto txt = std::format(fmt, arg1, arg2, arg3); \
        c->Print(txt.c_str());                         \
    }

#define ConsoleLog_5(fmt, arg1, arg2, arg3, arg4)            \
    if (auto* c = RE::ConsoleLog::GetSingleton()) {          \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4); \
        c->Print(txt.c_str());                               \
    }

#define ConsoleLog_6(fmt, arg1, arg2, arg3, arg4, arg5)            \
    if (auto* c = RE::ConsoleLog::GetSingleton()) {                \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5); \
        c->Print(txt.c_str());                                     \
    }

#define ConsoleLog_7(fmt, arg1, arg2, arg3, arg4, arg5, arg6)            \
    if (auto* c = RE::ConsoleLog::GetSingleton()) {                      \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6); \
        c->Print(txt.c_str());                                           \
    }

#define ConsoleLog_8(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)            \
    if (auto* c = RE::ConsoleLog::GetSingleton()) {                            \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7); \
        c->Print(txt.c_str());                                                 \
    }

#define ConsoleLog_9(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)            \
    if (auto* c = RE::ConsoleLog::GetSingleton()) {                                  \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); \
        c->Print(txt.c_str());                                                       \
    }

#define ConsoleLog_10(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)           \
    if (auto* c = RE::ConsoleLog::GetSingleton()) {                                        \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); \
        c->Print(txt.c_str());                                                             \
    }

#define ConsoleLog_11(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)           \
    if (auto* c = RE::ConsoleLog::GetSingleton()) {                                               \
        auto txt = std::format(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10); \
        c->Print(txt.c_str());                                                                    \
    }
