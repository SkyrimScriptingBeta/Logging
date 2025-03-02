#pragma once

#include "Config.h"                   // IWYU pragma: export
#include "Internal/FunctionRunner.h"  // IWYU pragma: export

// Override the full path of the log file for this plugin
#define Logging_SetLogFullPath(fullPath)                                        \
    __NEW_SKYRIM_SCRIPTING_LOGGING_FUNCTIONRUNNER {                             \
        []() { SkyrimScripting::Logging::Config::set_log_full_path(fullPath); } \
    }

// Override the filename of the log file for this plugin
#define Logging_SetLogFileName(filename)                                        \
    __NEW_SKYRIM_SCRIPTING_LOGGING_FUNCTIONRUNNER {                             \
        []() { SkyrimScripting::Logging::Config::set_log_file_name(filename); } \
    }

// Override the folder path of the log file for this plugin
#define Logging_SetLogFolder(folderPath)                                            \
    __NEW_SKYRIM_SCRIPTING_LOGGING_FUNCTIONRUNNER {                                 \
        []() { SkyrimScripting::Logging::Config::set_log_folder_path(folderPath); } \
    }

// Enables logging to debugger console when debugger is attached (default: false)
#define Logging_DisableLogToDebugConsole                                           \
    __NEW_SKYRIM_SCRIPTING_LOGGING_FUNCTIONRUNNER {                                \
        []() { SkyrimScripting::Logging::Config::set_log_to_debug_console(true); } \
    }

// Disables logging
#define Logging_Disable                                                        \
    __NEW_SKYRIM_SCRIPTING_LOGGING_FUNCTIONRUNNER {                            \
        []() { SkyrimScripting::Logging::Config::set_logging_disabled(true); } \
    }
