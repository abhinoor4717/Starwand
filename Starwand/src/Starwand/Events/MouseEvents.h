#pragma once

#include "Core.h"
#include "Events.h"

#include "Input.h"
#include "MouseCodes.h"

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
        inline Input::MouseButton GetMouseButton() const { return m_MouseButton; }
        inline int GetX() { return m_X; }
        inline int GetY() { return m_Y; }
    protected:
        MouseButtonEvent(int x, int y, Input::MouseButton button)
            : m_X(x), m_Y(y), m_MouseButton(button) {}
    private:
        int m_X, m_Y;
        Input::MouseButton m_MouseButton;
    };

    class STARWAND_API MouseButtonPressedEvent : public MouseButtonEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::MouseButtonPressed; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "MouseButtonPressedEvent: " + std::string(Input::MouseButtonToString(GetMouseButton())) + " (" + std::to_string(Input::ToRawMouseButton(GetMouseButton())) + ")"; }
    protected:
        MouseButtonPressedEvent(int x, int y, Input::MouseButton button)
            : MouseButtonEvent(x, y, button) {}
    };

    class STARWAND_API MouseButtonReleasedEvent : public MouseButtonEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::MouseButtonReleased; }
        EventType GetEventType() const { return GetStaticType(); };
        std::string ToString() const { return "MouseButtonReleasedEvent: " + std::string(Input::MouseButtonToString(GetMouseButton())) + " (" + std::to_string(Input::ToRawMouseButton(GetMouseButton())) + ")"; }
    protected:
        MouseButtonReleasedEvent(int x, int y, Input::MouseButton button)
            : MouseButtonEvent(x, y, button) {}
    };

    class STARWAND_API MouseButtonDownEvent : public MouseButtonEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::MouseButtonDown; }
        EventType GetEventType() const { return GetStaticType(); };
        std::string ToString() const { return "MouseButtonDownEvent: " + std::string(Input::MouseButtonToString(GetMouseButton())) + " (" + std::to_string(Input::ToRawMouseButton(GetMouseButton())) + ")"; }
    protected:
        MouseButtonDownEvent(int x, int y, Input::MouseButton button)
            : MouseButtonEvent(x, y, button) {}
    };

    class STARWAND_API MouseButtonUpEvent : public MouseButtonEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::MouseButtonUp; }
        EventType GetEventType() const { return GetStaticType(); };
        std::string ToString() const { return "MouseButtonUpEvent: " + std::string(Input::MouseButtonToString(GetMouseButton())) + " (" + std::to_string(Input::ToRawMouseButton(GetMouseButton())) + ")"; }
    protected:
        MouseButtonUpEvent(int x, int y, Input::MouseButton button)
            : MouseButtonEvent(x, y, button) {}
    };

    class STARWAND_API MouseMovedEvent : public MouseEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::MouseMoved; }
        inline EventType GetEventType() const { return GetStaticType(); }
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
        static EventType GetStaticType() { return EventType::MouseWheel; }
        inline EventType GetEventType() const { return GetStaticType(); }
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