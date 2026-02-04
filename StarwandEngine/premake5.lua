project "StarwandEngine"
    kind "SharedLib"
    language "C++"
    
    targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "%{wks.location}/obj/%{prj.name}/%{cfg.buildcfg}"

    files {
        "StarwandEngine/src/**.h",
        "StarwandEngine/src/**.cpp"
    }

    filter "configurations:Debug"
        defines {"SW_DEBUG"}
        symbols "On"
    filter "configurations:Release"
        defines {"SW_RELEASE", "SW_NDEBUG"}
        optimize "On"