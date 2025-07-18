#pragma once

#include "Core.h"
#include "Events.h"

namespace Starwand {

    class Window;

    class STARWAND_API MouseEvent : public Event {
        friend class Window;
    public:
        inline virtual EventType GetEventType() const = 0;
        inline virtual std::string ToString() const = 0;
    protected:
        MouseEvent() {};
    };

    class STARWAND_API MouseButtonEvent : public MouseEvent {
        friend class Window;
    public:
        inline virtual EventType GetEventType() const = 0;
        inline virtual std::string ToString() const = 0;
        inline int GetMouseButton() const { return m_MouseButton; }
    protected:
        MouseButtonEvent(int button)
            : m_MouseButton(button) {}
    private:
        int m_MouseButton;
    };

    class STARWAND_API MouseButtonPressedEvent : public MouseButtonEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::MouseButtonPressed; };
        std::string ToString() const { return "MouseButtonPressedEvent: " + std::to_string(GetMouseButton()); }
    protected:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}
    };

    class STARWAND_API MouseButtonReleasedEvent : public MouseButtonEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::MouseButtonReleased; };
        std::string ToString() const { return "MouseButtonReleasedEvent: " + std::to_string(GetMouseButton()); }
    protected:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) {}
    };

    class STARWAND_API MouseButtonDownEvent : public MouseButtonEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::MouseButtonDown; };
        std::string ToString() const { return "MouseButtonDownEvent: " + std::to_string(GetMouseButton()); }
    protected:
        MouseButtonDownEvent(int button)
            : MouseButtonEvent(button) {}
    };

    class STARWAND_API MouseButtonUpEvent : public MouseButtonEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::MouseButtonUp; };
        std::string ToString() const { return "MouseButtonUpEvent: " + std::to_string(GetMouseButton()); }
    protected:
        MouseButtonUpEvent(int button)
            : MouseButtonEvent(button) {}
    };

    class STARWAND_API MouseMovedEvent : public MouseEvent {
        friend class Window;
    public:
        inline EventType GetEventType() const { return EventType::MouseMoved; }
        inline std::string ToString() const { return "MouseMovedEvent: " + std::to_string(m_MouseX) + ", " + std::to_string(m_MouseY); }
        inline int GetX() const { return m_MouseX; }
        inline int GetY() const { return m_MouseY; }
    protected:
        MouseMovedEvent(int x, int y)
            : m_MouseX(x), m_MouseY(y) {}
    private:
        int m_MouseX, m_MouseY;
    };

    class STARWAND_API MouseWheelEvent : public MouseEvent {
        friend class Window;
    public:
        inline EventType GetEventType() const { return EventType::MouseWheel; }
        inline std::string ToString() const { return "MouseWheelEvent: " + std::to_string(m_WheelX) + ", " + std::to_string(m_WheelY);}
        inline float GetX() const { return m_WheelX; }
        inline float GetY() const { return m_WheelY; }
    protected:
        MouseWheelEvent(float x, float y)
            : m_WheelX(x), m_WheelY(y) {}
    private:
        float m_WheelX, m_WheelY;
    };

}