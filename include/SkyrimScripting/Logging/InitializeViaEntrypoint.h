#pragma once

#include <SkyrimScripting/Entrypoint/Macros/_SKSEPlugin_PreInit_HighPriority_.h>

#include "Logging.h"

_SKSEPlugin_PreInit_HighPriority_(const SKSE::LoadInterface* skse) {  // NOLINT
    SkyrimScripting::Logging::InitializeLogger();
    return true;
}
