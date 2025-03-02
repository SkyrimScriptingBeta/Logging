#include "SkyrimScripting/Logging/Config.h"

namespace SkyrimScripting::Logging::Config {
    static bool                  _logging_disabled     = false;
    static bool                  _log_to_debug_console = false;
    static std::filesystem::path _log_full_path;
    static std::filesystem::path _log_file_name;
    static std::filesystem::path _log_folder_path;

    const bool is_logging_disabled() { return _logging_disabled; }
    void       set_logging_disabled(bool value) { _logging_disabled = value; }

    const bool log_to_debug_console() { return _log_to_debug_console; }
    void       set_log_to_debug_console(bool value) { _log_to_debug_console = value; }

    const std::filesystem::path log_full_path() { return _log_full_path; }
    void set_log_full_path(const std::filesystem::path& value) { _log_full_path = value; }

    const std::filesystem::path log_file_name() { return _log_file_name; }
    void set_log_file_name(const std::filesystem::path& value) { _log_file_name = value; }

    const std::filesystem::path log_folder_path() { return _log_folder_path; }
    void set_log_folder_path(const std::filesystem::path& value) { _log_folder_path = value; }
}
