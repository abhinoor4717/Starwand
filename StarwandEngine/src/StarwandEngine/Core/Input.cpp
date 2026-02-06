#include "Input.h"

#include <glfw/glfw3.h>
#include <Application.h>

namespace Starwand {
    bool Input::IsKeyDown(Key key) {
        GLFWwindow* win = (GLFWwindow*)Application::GetInstance().GetWindow().GetNativeWindow();
        return glfwGetKey(win, static_cast<int>(key)) == GLFW_PRESS ? true : false;
    }

    bool Input::IsKeyUp(Key key) {
        GLFWwindow* win = (GLFWwindow*)Application::GetInstance().GetWindow().GetNativeWindow();
        return glfwGetKey(win, static_cast<int>(key)) == GLFW_RELEASE ? true : false;
    }

    glm::vec2 Input::GetMousePosition() {
        GLFWwindow* win = (GLFWwindow*)Application::GetInstance().GetWindow().GetNativeWindow();
        double x, y;
        glfwGetCursorPos(win, &x, &y);
        return glm::vec2(x, y);
    }

    bool Input::IsMouseButtonDown(MouseButton mb) {
        GLFWwindow* win = (GLFWwindow*)Application::GetInstance().GetWindow().GetNativeWindow();
        return glfwGetMouseButton(win, static_cast<int>(mb)) == GLFW_PRESS ? true : false;
    }

    bool Input::IsMouseButtonUp(MouseButton mb) {
        GLFWwindow* win = (GLFWwindow*)Application::GetInstance().GetWindow().GetNativeWindow();
        return glfwGetMouseButton(win, static_cast<int>(mb)) == GLFW_RELEASE ? true : false;
    }

    std::string Input::KeyToString(Key key) {
        switch (key) {
            case Key::Space:        return "Space";
            case Key::Apostrophe:   return "'";
            case Key::Comma:        return ",";
            case Key::Minus:        return "-";
            case Key::Period:       return ".";
            case Key::Slash:        return "/";

            case Key::D0: return "0";
            case Key::D1: return "1";
            case Key::D2: return "2";
            case Key::D3: return "3";
            case Key::D4: return "4";
            case Key::D5: return "5";
            case Key::D6: return "6";
            case Key::D7: return "7";
            case Key::D8: return "8";
            case Key::D9: return "9";

            case Key::A: return "A";
            case Key::B: return "B";
            case Key::C: return "C";
            case Key::D: return "D";
            case Key::E: return "E";
            case Key::F: return "F";
            case Key::G: return "G";
            case Key::H: return "H";
            case Key::I: return "I";
            case Key::J: return "J";
            case Key::K: return "K";
            case Key::L: return "L";
            case Key::M: return "M";
            case Key::N: return "N";
            case Key::O: return "O";
            case Key::P: return "P";
            case Key::Q: return "Q";
            case Key::R: return "R";
            case Key::S: return "S";
            case Key::T: return "T";
            case Key::U: return "U";
            case Key::V: return "V";
            case Key::W: return "W";
            case Key::X: return "X";
            case Key::Y: return "Y";
            case Key::Z: return "Z";

            case Key::Escape:     return "Escape";
            case Key::Enter:      return "Enter";
            case Key::Tab:        return "Tab";
            case Key::Backspace:  return "Backspace";
            case Key::Insert:     return "Insert";
            case Key::Delete:     return "Delete";
            case Key::Right:      return "Right Arrow";
            case Key::Left:       return "Left Arrow";
            case Key::Down:       return "Down Arrow";
            case Key::Up:         return "Up Arrow";

            case Key::LeftShift:   return "Left Shift";
            case Key::LeftControl: return "Left Ctrl";
            case Key::LeftAlt:     return "Left Alt";
            case Key::RightShift:  return "Right Shift";
            case Key::RightControl:return "Right Ctrl";
            case Key::RightAlt:    return "Right Alt";

            case Key::F1:  return "F1";
            case Key::F2:  return "F2";
            case Key::F3:  return "F3";
            case Key::F4:  return "F4";
            case Key::F5:  return "F5";
            case Key::F6:  return "F6";
            case Key::F7:  return "F7";
            case Key::F8:  return "F8";
            case Key::F9:  return "F9";
            case Key::F10: return "F10";
            case Key::F11: return "F11";
            case Key::F12: return "F12";

            default:
                return "Unknown Key";
        }
    }

    std::string Input::MouseButtonToString(MouseButton button) {
        switch (button) {
            case MouseButton::Left:   return "Left Mouse Button";
            case MouseButton::Right:  return "Right Mouse Button";
            case MouseButton::Middle: return "Middle Mouse Button";

            case MouseButton::Button3: return "Mouse Button 4";
            case MouseButton::Button4: return "Mouse Button 5";
            case MouseButton::Button5: return "Mouse Button 6";
            case MouseButton::Button6: return "Mouse Button 7";
            case MouseButton::Button7: return "Mouse Button 8";

            default:
                return "Unknown Mouse Button";
        }
    }
}