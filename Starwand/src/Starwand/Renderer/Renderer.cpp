#include "swpch.h"

#include "Renderer.h"
namespace Starwand {
    void Renderer::Clear(::Color color) {
        ::ClearBackground(color);
    }

    void Renderer::DrawLine(::Vector2 startPos, ::Vector2 endPos, ::Color color) {
        ::DrawLineV(startPos, endPos, color);
    }

    void Renderer::DrawRectangle(::Rectangle rect, ::Color color) {
        ::DrawRectangleRec(rect, color);
    }
    void Renderer::DrawRectangleLines(::Rectangle rect, ::Color color) {
        ::DrawRectangleRec(rect, color);
    }

    void Renderer::DrawCircle(::Vector2 center, float radius, ::Color color) {
        ::DrawCircleV(center, radius, color);
    }
    void Renderer::DrawCircleLines(::Vector2 center, float radius, ::Color color) {
        ::DrawCircleLinesV(center, radius, color);
    }
    void Renderer::DrawTriangle(::Vector2 v1, ::Vector2 v2, ::Vector2 v3, ::Color color) {
        ::DrawTriangle(v1, v2, v3, color);
    }

    void Renderer::DrawTriangleLines(::Vector2 v1, ::Vector2 v2, ::Vector2 v3, ::Color color) {
        ::DrawTriangleLines(v1, v2, v3, color);
    }
    void Renderer::DrawText(const std::string &text, ::Vector2 pos, int fontSize, ::Color color) {
        ::DrawText(text.c_str(), pos.x, pos.y, fontSize, color);
    }
}