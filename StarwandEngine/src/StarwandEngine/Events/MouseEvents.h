#pragma once

#include "Core.h"
#include "Events.h"

#include "Input.h"
#include "MouseButton.h"
#include <glm/glm.hpp>

namespace Starwand {

    class Window;

    class SW_API MouseEvent : public Event {
        friend class Window;
    public:
        inline virtual EventType GetEventType() const = 0;
        inline virtual std::string ToString() const = 0;
    protected:
        MouseEvent() {};
    };

    class SW_API MouseButtonEvent : public MouseEvent {
        friend class Window;
    public:
        inline virtual EventType GetEventType() const = 0;
        inline virtual std::string ToString() const = 0;
        inline MouseButton GetMouseButton() const { return m_mouseButton; }
        inline glm::vec2 GetPosition() { return m_pos; }
    protected:
        MouseButtonEvent(glm::vec2 pos, MouseButton button)
            : m_pos(pos), m_mouseButton(button) {}
    private:
        glm::vec2 m_pos;
        MouseButton m_mouseButton;
    };

    class SW_API MouseButtonDownEvent : public MouseButtonEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::MouseButtonDown; }
        EventType GetEventType() const { return GetStaticType(); };
        std::string ToString() const { return "MouseButtonDownEvent: " + Input::MouseButtonToString(GetMouseButton()) + " (" + std::to_string(static_cast<int>(GetMouseButton())) + ")"; }
    protected:
        MouseButtonDownEvent(glm::vec2 pos, MouseButton button)
            : MouseButtonEvent(pos, button) {}
    };

    class SW_API MouseButtonUpEvent : public MouseButtonEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::MouseButtonUp; }
        EventType GetEventType() const { return GetStaticType(); };
        std::string ToString() const { return "MouseButtonUpEvent: " + Input::MouseButtonToString(GetMouseButton()) + " (" + std::to_string(static_cast<int>(GetMouseButton())) + ")"; }
    protected:
        MouseButtonUpEvent(glm::vec2 pos, MouseButton button)
            : MouseButtonEvent(pos, button) {}
    };

    class SW_API MouseMovedEvent : public MouseEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::MouseMoved; }
        inline EventType GetEventType() const { return GetStaticType(); }
        inline std::string ToString() const { return "MouseMovedEvent: " + std::to_string(m_pos.x) + ", " + std::to_string(m_pos.y); }
        inline glm::vec2 GetPosition() const { return m_pos; }
    protected:
        MouseMovedEvent(glm::vec2 pos)
            : m_pos(pos) {}
    private:
        glm::vec2 m_pos;
    };

    class SW_API MouseWheelEvent : public MouseEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::MouseWheel; }
        inline EventType GetEventType() const { return GetStaticType(); }
        inline std::string ToString() const { return "MouseWheelEvent: " + std::to_string(m_offsets.x) + ", " + std::to_string(m_offsets.y);}
        inline glm::vec2 GetOffsets() const { return m_offsets; }
    protected:
        MouseWheelEvent(glm::vec2 offsets)
            : m_offsets(offsets) {}
    private:
        glm::vec2 m_offsets;
    };

}