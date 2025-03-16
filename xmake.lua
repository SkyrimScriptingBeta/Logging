add_rules("mode.debug", "mode.release", "mode.releasedbg")

set_languages("c++23")

option("commonlib")
    set_default("skyrim-commonlib-ae")
option_end()

option("build_example")
    set_default(true)
option_end()

option("use_skyrimscripting_entrypoint")
    set_default(true)
option_end()

library_name = "SkyrimScripting.Logging"

if has_config("build_example") then
    add_repositories("SkyrimScripting https://github.com/SkyrimScripting/Packages.git")
    add_repositories("SkyrimScriptingBeta https://github.com/SkyrimScriptingBeta/Packages.git")
    add_repositories("MrowrLib https://github.com/MrowrLib/Packages.git")
end

-- Example SKSE plugin using the static library
mod_info = {
    name = "Test plugin for " .. library_name,
    version = "0.0.1",
    author = "Mrowr Purr",
    email = "mrowr.purr@gmail.com"
}

-- Available versions: ae, se, ng, vr
skyrim_version = "ae"

add_requires(get_config("commonlib"))
add_requires("skse_plugin_info")

if has_config("use_skyrimscripting_entrypoint") then
    add_requires("SkyrimScripting.Entrypoint", { configs = { commonlib = get_config("commonlib") }})
end

-- if has_config("build_example") then
--     add_requires("skyrim-commonlib-" .. skyrim_version)
--     add_requires("SkyrimScripting.Entrypoint", { configs = { commonlib = "skyrim-commonlib-" .. skyrim_version }})
-- end

-- if has_config("commonlib") then
-- target(library_name)
--     set_kind("static")
--     add_files("src/*.cpp")
--     add_packages(get_config("commonlib"), { public = true })
--     add_packages("skse_plugin_info", { public = true })
--     add_packages("SkyrimScripting.Entrypoint", { public = true })
--     -- if has_config("use_skyrimscripting_entrypoint") then
--     --     add_packages("SkyrimScripting.Entrypoint", { public = true })
--     -- end
-- target_end()
-- end

if has_config("build_example") then
    includes("skse.lua")
end
