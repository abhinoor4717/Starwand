#pragma once

#include <raylib.h>
#include <vector>

#include "KeyCodes.h"
#include "MouseCodes.h"

namespace Starwand {
    namespace Input {
        // Key input

        inline static Starwand::Input::Key ToKey(int keycode) {
            return static_cast<Starwand::Input::Key>(keycode);
        }

        inline static int ToRawKey(Key key) {
            return static_cast<int>(key);
        }

        struct KeyState {
            int key;
            bool pressed;
            bool down;
            bool released;
        };

        inline static std::vector<KeyState> GetActiveKeyStates() {
            static bool capsIsDown = false;
            static bool capsWasDown = false;

            static bool numIsDown = false;
            static bool numWasDown = false;

            std::vector<KeyState> keys;

            // Handle normal keys (excluding toggle keys)
            for (int key = 32; key < 349; ++key) {
                if (key == KEY_CAPS_LOCK || key == KEY_NUM_LOCK) continue;

                bool p = ::IsKeyPressed(key);
                bool d = ::IsKeyDown(key);
                bool r = ::IsKeyReleased(key);

                if (p || d || r) {
                    keys.push_back({ key, p, d, r });
                }
            }

            // ---- Poll all pressed keys (handles toggle keys) ----
            int pressedKey = GetKeyPressed();
            while (pressedKey > 0) {
                if (pressedKey == KEY_CAPS_LOCK) {
                    capsIsDown = !capsIsDown; // toggle
                } else if (pressedKey == KEY_NUM_LOCK) {
                    numIsDown = !numIsDown; // toggle
                }

                pressedKey = GetKeyPressed();
            }

            // ---- Emulate Caps Lock state ----
            bool capsPressed = !capsWasDown && capsIsDown;
            bool capsReleased = capsWasDown && !capsIsDown;
            if (capsPressed || capsIsDown || capsReleased) {
                keys.push_back({ KEY_CAPS_LOCK, capsPressed, capsIsDown, capsReleased });
            }
            capsWasDown = capsIsDown;

            // ---- Emulate Num Lock state ----
            bool numPressed = !numWasDown && numIsDown;
            bool numReleased = numWasDown && !numIsDown;
            if (numPressed || numIsDown || numReleased) {
                keys.push_back({ KEY_NUM_LOCK, numPressed, numIsDown, numReleased });
            }
            numWasDown = numIsDown;

            return keys;
        }

        inline static std::vector<KeyState> GetAllKeyStates() {
            static bool capsIsDown = false;
            static bool capsWasDown = false;

            static bool numIsDown = false;
            static bool numWasDown = false;

            std::vector<KeyState> keys;

            // First, handle all non-toggle keys
            for (int key = 32; key < 349; ++key) {
                if (key == KEY_CAPS_LOCK || key == KEY_NUM_LOCK) continue;

                bool p = ::IsKeyPressed(key);
                bool d = ::IsKeyDown(key);
                bool r = ::IsKeyReleased(key);

                keys.push_back({ key, p, d, r });
            }

            // Poll pressed toggle keys (one per frame)
            int pressedKey = GetKeyPressed();
            while (pressedKey > 0) {
                if (pressedKey == KEY_CAPS_LOCK)
                    capsIsDown = !capsIsDown;
                else if (pressedKey == KEY_NUM_LOCK)
                    numIsDown = !numIsDown;

                pressedKey = GetKeyPressed();
            }

            // Manually insert caps lock state
            {
                bool pressed = !capsWasDown && capsIsDown;
                bool released = capsWasDown && !capsIsDown;
                keys.push_back({ KEY_CAPS_LOCK, pressed, capsIsDown, released });
                capsWasDown = capsIsDown;
            }

            // Manually insert num lock state
            {
                bool pressed = !numWasDown && numIsDown;
                bool released = numWasDown && !numIsDown;
                keys.push_back({ KEY_NUM_LOCK, pressed, numIsDown, released });
                numWasDown = numIsDown;
            }

            return keys;
        }


        inline static bool IsKeyPressed(Key key) {
            return ::IsKeyPressed(ToRawKey(key));
        }

        inline static bool IsKeyPressedRepeat(Key key) {
            return ::IsKeyPressedRepeat(ToRawKey(key));
        }

        inline static bool IsKeyReleased(Key key) {
            return ::IsKeyReleased(ToRawKey(key));
        }
        
        inline static bool IsKeyDown(Key key) {
            return ::IsKeyDown(ToRawKey(key));
        }

        inline static bool IsKeyUp(Key key) {
            return ::IsKeyUp(ToRawKey(key));
        }

        // Mouse input

        inline static Starwand::Input::MouseButton ToMouseButton(int mousecode) {
            return static_cast<Starwand::Input::MouseButton>(mousecode);
        }

        inline static int ToRawMouseButton(MouseButton button) {
            return static_cast<int>(button);
        }

        struct MouseState {
            int button;
            bool pressed;
            bool down;
            bool released;
        };

        inline static std::vector<MouseState> GetActiveMouseStates() {
            std::vector<MouseState> buttons;

            // raylib defines 0-7 mouse buttons (left, right, middle, etc.)
            for (int button = 0; button <= 7; ++button) {
                bool p = ::IsMouseButtonPressed(button);
                bool d = ::IsMouseButtonDown(button);
                bool r = ::IsMouseButtonReleased(button);

                if (p || d || r) {
                    buttons.push_back({ button, p, d, r });
                }
            }

            return buttons;
        }

        inline static std::vector<MouseState> GetAllMouseStates() {
            std::vector<MouseState> buttons;

            // raylib defines 0-7 mouse buttons (left, right, middle, etc.)
            for (int button = 0; button <= 7; ++button) {
                bool p = ::IsMouseButtonPressed(button);
                bool d = ::IsMouseButtonDown(button);
                bool r = ::IsMouseButtonReleased(button);
                
                buttons.push_back({ button, p, d, r });
            }

            return buttons;
        }


        
        inline static bool IsMouseButtonPressed(MouseButton button) {
            return ::IsMouseButtonPressed(ToRawMouseButton(button));
        }

        inline static bool IsMouseButtonDown(MouseButton button) {
            return ::IsMouseButtonDown(ToRawMouseButton(button));
        }
        
        inline static bool IsMouseButtonReleased(MouseButton button) {
            return ::IsMouseButtonReleased(ToRawMouseButton(button));
        }

        inline static bool IsMouseButtonUp(MouseButton button) {
            return ::IsMouseButtonUp(ToRawMouseButton(button));
        }

        inline static int GetMouseX() {
            return ::GetMouseX();
        }

        inline static int GetMouseY() {
            return ::GetMouseY();
        }

        inline static int GetMouseWheelMoveX() {
            return ::GetMouseWheelMoveV().x;
        }

        inline static int GetMouseWheelMoveY() {
            return ::GetMouseWheelMoveV().y;
        }

    };
}