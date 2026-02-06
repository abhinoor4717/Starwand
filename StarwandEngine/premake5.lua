project "StarwandEngine"
    kind "SharedLib"
    language "C++"
    
    targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "%{wks.location}/obj/%{prj.name}/%{cfg.buildcfg}"

    files {
        "src/**.h",
        "src/**.cpp"
    }

    links {
        "glad",
        "glfw",
        "gdi32",
        "spdlog"
    }

    includedirs {
        "vendor/glfw/include",
        "vendor/glad/include",
        "vendor/spdlog/include",
        "vendor/glm",
        "src/StarwandEngine"
    }

    defines {
        "SW_BUILD_DLL"
    }

    filter "action:vs**"
        buildoptions "/utf-8"

    filter "system:windows"
        systemversion "latest"
        defines "SW_PLATFORM_WINDOWS"
        links "winmm"

    filter "configurations:Debug"
        runtime "Debug"
        defines {"SW_DEBUG"}
        symbols "On"
    filter "configurations:Release"
        runtime "Release"
        defines {"SW_RELEASE", "SW_NDEBUG"}
        optimize "On"