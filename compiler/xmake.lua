set_languages("c++23")
set_toolchains("clang-cl")

add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

target("wea-lib")
    set_kind("static")
    add_includedirs("include/")
    add_headerfiles("include/**.hpp")
    add_files("src/**.cpp")

-- Binary is not done yet
-- target("wea")
--     set_kind("binary")
--     add_includedirs("include/")
--     add_headerfiles("include/Lettuce/**.hpp")
--     add_files("src/Core/**.cpp")