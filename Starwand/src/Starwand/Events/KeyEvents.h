#pragma once

#include "Core.h"
#include <string>

#include "Events.h"
#include "Input.h"
#include "KeyCodes.h"

namespace Starwand {

    class Window;

    class STARWAND_API KeyEvent : public Event {
        friend class Window;
    public:
        inline virtual EventType GetEventType() const = 0;
        inline virtual std::string ToString() const = 0;
        inline Input::Key GetKeyCode() const { return m_KeyCode; }
    protected:
        KeyEvent(Input::Key keycode)
            : m_KeyCode(keycode) {}
    private:
        Input::Key m_KeyCode;
    };

    class STARWAND_API KeyPressedEvent : public KeyEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::KeyPressed; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "KeyPressedEvent: " + std::string(Input::KeyToString(GetKeyCode())) + " (" + std::to_string(Input::ToRawKey(GetKeyCode())) + ")"; }
    protected:
        KeyPressedEvent(Input::Key keycode)
            : KeyEvent(keycode) {}
    };

    class STARWAND_API KeyReleasedEvent : public KeyEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::KeyReleased; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "KeyReleasedEvent: " + std::string(Input::KeyToString(GetKeyCode())) + " (" + std::to_string(Input::ToRawKey(GetKeyCode())) + ")"; }
    protected:
        KeyReleasedEvent(Input::Key keycode)
            : KeyEvent(keycode) {}
    };

    class STARWAND_API KeyDownEvent : public KeyEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::KeyDown; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "KeyDownEvent: " + std::string(Input::KeyToString(GetKeyCode())) + " (" + std::to_string(Input::ToRawKey(GetKeyCode())) + ")"; }
    protected:
        KeyDownEvent(Input::Key keycode)
            : KeyEvent(keycode) {}
    };

    class STARWAND_API KeyUpEvent : public KeyEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::KeyUp; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "KeyUpEvent: " + std::string(Input::KeyToString(GetKeyCode())) + " (" + std::to_string(Input::ToRawKey(GetKeyCode())) + ")"; }
    protected:
        KeyUpEvent(Input::Key keycode)
            : KeyEvent(keycode) {}
    };
}