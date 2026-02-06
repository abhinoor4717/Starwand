#pragma once
#include "Core/Core.h"

#include "Core/Window.h"
#include "Events/Events.h"

namespace Starwand {
    class SW_API Application {
    public:
        Application(const std::string& title, uint32_t width, uint32_t height);
        ~Application();

        void Run();
        void inline Update() {};
        void inline Render() {};
        void OnEvent(Event& e);

        static inline Application& GetInstance() { return *s_instance; }
        inline Window& GetWindow() { return *m_window; } 
    private:
        std::shared_ptr<Window> m_window;
        bool m_running;
        static Application* s_instance;
    };
}