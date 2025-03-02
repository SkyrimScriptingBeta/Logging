#include "SkyrimScripting/Logging/Internal/FunctionRunner.h"

namespace SkyrimScripting::Logging::Internal {
    FunctionRunner::FunctionRunner(std::function<void()> fn) { fn(); }
}
