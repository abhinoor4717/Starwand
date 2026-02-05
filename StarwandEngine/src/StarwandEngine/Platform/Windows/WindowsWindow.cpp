#include "WindowsWindow.h"

#include "Core/Log.h"

namespace Starwand {
    WindowsWindow::WindowsWindow(const std::string& title, uint32_t width, uint32_t height) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!m_glfwWindow) {
            SWE_FATAL("GLFW window failed to initialize!");
            exit(-1);
        }

        glfwMakeContextCurrent(m_glfwWindow);

    }
}