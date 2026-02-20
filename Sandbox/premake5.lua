project "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "%{wks.location}/obj/%{prj.name}/%{cfg.buildcfg}"

    files {
        "src/**.h",
        "src/**.cpp"
    }

    links {
        "StarwandEngine"
    }

    includedirs {
        "%{wks.location}/StarwandEngine/src",
        "%{wks.location}/StarwandEngine/src/StarwandEngine",
        "%{wks.location}/StarwandEngine/vendor/spdlog/include",
        "%{wks.location}/StarwandEngine/vendor/glm",
    }

    postbuildcommands {
        "{COPY} %{wks.location}/bin/StarwandEngine/%{cfg.buildcfg}/* %{cfg.targetdir}"
    }

    filter "system:windows"
        defines { "SW_PLATFORM_WINDOWS" }
    
    filter "action:vs*"
        buildoptions "/utf-8"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
    filter "configurations:Release"
        runtime "Release"
        optimize "On"
