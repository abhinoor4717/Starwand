#include "Application.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "Log.h"

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

        // TODO: Initialize glad and rendering logic elsewhere
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            SWE_FATAL("GLAD failed to initalize!");
            glfwTerminate();
            exit(-1);
        }

        s_instance = this;
    }

    Application::~Application() {
        m_window.reset();
        glfwTerminate();
    }

    void Application::Run() {
        auto win = (GLFWwindow*)m_window->GetNativeWindow();
        while (!glfwWindowShouldClose(win)) {
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(win);
            glfwPollEvents();
        }
    }
}