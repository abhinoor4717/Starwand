#pragma once

#include "Core.h"
#include <string>

#include "Events.h"
#include "Input.h"
#include "Key.h"

namespace Starwand {

    class Window;

    class SW_API KeyEvent : public Event {
        friend class Window;
    public:
        inline virtual EventType GetEventType() const = 0;
        inline virtual std::string ToString() const = 0;
        inline Key GetKey() const { return m_key; }
    protected:
        KeyEvent(Key key)
            : m_key(key) {}
    private:
        Key m_key;
    };

    class SW_API KeyDownEvent : public KeyEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::KeyDown; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "KeyDownEvent: " + Input::KeyToString(GetKey()) + " (" + std::to_string(static_cast<int>(GetKey())) + ")"; }
    protected:
        KeyDownEvent(Key key)
            : KeyEvent(key) {}
    };

    class SW_API KeyUpEvent : public KeyEvent {
        friend class Window;
    public:
        static EventType GetStaticType() { return EventType::KeyUp; }
        EventType GetEventType() const { return GetStaticType(); }
        std::string ToString() const { return "KeyUpEvent: " + Input::KeyToString(GetKey()) + " (" + std::to_string(static_cast<int>(GetKey())) + ")"; }
    protected:
        KeyUpEvent(Key key)
            : KeyEvent(key) {}
    };
}