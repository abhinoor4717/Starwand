#pragma once
#include "Core/Window.h"
#include <glfw/glfw3.h>
#include <functional>
#include "Events/Events.h"

namespace Starwand {
    class WindowsWindow : public Window {
    public:
        WindowsWindow(const std::string& title, uint32_t width, uint32_t height);
        ~WindowsWindow();

        uint32_t GetWidth() const override;
        uint32_t GetHeight() const override;
        std::string GetTitle() const override;
        void* GetNativeWindow() const override;

        void Update() override;

        void SetEventCallback(EventCallbackFn callback);

    private:
        uint32_t m_width, m_height;
        std::string m_title;
        GLFWwindow* m_glfwWindow;
        WindowData m_windowData;
    };
}