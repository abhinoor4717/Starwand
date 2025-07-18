#pragma once

#include "Core.h"
#include "Events.h"

namespace Starwand {

    class Window;

    class STARWAND_API WindowEvent : public Event {
        friend class Window;
    public:
        inline virtual EventType GetEventType() const = 0;
        inline virtual std::string ToString() const = 0;
    protected:
        WindowEvent() {};
    };

    class STARWAND_API WindowClosedEvent : public WindowEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::WindowClosed; }
        std::string ToString() const { return "WindowClosedEvent"; }
    protected:
        WindowClosedEvent() {};
    };

    class STARWAND_API WindowMaximizedEvent : public WindowEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::WindowMaximized; }
        std::string ToString() const { return "WindowMaximizedEvent"; }
    protected:
        WindowMaximizedEvent() {};
    };

    class STARWAND_API WindowMinimizedEvent : public WindowEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::WindowMinimized; }
        std::string ToString() const { return "WindowMinimizedEvent"; }
    protected:
        WindowMinimizedEvent() {};
    };

    class STARWAND_API WindowResizedEvent : public WindowEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::WindowResized; }
        std::string ToString() const { return "WindowResizedEvent: " + std::to_string(m_Width) + ", " + std::to_string(m_Height); }
    protected:
        WindowResizedEvent(int w, int h)
            : m_Width(w), m_Height(h) {}
    private:
        int m_Width, m_Height;
    };

    class STARWAND_API WindowFocusGainedEvent : public WindowEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::WindowFocusGained; }
        std::string ToString() const { return "WindowFocusGainedEvent"; }
    protected:
        WindowFocusGainedEvent() {};
    };

    class STARWAND_API WindowFocusLostEvent : public WindowEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::WindowFocusLost; }
        std::string ToString() const { return "WindowFocusLostEvent"; }
    protected:
        WindowFocusLostEvent() {};
    };
}