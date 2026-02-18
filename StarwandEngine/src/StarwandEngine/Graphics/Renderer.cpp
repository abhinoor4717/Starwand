#include "Renderer.h"
#include  "GraphicsAPI.h"
#include <glad/glad.h>
#include "Core/Log.h"
#include "Core/Exceptions.h"

#include "Graphics/VertexArray.h"

#include <fstream>
#include <string>
#include <iterator>
#include <iostream>

namespace Starwand {
    std::shared_ptr<Shader> Renderer::s_DefaultShader = nullptr;

    void Renderer::Init() {
        // TODO: Add dynamic support for multiple graphics api

        std::ifstream vFile(SW_RESOURCES_DIR "/Shaders/vertex.glsl");
        if (!vFile)
            SWE_FATAL("Could not open default vertex shader!");

        std::string vertexSource(
            (std::istreambuf_iterator<char>(vFile)),
            std::istreambuf_iterator<char>()
        );

        std::ifstream fFile(SW_RESOURCES_DIR "/Shaders/fragment.glsl");
        if (!fFile)
            SWE_FATAL("Could not open default fragment shader!");

        std::string fragmentSource(
            (std::istreambuf_iterator<char>(fFile)),
            std::istreambuf_iterator<char>()
        );

        try {
            s_DefaultShader = Shader::Create(vertexSource, fragmentSource);
        }
        catch (const ShaderException& e) {
            SWE_ERROR(e.what());
        }
    }

    void Renderer::SetClearColor(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
    }

    void Renderer::Clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::DrawRect() {
        float vertices[] = {
            -0.5f, -0.5f, // Bottom Left
            0.5f, -0.5f,  // Bottom Right
            0.5f, 0.5f,    // Top right
            -0.5f, 0.5f  // Top left
        };

        uint32_t indices[] = {
            0, 1, 2,
            0, 2, 3
        };

        auto va = VertexArray::Create();
        auto vb = VertexBuffer::Create(vertices, sizeof(vertices), BufferUsage::Static);
        auto ib = IndexBuffer::Create(indices, sizeof(indices));
        vb->SetLayout(BufferLayout({
            BufferElement(ShaderDataType::Float2, "position",  false)
        }));
        va->AddVertexBuffer(vb);
        va->SetIndexBuffer(ib);
        va->Bind();
        s_DefaultShader->Bind();

        glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, nullptr);
    }
}