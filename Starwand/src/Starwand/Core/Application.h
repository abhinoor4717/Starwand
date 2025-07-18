#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Events.h"

namespace Starwand {
    class STARWAND_API Application {
    public:
        Application();
        ~Application();

        void Run();
        void OnEvent(Event& e);

        inline static Application& Get() { return *s_Instance; }
    
    private:
        bool m_Running;
        Window* m_Window;

        static Application* s_Instance;
    };
}