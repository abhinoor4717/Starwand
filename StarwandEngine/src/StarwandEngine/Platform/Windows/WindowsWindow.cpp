#include "Platform/Windows/WindowsWindow.h"

#include "Core/Log.h"
#include "Events/WindowEvents.h"
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"
#include "Core/Input.h"

namespace Starwand {
    WindowsWindow::WindowsWindow(const std::string& title, uint32_t width, uint32_t height) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if (!m_glfwWindow) {
            SWE_FATAL("GLFW window failed to initialize!");
            exit(-1);
        }
        glfwMakeContextCurrent(m_glfwWindow);
        m_windowData.Title = title;
        m_windowData.Width = width;
        m_windowData.Height = height;
        glfwSetWindowUserPointer(m_glfwWindow, &m_windowData);

        // Window event handlers
        glfwSetWindowCloseCallback(m_glfwWindow, [](GLFWwindow* win) {
            WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
            WindowClosedEvent e;
            data->EventCallback(e);
        });
        glfwSetWindowSizeCallback(m_glfwWindow, [](GLFWwindow* win, int w, int h) {
            WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
            data->Width = w;
            data->Height = h;
            WindowResizedEvent e(w, h);
            data->EventCallback(e);
        });
        glfwSetWindowMaximizeCallback(m_glfwWindow, [](GLFWwindow* win, int maximized) {
            WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
            if (maximized == GLFW_TRUE) {
                WindowMaximizedEvent e;
                data->EventCallback(e);
            }
            else {
                WindowRestoredEvent e;
                data->EventCallback(e);
            }
        });
        glfwSetWindowIconifyCallback(m_glfwWindow, [](GLFWwindow* win, int iconified) {
            WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
            if (iconified == GLFW_TRUE) {
                WindowMinimizedEvent e;
                data->EventCallback(e);
            }
            else {
                WindowRestoredEvent e;
                data->EventCallback(e);
            }
        });
        glfwSetWindowFocusCallback(m_glfwWindow, [](GLFWwindow* win, int focused) {
            WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
            if (focused == GLFW_TRUE) {
                WindowFocusGainedEvent e;
                data->EventCallback(e);
            }
            else {
                WindowFocusLostEvent e;
                data->EventCallback(e);
            }
        });

        // Key event handlers
        glfwSetKeyCallback(m_glfwWindow, [](GLFWwindow* win, int key, int scancode, int action, int mods) {
            WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
            if (action == GLFW_PRESS || action == GLFW_REPEAT) {
                KeyDownEvent e(static_cast<Key>(key));
                data->EventCallback(e);
            }
            else if (action == GLFW_RELEASE) {
                KeyUpEvent e(static_cast<Key>(key));
                data->EventCallback(e);
            }
        });

        // Mouse event handlers
        glfwSetMouseButtonCallback(m_glfwWindow, [](GLFWwindow* win, int button, int action, int mods) {
            WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
            if (action == GLFW_PRESS) {
                MouseButtonDownEvent e(Input::GetMousePosition(), static_cast<MouseButton>(button));
                data->EventCallback(e);
            }
            else if (action == GLFW_RELEASE) {
                MouseButtonUpEvent e(Input::GetMousePosition(), static_cast<MouseButton>(button));
                data->EventCallback(e);
            }
        });
        glfwSetCursorPosCallback(m_glfwWindow, [](GLFWwindow* win, double x, double y) {
            WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
            MouseMovedEvent e({x, y});
            data->EventCallback(e);
        });
        glfwSetScrollCallback(m_glfwWindow, [](GLFWwindow* win, double x, double y) {
            WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
            MouseWheelEvent e({x, y});
            data->EventCallback(e);
        });
    }

    WindowsWindow::~WindowsWindow() {
        glfwDestroyWindow(m_glfwWindow);
    }

    void WindowsWindow::Update() {
        // TODO: Check if current context is this one before updating
        glfwSwapBuffers(m_glfwWindow);
        glfwPollEvents();
    }

    uint32_t WindowsWindow::GetWidth() const { return m_windowData.Width; }
    uint32_t WindowsWindow::GetHeight() const { return m_windowData.Height; }
    std::string WindowsWindow::GetTitle() const { return m_windowData.Title; }
    void* WindowsWindow::GetNativeWindow() const { return (void*)m_glfwWindow; }
    void WindowsWindow::SetEventCallback(std::function<void(Event&)> callback) {
        m_windowData.EventCallback = callback;
    }
}