#include "swpch.h"

#include "Application.h"

#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"
#include "Events/WindowEvents.h"
#include "Utils/DeltaTime.h"
#include "Renderer/Renderer.h"

namespace Starwand {

    Application* Application::s_Instance = nullptr;

    Application::Application(ApplicationProps props)
        : m_Running(false) {
            Logger::Init();
            s_Instance = this;

            #ifdef SW_RELEASE
                ::SetTraceLogLevel(::LOG_NONE);
            #endif
            #ifdef SW_DEBUG
                ::SetTraceLogLevel(::LOG_ALL);
            #endif

            m_Window = new Window(props.Width, props.Height, props.Title.c_str());
            if (HasFlag(props.flags, ApplicationConfigFlags::VSYNC)) {
                m_Window->SetVsync(true);
            }
            if (HasFlag(props.flags, ApplicationConfigFlags::WINDOW_FULLSCREEN)) {
                m_Window->SetFullscreen(true);
            }
            if (HasFlag(props.flags, ApplicationConfigFlags::WINDOW_MAXIMIZED)) {
                m_Window->SetMaximized(true);
            }

            m_LayerStack = new LayerStack();
            m_Running = true;
    }

    Application::~Application() {
        delete m_Window;
    }

    void Application::Run() {
        auto& app = Get();

        while (m_Running) {
            DeltaTime dt = DeltaTime::FromSeconds(::GetFrameTime());
            
            m_Window->PollEvents([&app](Event& e) { app.OnEvent(e); });

            ::BeginDrawing();

            m_LayerStack->OnUpdate(dt);

            ::EndDrawing();
        }
    }

    void Application::OnEvent(Event& e) {
        SW_CORE_TRACE(e);
        if (e.GetEventType() == EventType::WindowClosed) {
            m_Running = false;
        }

        if (!e.Handled)
            m_LayerStack->OnEvent(e);
    }
}