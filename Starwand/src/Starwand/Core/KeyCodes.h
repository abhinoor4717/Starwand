#pragma once

#include "Core.h"
#include <raylib.h>

namespace Starwand {
    namespace Input {
        enum class STARWAND_API Key {
            // Printable keys
            SPACE              = ::KEY_SPACE,            // Spacebar
            APOSTROPHE         = ::KEY_APOSTROPHE,       // '
            COMMA              = ::KEY_COMMA,            // ,
            MINUS              = ::KEY_MINUS,            // -
            PERIOD             = ::KEY_PERIOD,           // .
            SLASH              = ::KEY_SLASH,            // /
            ZERO               = ::KEY_ZERO,             // 0
            ONE                = ::KEY_ONE,              // 1
            TWO                = ::KEY_TWO,              // 2
            THREE              = ::KEY_THREE,            // 3
            FOUR               = ::KEY_FOUR,             // 4
            FIVE               = ::KEY_FIVE,             // 5
            SIX                = ::KEY_SIX,              // 6
            SEVEN              = ::KEY_SEVEN,            // 7
            EIGHT              = ::KEY_EIGHT,            // 8
            NINE               = ::KEY_NINE,             // 9
            SEMICOLON          = ::KEY_SEMICOLON,        // ;
            EQUAL              = ::KEY_EQUAL,            // =
            A                  = ::KEY_A,
            B                  = ::KEY_B,
            C                  = ::KEY_C,
            D                  = ::KEY_D,
            E                  = ::KEY_E,
            F                  = ::KEY_F,
            G                  = ::KEY_G,
            H                  = ::KEY_H,
            I                  = ::KEY_I,
            J                  = ::KEY_J,
            K                  = ::KEY_K,
            L                  = ::KEY_L,
            M                  = ::KEY_M,
            N                  = ::KEY_N,
            O                  = ::KEY_O,
            P                  = ::KEY_P,
            Q                  = ::KEY_Q,
            R                  = ::KEY_R,
            S                  = ::KEY_S,
            T                  = ::KEY_T,
            U                  = ::KEY_U,
            V                  = ::KEY_V,
            W                  = ::KEY_W,
            X                  = ::KEY_X,
            Y                  = ::KEY_Y,
            Z                  = ::KEY_Z,
            LEFT_BRACKET       = ::KEY_LEFT_BRACKET,     // [
            BACKSLASH          = ::KEY_BACKSLASH,        // '\'
            RIGHT_BRACKET      = ::KEY_RIGHT_BRACKET,    // ]
            GRAVE              = ::KEY_GRAVE,            // `

            // Function keys
            ESCAPE             = ::KEY_ESCAPE,
            ENTER              = ::KEY_ENTER,
            TAB                = ::KEY_TAB,
            BACKSPACE          = ::KEY_BACKSPACE,
            INSERT             = ::KEY_INSERT,
            DELETE             = ::KEY_DELETE,
            RIGHT              = ::KEY_RIGHT,
            LEFT               = ::KEY_LEFT,
            DOWN               = ::KEY_DOWN,
            UP                 = ::KEY_UP,
            PAGE_UP            = ::KEY_PAGE_UP,
            PAGE_DOWN          = ::KEY_PAGE_DOWN,
            HOME               = ::KEY_HOME,
            END                = ::KEY_END,
            CAPS_LOCK          = ::KEY_CAPS_LOCK,
            SCROLL_LOCK        = ::KEY_SCROLL_LOCK,
            NUM_LOCK           = ::KEY_NUM_LOCK,
            PRINT_SCREEN       = ::KEY_PRINT_SCREEN,
            PAUSE              = ::KEY_PAUSE,
            F1                 = ::KEY_F1,
            F2                 = ::KEY_F2,
            F3                 = ::KEY_F3,
            F4                 = ::KEY_F4,
            F5                 = ::KEY_F5,
            F6                 = ::KEY_F6,
            F7                 = ::KEY_F7,
            F8                 = ::KEY_F8,
            F9                 = ::KEY_F9,
            F10                = ::KEY_F10,
            F11                = ::KEY_F11,
            F12                = ::KEY_F12,

            // Keypad keys
            KP_0               = ::KEY_KP_0,
            KP_1               = ::KEY_KP_1,
            KP_2               = ::KEY_KP_2,
            KP_3               = ::KEY_KP_3,
            KP_4               = ::KEY_KP_4,
            KP_5               = ::KEY_KP_5,
            KP_6               = ::KEY_KP_6,
            KP_7               = ::KEY_KP_7,
            KP_8               = ::KEY_KP_8,
            KP_9               = ::KEY_KP_9,
            KP_DECIMAL         = ::KEY_KP_DECIMAL,
            KP_DIVIDE          = ::KEY_KP_DIVIDE,
            KP_MULTIPLY        = ::KEY_KP_MULTIPLY,
            KP_SUBTRACT        = ::KEY_KP_SUBTRACT,
            KP_ADD             = ::KEY_KP_ADD,
            KP_ENTER           = ::KEY_KP_ENTER,
            KP_EQUAL           = ::KEY_KP_EQUAL,

            // Modifier keys
            LEFT_SHIFT         = ::KEY_LEFT_SHIFT,
            LEFT_CONTROL       = ::KEY_LEFT_CONTROL,
            LEFT_ALT           = ::KEY_LEFT_ALT,
            LEFT_SUPER         = ::KEY_LEFT_SUPER,       // Windows / Command / Meta
            RIGHT_SHIFT        = ::KEY_RIGHT_SHIFT,
            RIGHT_CONTROL      = ::KEY_RIGHT_CONTROL,
            RIGHT_ALT          = ::KEY_RIGHT_ALT,
            RIGHT_SUPER        = ::KEY_RIGHT_SUPER,
            KB_MENU            = ::KEY_KB_MENU           // Menu key
        };

