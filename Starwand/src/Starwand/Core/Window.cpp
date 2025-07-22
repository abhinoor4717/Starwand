#include "swpch.h"

#include "Window.h"

#include "Application.h"
#include "Events/WindowEvents.h"
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"
#include "Input.h"

namespace Starwand {
    Window::Window(int w, int h, const char* title)
        : m_Width(w), m_Height(h), m_Title(title) {
            ::InitWindow(w, h, title);
            ::SetWindowState(::FLAG_WINDOW_RESIZABLE);
            ::SetExitKey(0);
    }

    Window::~Window() {
        ::CloseWindow();
    }

    void Window::PollEvents(std::function<void(Event&)> eventCallback) {
        UpdateState();
        
        if (m_State.Closed) {
            WindowClosedEvent e;
            eventCallback(e);
        }

        if (m_State.Maximized) {
            WindowMaximizedEvent e;
            eventCallback(e);
        }

        if (m_State.Minimized) {
            WindowMinimizedEvent e;
            eventCallback(e);
        }

        if (m_State.GainedFocus) {
            WindowFocusGainedEvent e;
            eventCallback(e);
        }

        if (m_State.LostFocus) {
            WindowFocusLostEvent e;
            eventCallback(e);
        }

        if (m_State.Resized) {
            int w = ::GetScreenWidth();
            int h = ::GetScreenHeight();
            WindowResizedEvent e(w, h);
            eventCallback(e);
        }

        auto keys = Input::GetActiveKeyStates();
        for (const auto& k : keys ) {
            if (k.pressed) {
                KeyPressedEvent e(Input::ToKey(k.key));
                eventCallback(e);
            }

            if (k.released) {
                KeyReleasedEvent e(Input::ToKey(k.key));
                eventCallback(e);
            }
            
            if (k.down) {
                KeyDownEvent e(Input::ToKey(k.key));
                eventCallback(e);
            }
        }

        auto buttons = Input::GetActiveMouseStates();
        for (const auto& b : buttons) {
            if (b.pressed) {
                MouseButtonPressedEvent e(::GetMouseX(), ::GetMouseY(), Input::ToMouseButton(b.button));
                eventCallback(e);
            }

            if (b.released) {
                MouseButtonReleasedEvent e(::GetMouseX(), ::GetMouseY(), Input::ToMouseButton(b.button));
                eventCallback(e);
            }

            if (b.down) {
                MouseButtonDownEvent e(::GetMouseX(), ::GetMouseY(), Input::ToMouseButton(b.button));
                eventCallback(e);
            }
        }

        auto mouseDelta = ::GetMouseDelta();
        if (mouseDelta.x != 0 || mouseDelta.y != 0) {
            MouseMovedEvent e(::GetMouseX(), ::GetMouseY());
            eventCallback(e);
        }

    }

    void Window::UpdateState() {
        bool wasFocused   = m_State.Focused;
        bool wasMinimized = m_State.Minimized;
        bool wasMaximized = m_State.Maximized;

        bool nowFocused   = ::IsWindowFocused();
        bool nowMinimized = ::IsWindowMinimized();
        bool nowMaximized = ::IsWindowMaximized();

        m_State.LostFocus = (wasFocused && !nowFocused);
        m_State.GainedFocus  = (!wasFocused && nowFocused); 
        m_State.Focused      = nowFocused;                  

        m_State.Minimized    = nowMinimized;
        m_State.Maximized    = nowMaximized;

        m_State.Closed       = ::WindowShouldClose();
        m_State.Resized      = ::IsWindowResized();
    }

    void Window::SetVsync(bool vsync) {
        if (vsync && !m_State.Vsync) {
            ::SetWindowState(::FLAG_VSYNC_HINT);
            m_State.Vsync = true;
        }
        else if (!vsync && m_State.Vsync) {
            ::ClearWindowState(::FLAG_VSYNC_HINT);
            m_State.Vsync = false;
        }
    }

    void Window::SetFullscreen(bool fullscreen) {
        if (fullscreen && !::IsWindowFullscreen()) {
            ::ToggleFullscreen();
            m_State.Fullscreen = true;
        }
        else if (!fullscreen && ::IsWindowFullscreen()) {
            ::ToggleFullscreen();
            m_State.Fullscreen = false;
        }
    }

    void Window::SetMaximized(bool maximized) {
        if (maximized && !m_State.Maximized) {
            ::MaximizeWindow();
        }
        else if (!maximized && m_State.Maximized) {
            ::ClearWindowState(::FLAG_WINDOW_MAXIMIZED);
        }
    }
}