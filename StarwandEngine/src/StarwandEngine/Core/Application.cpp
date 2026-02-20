#include "Core/Application.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "Core/Log.h"
#include "Graphics/Renderer.h"
#include "Graphics/RenderCommand.h"
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

        Renderer::Init();

        m_running = true;
        s_instance = this;
    }

    Application::~Application() {
        m_window.reset();
        glfwTerminate();
    }

    void Application::Run() {
        while (m_running) {
            Renderer::SetClearColor(0.5f, 0.5f, 0.5f, 1.0f);
            Renderer::Clear();

            Update();
            Render();

            m_window->Update();
        }
    }

    void Application::OnEvent(Event& e) {
        if (e.GetEventType() == EventType::WindowClosed) {
            m_running = false;
        }
        else if (e.GetEventType() == EventType::WindowResized) {
            auto winEvent = ConvertEvent<WindowResizedEvent>(e);
            RenderCommand::SetViewport(0, 0, winEvent->GetWidth(), winEvent->GetHeight());
        }
    }
}