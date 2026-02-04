workspace "StarwandTester"
    configurations {
        "Debug",
        "Release"
    }

    include "StarwandEngine/vendor/glfw"
    include "StarwandEngine/vendor/glad"
    include "StarwandEngine"
    include "Sandbox"