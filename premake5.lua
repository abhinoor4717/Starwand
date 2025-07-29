workspace "Starwand"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }
    
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Starwand/vendor/spdlog"
include "Starwand/vendor/raylib"

project "Starwand"
    location "Starwand"
    kind "SharedLib"
    language "C++"
    cppdialect "C++23"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "swpch.h"
	pchsource "Starwand/src/swpch.cpp"

    files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/src/**",
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/raylib/src",        
        "%{prj.name}/vendor/raylib/src/external"
    }


    links {
        "raylib",
        "spdlog"
    }

    defines {
        "SW_BUILD_DLL"
    }
    
    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SW_PLATFORM_WINDOWS"
        }

        links {
            "winmm"
        }

    filter "action:vs*"
        buildoptions {
            "/utf-8"
        }

    filter "system:linux"
        defines {
            "SW_PLATFORM_LINUX"
        }
    filter "system:mac"
        defines {
            "SW_PLATFORM_MAC"
        }
    
    filter "configurations:Debug"
        defines "SW_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "SW_RELEASE"

    postbuildcommands {
		("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
		("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
	}

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Starwand/vendor/spdlog/include",
		"Starwand/src/**",
		"Starwand/src/",
        "Starwand/vendor/raylib/src",
        "Starwand/vendor/raylib/src/external",
	}

	links {
		"Starwand"
	}

    filter "system:windows"
        staticruntime "On"
		systemversion "latest"
        
        defines {
            "SW_PLATFORM_WINDOWS"
        }

    filter "action:vs*"
        buildoptions {
            "/utf-8"
        }

    filter "system:linux"
        defines {
            "SW_PLATFORM_LINUX"
        }
    filter "system:mac"
        defines {
            "SW_PLATFORM_MAC"
        }

    filter "configurations:Debug"
        defines "SW_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "SW_RELEASE"