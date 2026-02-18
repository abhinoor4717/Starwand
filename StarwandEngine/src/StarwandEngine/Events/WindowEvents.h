#pragma once

#include "Core/Core.h"
#include "Events/Events.h"

namespace Starwand {

    class SW_API WindowEvent : public Event {
    public:
        inline virtual EventType GetEventType() const = 0;
        inline virtual std::string ToString() const = 0;
    protected:
        WindowEvent() = default;
    };

    class SW_API WindowClosedEvent : public WindowEvent {
    public:
        static EventType GetStaticType() { return EventType::WindowClosed; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "WindowClosedEvent"; }
        WindowClosedEvent() = default;
    };

    class SW_API WindowMaximizedEvent : public WindowEvent {
    public:
        static EventType GetStaticType() { return EventType::WindowMaximized; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "WindowMaximizedEvent"; }
        WindowMaximizedEvent() = default;
    };

    class SW_API WindowMinimizedEvent : public WindowEvent {
    public:
        static EventType GetStaticType() { return EventType::WindowMinimized; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "WindowMinimizedEvent"; }
        WindowMinimizedEvent() = default;
    };

    class SW_API WindowRestoredEvent : public WindowEvent {
    public:
        static EventType GetStaticType() { return EventType::WindowRestored; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "WindowRestoredEvent"; }
        WindowRestoredEvent() = default;
    };

    class SW_API WindowResizedEvent : public WindowEvent {
    public:
        static EventType GetStaticType() { return EventType::WindowResized; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "WindowResizedEvent: " + std::to_string(m_Width) + ", " + std::to_string(m_Height); }
        inline uint32_t GetWidth() { return m_Width; }
        inline uint32_t GetHeight() { return m_Height; }
        WindowResizedEvent(int w, int h)
            : m_Width(w), m_Height(h) {}
    private:
        int m_Width, m_Height;
    };

    class SW_API WindowFocusGainedEvent : public WindowEvent {
    public:
        static EventType GetStaticType() { return EventType::WindowFocusGained; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "WindowFocusGainedEvent"; }
        WindowFocusGainedEvent() = default;
    };

    class SW_API WindowFocusLostEvent : public WindowEvent {
    public:
        static EventType GetStaticType() { return EventType::WindowFocusLost; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "WindowFocusLostEvent"; }
        WindowFocusLostEvent() = default;
    };
}