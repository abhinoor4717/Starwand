#include "swpch.h"

#include "Application.h"

#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"
#include "Events/WindowEvents.h"
#include "Utils/DeltaTime.h"

namespace Starwand {

    Application* Application::s_Instance = nullptr;

    Application::Application()
        : m_Running(false) {
            s_Instance = this;

            #ifndef SW_DEBUG
                SetConfigFlags(LOG_NONE);
            #endif

            m_Window = new Window(1080, 720);
            m_Running = true;
            // SetTargetFPS(240);
            Logger::Init();
    }

    Application::~Application() {
        delete m_Window;
    }

    void Application::Run() {
        auto& app = Get();

        while (m_Running) {
            DeltaTime dt = DeltaTime::FromSeconds(GetFrameTime());
            
            m_Window->PollEvents([&app](Event& e) { app.OnEvent(e); });

            BeginDrawing();
            ClearBackground(BLACK);
            DrawFPS(10, 10);
            EndDrawing();
        }
    }

    void Application::OnEvent(Event& e) {
        SW_CORE_INFO(e);
        if (e.GetEventType() == EventType::WindowClosed) {
            m_Running = false;
        }
        else if (e.GetEventType() == EventType::KeyReleased) {
            auto& kEvent = dynamic_cast<KeyReleasedEvent&>(e);
            if (kEvent.GetKeyCode() == KEY_V) {
                m_Window->ToggleVsync();
            }
        }
    }
}