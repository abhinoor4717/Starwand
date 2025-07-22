#pragma once

#include "Core.h"
#include <functional>
#include "Events/Events.h"

namespace Starwand {
    class Window {
    public:
        Window(int w, int h, const char* title);
        ~Window();

        void PollEvents(std::function<void(Event&)> eventCallback);
        void SetVsync(bool vsync);
        inline void ToggleVsync() { SetVsync(!m_State.Vsync); }

        void SetFullscreen(bool fullscreen);
        inline void ToggleFullscreen() { SetFullscreen(!m_State.Fullscreen); }

        void SetMaximized(bool maximized);
        inline void ToggleMaximized() { SetMaximized(!m_State.Maximized); }

    private:
        int m_Width;
        int m_Height;
        std::string m_Title;

        struct WindowState {
            bool Closed = false;
            bool Maximized = false;
            bool Minimized = false;
            bool Focused = false;
            bool GainedFocus = false;
            bool LostFocus = false;
            bool Resized = false;
            bool Vsync = false;
            bool Fullscreen = false;
        };

        WindowState m_State;

    private:
        void UpdateState();

    };
}