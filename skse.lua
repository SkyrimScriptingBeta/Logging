mods_folders = os.getenv("SKYRIM_MODS_FOLDERS")

if mods_folders then
    mod_info.mods_folders = mods_folders
else
    print("SKYRIM_MODS_FOLDERS environment variable not set")
end

target("_SksePlugin-" .. skyrim_version:upper())
    set_basename(mod_info.name .. "-" .. skyrim_version:upper())
    add_files("*.cpp")
    add_rules("@skyrim-commonlib-" .. skyrim_version .. "/plugin", {
        mod_name = mod_info.name .. " (" .. skyrim_version:upper() .. ")",
        mods_folders = mod_info.mods_folders or "",
        mod_files = mod_info.mod_files,
        name = mod_info.name,
        version = mod_info.version,
        author = mod_info.author,
        email = mod_info.email
    })
    -- add_deps(library_name)
