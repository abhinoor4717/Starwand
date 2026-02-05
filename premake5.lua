workspace "StarwandTester"
    configurations {
        "Debug",
        "Release"
    }

    include "StarwandEngine/vendor/glfw"
    include "StarwandEngine/vendor/glad"
    include "StarwandEngine/vendor/spdlog"
    include "StarwandEngine"
    include "Sandbox"