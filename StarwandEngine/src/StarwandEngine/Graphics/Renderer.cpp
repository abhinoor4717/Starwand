#include "Core/Exceptions.h"
#include "Core/Log.h"
#include  "GraphicsAPI.h"
#include "Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Graphics/VertexArray.h"
#include "Graphics/Texture2D.h"

#include "Graphics/RenderCommand.h"

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

namespace Starwand {
    std::shared_ptr<Shader> Renderer::s_DefaultShader = nullptr;

    std::shared_ptr<Texture2D> texture = nullptr;

    void Renderer::Init() {
        
        GraphicsAPI::Initalize();

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

        texture = Texture2D::Create(SW_RESOURCES_DIR "/images/sample.png");
    }

    void Renderer::SetClearColor(float r, float g, float b, float a) {
        RenderCommand::SetClearColor(r, g, b, a);
    }

    void Renderer::Clear() {
        RenderCommand::Clear();
    }

    void Renderer::DrawRect() {
        static float vertices[] = {
            // Position                 Color                   UV          UseTex
            -0.5f, -0.5f, 1.0f,     1.0f, 0.0f, 0.0f,       0.0f, 0.0f,     1.0f,      // Bottom Left
            0.5f, -0.5f, 1.0f,      0.0f, 1.0f, 0.0f,       1.0f, 0.0f,     1.0f,      // Bottom Right
            0.5f, 0.5f, 1.0f,       0.0f, 0.0f, 1.0f,       1.0f, 1.0f,     1.0f,      // Top right
            -0.5f, 0.5f, 1.0f,      1.0f, 1.0f, 1.0f,       0.0f, 1.0f,     1.0f,      // Top left
        };

        static uint32_t indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        static auto va = VertexArray::Create();
        static auto vb = VertexBuffer::Create(vertices, sizeof(vertices), BufferUsage::Static);
        static auto ib = IndexBuffer::Create(indices, sizeof(indices));
        vb->SetLayout(BufferLayout({
            BufferElement(ShaderDataType::Float3, "Position",  false),
            BufferElement(ShaderDataType::Float3, "Color",  false),
            BufferElement(ShaderDataType::Float2, "UV",  false),
            BufferElement(ShaderDataType::Float, "UseTexture",  false),

        }));
        va->AddVertexBuffer(vb);
        va->SetIndexBuffer(ib);
        s_DefaultShader->Bind();
        
        glActiveTexture(GL_TEXTURE0);
        texture->Bind();

        s_DefaultShader->SetInt("sampler", 0);

        RenderCommand::DrawIndexed(va);
    }
}