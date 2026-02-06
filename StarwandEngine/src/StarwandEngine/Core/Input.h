#pragma once

#include <glm/glm.hpp>
#include "Core/Key.h"
#include "Core/MouseButton.h"
#include <string>

namespace Starwand {
    
    class Input {
    public:
        static bool IsKeyDown(Key key);
        static bool IsKeyUp(Key key);
        
        static glm::vec2 GetMousePosition();
        static bool IsMouseButtonDown(MouseButton mb);
        static bool IsMouseButtonUp(MouseButton mb);

        static std::string KeyToString(Key key);
        static std::string MouseButtonToString(MouseButton mb);
    };
}