#pragma once

#include "Core/Core.h"
#include "Graphics/Shader.h"

namespace Starwand {
    class SW_API Renderer {
    public:
        static void Init();

        static void SetClearColor(float r, float g, float b, float a);
        static void Clear();

        static void DrawRect();

    private:
        static std::shared_ptr<Shader> s_DefaultShader;
    };
}