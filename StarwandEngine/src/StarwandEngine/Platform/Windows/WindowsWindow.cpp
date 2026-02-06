#include "WindowsWindow.h"

#include "Core/Log.h"

namespace Starwand {
    WindowsWindow::WindowsWindow(const std::string& title, uint32_t width, uint32_t height)
        : m_title(title), m_width(width), m_height(height) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if (!m_glfwWindow) {
            SWE_FATAL("GLFW window failed to initialize!");
            exit(-1);
        }
        glfwMakeContextCurrent(m_glfwWindow);

    }

    WindowsWindow::~WindowsWindow() {
        glfwDestroyWindow(m_glfwWindow);
    }

    uint32_t WindowsWindow::GetWidth() const { return m_width; }
    uint32_t WindowsWindow::GetHeight() const { return m_height; }
    std::string WindowsWindow::GetTitle() const { return m_title; }
    void* WindowsWindow::GetNativeWindow() const { return (void*)m_glfwWindow; }
}