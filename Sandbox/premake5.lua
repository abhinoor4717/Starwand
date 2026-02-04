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
        "%{wks.location}/StarwandEngine/src"
    }

    filter "system:windows"
        defines { "SW_PLATFORM_WINDOWS" }

    postbuildcommands {
        "{COPY} %{wks.location}/bin/StarwandEngine/%{cfg.buildcfg}/* %{cfg.targetdir}"
    }
