#pragma once

#include "Core.h"
#include <raylib.h>
#include "Window.h"
#include "Events/Events.h"
#include "LayerStack.h"

namespace Starwand {

    enum class STARWAND_API ApplicationConfigFlags : uint32_t {
        NONE               = 0,
        VSYNC              = 1 << 0,
        WINDOW_MAXIMIZED   = 1 << 1,
        WINDOW_FULLSCREEN  = 1 << 2,
    };
    
    inline ApplicationConfigFlags operator|(ApplicationConfigFlags lhs, ApplicationConfigFlags rhs) {
        return static_cast<ApplicationConfigFlags>(
            static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs)
        );
    }

    inline ApplicationConfigFlags operator&(ApplicationConfigFlags lhs, ApplicationConfigFlags rhs) {
        return static_cast<ApplicationConfigFlags>(
            static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs)
        );
    }

    inline ApplicationConfigFlags& operator|=(ApplicationConfigFlags& lhs, ApplicationConfigFlags rhs) {
        lhs = lhs | rhs;
        return lhs;
    }

    inline bool HasFlag(ApplicationConfigFlags flags, ApplicationConfigFlags flag) {
        return (static_cast<uint32_t>(flags) & static_cast<uint32_t>(flag)) != 0;
    }

    struct ApplicationProps {
        std::string Title = "Starwand Application";
        int Width = 1080;
        int Height = 720;
        ApplicationConfigFlags flags = ApplicationConfigFlags::VSYNC;
    };


    class STARWAND_API Application {
    public:
        Application(ApplicationProps props = {});
        ~Application();

        void Run();
        void OnEvent(Event& e);

        inline int GetFPS() { return ::GetFPS(); }

        inline static Application& Get() { return *s_Instance; }
        inline LayerStack& GetLayerStack() { return *m_LayerStack; }
    
    private:
        bool m_Running;
        Window* m_Window;
        LayerStack* m_LayerStack;

        static Application* s_Instance;

    };
}