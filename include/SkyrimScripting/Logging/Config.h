#pragma once

#include <filesystem>

namespace SkyrimScripting::Logging::Config {
    // Check if logging is disabled
    const bool is_logging_disabled();

    // Enable or disable logging
    void set_logging_disabled(bool value);

    // Check if logging to the debug console is enabled
    const bool log_to_debug_console();

    // Enable or disable logging to the debug console
    void set_log_to_debug_console(bool value);

    // Get the full path of the log file
    const std::filesystem::path log_full_path();

    // Set the full path of the log file
    void set_log_full_path(const std::filesystem::path& value);

    // Get the name of the log file
    const std::filesystem::path log_file_name();

    // Set the name of the log file
    void set_log_file_name(const std::filesystem::path& value);

    // Get the path of the log folder
    const std::filesystem::path log_folder_path();

    // Set the path of the log folder
    void set_log_folder_path(const std::filesystem::path& value);
}
