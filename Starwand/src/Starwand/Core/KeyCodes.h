#pragma once

#include "Core.h"
#include <raylib.h>

namespace Starwand {
    namespace Input {
        enum class STARWAND_API Key {
            // Printable keys
            SPACE              = KEY_SPACE,            // Spacebar
            APOSTROPHE         = KEY_APOSTROPHE,       // '
            COMMA              = KEY_COMMA,            // ,
            MINUS              = KEY_MINUS,            // -
            PERIOD             = KEY_PERIOD,           // .
            SLASH              = KEY_SLASH,            // /
            ZERO               = KEY_ZERO,             // 0
            ONE                = KEY_ONE,              // 1
            TWO                = KEY_TWO,              // 2
            THREE              = KEY_THREE,            // 3
            FOUR               = KEY_FOUR,             // 4
            FIVE               = KEY_FIVE,             // 5
            SIX                = KEY_SIX,              // 6
            SEVEN              = KEY_SEVEN,            // 7
            EIGHT              = KEY_EIGHT,            // 8
            NINE               = KEY_NINE,             // 9
            SEMICOLON          = KEY_SEMICOLON,        // ;
            EQUAL              = KEY_EQUAL,            // =
            A                  = KEY_A,
            B                  = KEY_B,
            C                  = KEY_C,
            D                  = KEY_D,
            E                  = KEY_E,
            F                  = KEY_F,
            G                  = KEY_G,
            H                  = KEY_H,
            I                  = KEY_I,
            J                  = KEY_J,
            K                  = KEY_K,
            L                  = KEY_L,
            M                  = KEY_M,
            N                  = KEY_N,
            O                  = KEY_O,
            P                  = KEY_P,
            Q                  = KEY_Q,
            R                  = KEY_R,
            S                  = KEY_S,
            T                  = KEY_T,
            U                  = KEY_U,
            V                  = KEY_V,
            W                  = KEY_W,
            X                  = KEY_X,
            Y                  = KEY_Y,
            Z                  = KEY_Z,
            LEFT_BRACKET       = KEY_LEFT_BRACKET,     // [
            BACKSLASH          = KEY_BACKSLASH,        // '\'
            RIGHT_BRACKET      = KEY_RIGHT_BRACKET,    // ]
            GRAVE              = KEY_GRAVE,            // `

            // Function keys
            ESCAPE             = KEY_ESCAPE,
            ENTER              = KEY_ENTER,
            TAB                = KEY_TAB,
            BACKSPACE          = KEY_BACKSPACE,
            INSERT             = KEY_INSERT,
            DELETE             = KEY_DELETE,
            RIGHT              = KEY_RIGHT,
            LEFT               = KEY_LEFT,
            DOWN               = KEY_DOWN,
            UP                 = KEY_UP,
            PAGE_UP            = KEY_PAGE_UP,
            PAGE_DOWN          = KEY_PAGE_DOWN,
            HOME               = KEY_HOME,
            END                = KEY_END,
            CAPS_LOCK          = KEY_CAPS_LOCK,
            SCROLL_LOCK        = KEY_SCROLL_LOCK,
            NUM_LOCK           = KEY_NUM_LOCK,
            PRINT_SCREEN       = KEY_PRINT_SCREEN,
            PAUSE              = KEY_PAUSE,
            F1                 = KEY_F1,
            F2                 = KEY_F2,
            F3                 = KEY_F3,
            F4                 = KEY_F4,
            F5                 = KEY_F5,
            F6                 = KEY_F6,
            F7                 = KEY_F7,
            F8                 = KEY_F8,
            F9                 = KEY_F9,
            F10                = KEY_F10,
            F11                = KEY_F11,
            F12                = KEY_F12,

            // Keypad keys
            KP_0               = KEY_KP_0,
            KP_1               = KEY_KP_1,
            KP_2               = KEY_KP_2,
            KP_3               = KEY_KP_3,
            KP_4               = KEY_KP_4,
            KP_5               = KEY_KP_5,
            KP_6               = KEY_KP_6,
            KP_7               = KEY_KP_7,
            KP_8               = KEY_KP_8,
            KP_9               = KEY_KP_9,
            KP_DECIMAL         = KEY_KP_DECIMAL,
            KP_DIVIDE          = KEY_KP_DIVIDE,
            KP_MULTIPLY        = KEY_KP_MULTIPLY,
            KP_SUBTRACT        = KEY_KP_SUBTRACT,
            KP_ADD             = KEY_KP_ADD,
            KP_ENTER           = KEY_KP_ENTER,
            KP_EQUAL           = KEY_KP_EQUAL,

            // Modifier keys
            LEFT_SHIFT         = KEY_LEFT_SHIFT,
            LEFT_CONTROL       = KEY_LEFT_CONTROL,
            LEFT_ALT           = KEY_LEFT_ALT,
            LEFT_SUPER         = KEY_LEFT_SUPER,       // Windows / Command / Meta
            RIGHT_SHIFT        = KEY_RIGHT_SHIFT,
            RIGHT_CONTROL      = KEY_RIGHT_CONTROL,
            RIGHT_ALT          = KEY_RIGHT_ALT,
            RIGHT_SUPER        = KEY_RIGHT_SUPER,
            KB_MENU            = KEY_KB_MENU           // Menu key
        };
    }
}
