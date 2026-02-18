#include "Renderer.h"
#include  "GraphicsAPI.h"
#include <glad/glad.h>

#include "Graphics/VertexArray.h"

namespace Starwand {
    void Renderer::Init() {
        // TODO: Add dynamic support for multiple graphics api
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

        glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, nullptr);
    }
}