#pragma once

#include "Core.h"
#include <raylib.h>

namespace Starwand {

    class STARWAND_API Renderer {
    public:
        static void Clear(::Color color = BLACK);

        static void DrawLine(::Vector2 startPos, ::Vector2 endPos, ::Color color = WHITE);

        static void DrawRectangle(::Rectangle rect, ::Color color = WHITE);
        static void DrawRectangleLines(::Rectangle rect, ::Color color = WHITE);

        static void DrawCircle(::Vector2 center, float radius, ::Color color = WHITE);
        static void DrawCircleLines(::Vector2 center, float radius, ::Color color = WHITE);

        static void DrawTriangle(::Vector2 v1, ::Vector2 v2, ::Vector2 v3, ::Color color = WHITE);
        static void DrawTriangleLines(::Vector2 v1, ::Vector2 v2, ::Vector2 v3, ::Color color = WHITE);

        static void DrawText(const std::string& text, ::Vector2 pos, int fontSize, ::Color color = WHITE);
    };
}