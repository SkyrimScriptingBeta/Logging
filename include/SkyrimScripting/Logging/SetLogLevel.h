#pragma once

#include <cstdint>

namespace SkyrimScripting::Logging {

    enum class LogLevel : uint8_t {
        Trace    = 0,
        Debug    = 1,
        Info     = 2,
        Warn     = 3,
        Error    = 4,
        Critical = 5,
        Off      = 6
    };

    void SetLogLevel(LogLevel level, bool alsoFlush = false);
}
