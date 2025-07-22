#pragma once

#include "Core.h"
#include <raylib.h>

namespace Starwand {
    namespace Input {
        enum class STARWAND_API MouseButton {
            LEFT        = ::MOUSE_BUTTON_LEFT,
            RIGHT       = ::MOUSE_BUTTON_RIGHT,
            MIDDLE      = ::MOUSE_BUTTON_MIDDLE,
            SIDE_1      = ::MOUSE_BUTTON_SIDE,
            SIDE_2      = ::MOUSE_BUTTON_EXTRA,
            FORWARD     = ::MOUSE_BUTTON_FORWARD,
            BACK        = ::MOUSE_BUTTON_BACK,
        };

        inline const char* MouseButtonToString(MouseButton button) {
            switch (button) {
                case MouseButton::LEFT:    return "LEFT";
                case MouseButton::RIGHT:   return "RIGHT";
                case MouseButton::MIDDLE:  return "MIDDLE";
                case MouseButton::SIDE_1:  return "SIDE_1";
                case MouseButton::SIDE_2:  return "SIDE_2";
                case MouseButton::FORWARD: return "FORWARD";
                case MouseButton::BACK:    return "BACK";
                default:                   return "UNKNOWN";
            }
        }

        inline std::ostream& operator<<(std::ostream& os, MouseButton button) {
            return os << MouseButtonToString(button);
        }

    };
}