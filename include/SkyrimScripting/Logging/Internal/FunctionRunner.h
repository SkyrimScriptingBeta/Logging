#pragma once

#include <functional>

namespace SkyrimScripting::Logging::Internal {

    /*
     * Lazy way to run arbitrary function on startup by providing a function.
     * Defined by macros or inline functions.
     */
    struct FunctionRunner {
        FunctionRunner(std::function<void()> fn);
    };
}

#define __SKYRIM_SCRIPTING_LOGGING_CONCAT0(x, y) x##y
#define __SKYRIM_SCRIPTING_LOGGING_CONCAT(x, y) __SKYRIM_SCRIPTING_LOGGING_CONCAT0(x, y)

// Create a "FunctionRunner" which takes a std::function which is run immediately at runtime
#define __SKYRIM_SCRIPTING_LOGGING_FUNCTIONRUNNER(count)                                  \
    SkyrimScripting::Logging::Internal::FunctionRunner __SKYRIM_SCRIPTING_LOGGING_CONCAT( \
        __skyrimScriptingLoggingFunctionRunner, count                                     \
    )

#define __NEW_SKYRIM_SCRIPTING_LOGGING_FUNCTIONRUNNER \
    __SKYRIM_SCRIPTING_LOGGING_FUNCTIONRUNNER(__COUNTER__)
