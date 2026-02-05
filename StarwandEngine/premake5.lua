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
        "gdi32"
    }

    includedirs {
        "vendor/glfw/include",
        "vendor/glad/include",
        "vendor/glm",
        "src/**"
    }

    defines {
        "SW_BUILD_DLL"
    }

    filter "system:windows"
        defines "SW_PLATFORM_WINDOWS"
        links "winmm"

    filter "configurations:Debug"
        defines {"SW_DEBUG"}
        symbols "On"
    filter "configurations:Release"
        defines {"SW_RELEASE", "SW_NDEBUG"}
        optimize "On"