        inline const char* KeyToString(Key key) {
            switch (key) {
                case Key::SPACE:              return "SPACE";
                case Key::APOSTROPHE:         return "APOSTROPHE";
                case Key::COMMA:              return "COMMA";
                case Key::MINUS:              return "MINUS";
                case Key::PERIOD:             return "PERIOD";
                case Key::SLASH:              return "SLASH";
                case Key::ZERO:               return "ZERO";
                case Key::ONE:                return "ONE";
                case Key::TWO:                return "TWO";
                case Key::THREE:              return "THREE";
                case Key::FOUR:               return "FOUR";
                case Key::FIVE:               return "FIVE";
                case Key::SIX:                return "SIX";
                case Key::SEVEN:              return "SEVEN";
                case Key::EIGHT:              return "EIGHT";
                case Key::NINE:               return "NINE";
                case Key::SEMICOLON:          return "SEMICOLON";
                case Key::EQUAL:              return "EQUAL";
                case Key::A:                  return "A";
                case Key::B:                  return "B";
                case Key::C:                  return "C";
                case Key::D:                  return "D";
                case Key::E:                  return "E";
                case Key::F:                  return "F";
                case Key::G:                  return "G";
                case Key::H:                  return "H";
                case Key::I:                  return "I";
                case Key::J:                  return "J";
                case Key::K:                  return "K";
                case Key::L:                  return "L";
                case Key::M:                  return "M";
                case Key::N:                  return "N";
                case Key::O:                  return "O";
                case Key::P:                  return "P";
                case Key::Q:                  return "Q";
                case Key::R:                  return "R";
                case Key::S:                  return "S";
                case Key::T:                  return "T";
                case Key::U:                  return "U";
                case Key::V:                  return "V";
                case Key::W:                  return "W";
                case Key::X:                  return "X";
                case Key::Y:                  return "Y";
                case Key::Z:                  return "Z";
                case Key::LEFT_BRACKET:       return "LEFT_BRACKET";
                case Key::BACKSLASH:          return "BACKSLASH";
                case Key::RIGHT_BRACKET:      return "RIGHT_BRACKET";
                case Key::GRAVE:              return "GRAVE";

                case Key::ESCAPE:             return "ESCAPE";
                case Key::ENTER:              return "ENTER";
                case Key::TAB:                return "TAB";
                case Key::BACKSPACE:          return "BACKSPACE";
                case Key::INSERT:             return "INSERT";
                case Key::DELETE:             return "DELETE";
                case Key::RIGHT:              return "RIGHT";
                case Key::LEFT:               return "LEFT";
                case Key::DOWN:               return "DOWN";
                case Key::UP:                 return "UP";
                case Key::PAGE_UP:            return "PAGE_UP";
                case Key::PAGE_DOWN:          return "PAGE_DOWN";
                case Key::HOME:               return "HOME";
                case Key::END:                return "END";
                case Key::CAPS_LOCK:          return "CAPS_LOCK";
                case Key::SCROLL_LOCK:        return "SCROLL_LOCK";
                case Key::NUM_LOCK:           return "NUM_LOCK";
                case Key::PRINT_SCREEN:       return "PRINT_SCREEN";
                case Key::PAUSE:              return "PAUSE";
                case Key::F1:                 return "F1";
                case Key::F2:                 return "F2";
                case Key::F3:                 return "F3";
                case Key::F4:                 return "F4";
                case Key::F5:                 return "F5";
                case Key::F6:                 return "F6";
                case Key::F7:                 return "F7";
                case Key::F8:                 return "F8";
                case Key::F9:                 return "F9";
                case Key::F10:                return "F10";
                case Key::F11:                return "F11";
                case Key::F12:                return "F12";

                case Key::KP_0:               return "KP_0";
                case Key::KP_1:               return "KP_1";
                case Key::KP_2:               return "KP_2";
                case Key::KP_3:               return "KP_3";
                case Key::KP_4:               return "KP_4";
                case Key::KP_5:               return "KP_5";
                case Key::KP_6:               return "KP_6";
                case Key::KP_7:               return "KP_7";
                case Key::KP_8:               return "KP_8";
                case Key::KP_9:               return "KP_9";
                case Key::KP_DECIMAL:         return "KP_DECIMAL";
                case Key::KP_DIVIDE:          return "KP_DIVIDE";
                case Key::KP_MULTIPLY:        return "KP_MULTIPLY";
                case Key::KP_SUBTRACT:        return "KP_SUBTRACT";
                case Key::KP_ADD:             return "KP_ADD";
                case Key::KP_ENTER:           return "KP_ENTER";
                case Key::KP_EQUAL:           return "KP_EQUAL";

                case Key::LEFT_SHIFT:         return "LEFT_SHIFT";
                case Key::LEFT_CONTROL:       return "LEFT_CONTROL";
                case Key::LEFT_ALT:           return "LEFT_ALT";
                case Key::LEFT_SUPER:         return "LEFT_SUPER";
                case Key::RIGHT_SHIFT:        return "RIGHT_SHIFT";
                case Key::RIGHT_CONTROL:      return "RIGHT_CONTROL";
                case Key::RIGHT_ALT:          return "RIGHT_ALT";
                case Key::RIGHT_SUPER:        return "RIGHT_SUPER";
                case Key::KB_MENU:            return "KB_MENU";

                default:                      return "UNKNOWN_KEY";
            }
        }

        inline std::ostream& operator<<(std::ostream& os, Key button) {
            return os << KeyToString(button);
        }

    }
}