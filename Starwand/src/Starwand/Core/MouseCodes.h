#pragma once

#include "Core.h"
#include <raylib.h>

namespace Starwand {
    namespace Input {
        enum class STARWAND_API MouseButton {
            LEFT        = MOUSE_BUTTON_LEFT,
            RIGHT       = MOUSE_BUTTON_RIGHT,
            MIDDLE      = MOUSE_BUTTON_MIDDLE,
            SIDE_1      = MOUSE_BUTTON_SIDE,
            SIDE_2      = MOUSE_BUTTON_EXTRA,
            FORWARD     = MOUSE_BUTTON_FORWARD,
            BACK        = MOUSE_BUTTON_BACK
        };
    };
}