#pragma once

#include <filesystem>

namespace SkyrimScripting::Logging {
    const std::filesystem::path skse_log_folder();
    void                        InitializeLogger();
}
