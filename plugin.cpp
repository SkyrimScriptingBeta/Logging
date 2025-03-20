#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>
#include <SKSEPluginInfo.h>
#include <SkyrimScripting/Logging.h>

extern "C" __declspec(dllexport) bool SKSEPlugin_Load(const SKSE::LoadInterface* a_skse) {
    // This is AUTOMATIC nowadays in po3 (and possibly VR, need to verify)
    // SkyrimScripting::Logging::InitializeLogger("MyAwesomePlugin123");
    // SkyrimScripting::Logging::InitializeLogger(SKSEPluginInfo::GetPluginName());

    SKSE::Init(a_skse);
    SKSE::log::info("Hello! This my SKSE::log::info message!");
    SKSE::log::debug("Hello! This my SKSE::log::debug message!");
    SKSE::log::warn("Hello! This my SKSE::log::warn message!");
    return true;
}