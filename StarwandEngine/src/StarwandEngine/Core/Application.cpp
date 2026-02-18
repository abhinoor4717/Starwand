#include "Core/Application.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "Core/Log.h"
#include "Graphics/Renderer.h"
#include "Events/WindowEvents.h"
#include <filesystem>
#include <iostream>

namespace Starwand {
    Application* Application::s_instance = nullptr;

    Application::Application(const std::string& title, uint32_t width, uint32_t height) {
        Log::Init();
        if (s_instance != nullptr) {
            SWE_FATAL("Instance of application exists!");
            exit(-1);
        }

        if (!glfwInit()) {
            SWE_FATAL("GLFW failed to initialize!");
            glfwTerminate();
            exit(-1);
        }

        m_window = Window::Create(title, width, height);
        m_window->SetEventCallback([this](Event& e) { this->OnEvent(e); });

        // TODO: Initialize glad and rendering logic elsewhere
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            SWE_FATAL("GLAD failed to initalize!");
            glfwTerminate();
            exit(-1);
        }

        Renderer::Init();

        SWE_INFO("Hi!");

        m_running = true;
        s_instance = this;
    }

    Application::~Application() {
        m_window.reset();
        glfwTerminate();
    }

    void Application::Run() {
        auto win = (GLFWwindow*)m_window->GetNativeWindow();
        while (m_running) {
            Renderer::SetClearColor(0.5f, 0.5f, 0.5f, 1.0f);
            Renderer::Clear();

            Renderer::DrawRect();

            m_window->Update();
        }
    }

    void Application::OnEvent(Event& e) {
        if (e.GetEventType() == EventType::WindowClosed) {
            m_running = false;
        }
        else if (e.GetEventType() == EventType::WindowResized) {
            auto winEvent = ConvertEvent<WindowResizedEvent>(e);
            glViewport(0, 0, winEvent->GetWidth(), winEvent->GetHeight());
        }
    }
}