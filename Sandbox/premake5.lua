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
        "%{wks.location}/StarwandEngine/StarwandEngine/src"
    }

    postbuildcommands {
        "{COPY} %{wks.location}/bin/StarwandEngine/%{cfg.buildcfg}/* %{cfg.targetdir}"
    }
