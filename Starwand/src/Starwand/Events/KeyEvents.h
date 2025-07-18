#pragma once

#include "Core.h"
#include <string>

#include "Events.h"

namespace Starwand {

    class Window;

    class STARWAND_API KeyEvent : public Event {
        friend class Window;
    public:
        inline virtual EventType GetEventType() const = 0;
        inline virtual std::string ToString() const = 0;
        inline int GetKeyCode() const { return m_KeyCode; }
    protected:
        KeyEvent(int keycode)
            : m_KeyCode(keycode) {}
    private:
        int m_KeyCode;
    };

    class STARWAND_API KeyPressedEvent : public KeyEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::KeyPressed; }
        std::string ToString() const { return "KeyPressedEvent: " + std::to_string(GetKeyCode()); }
    protected:
        KeyPressedEvent(int keycode)
            : KeyEvent(keycode) {}
    };

    class STARWAND_API KeyReleasedEvent : public KeyEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::KeyReleased; }
        std::string ToString() const { return "KeyReleasedEvent: " + std::to_string(GetKeyCode()); }
    protected:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) {}
    };

    class STARWAND_API KeyDownEvent : public KeyEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::KeyDown; }
        std::string ToString() const { return "KeyDownEvent: " + std::to_string(GetKeyCode()); }
    protected:
        KeyDownEvent(int keycode)
            : KeyEvent(keycode) {}
    };

    class STARWAND_API KeyUpEvent : public KeyEvent {
        friend class Window;
    public:
        EventType GetEventType() const { return EventType::KeyUp; }
        std::string ToString() const { return "KeyUpEvent: " + std::to_string(GetKeyCode()); }
    protected:
        KeyUpEvent(int keycode)
            : KeyEvent(keycode) {}
    };
}