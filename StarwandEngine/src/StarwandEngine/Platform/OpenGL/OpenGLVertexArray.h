#pragma once

#include "Graphics/VertexArray.h"

namespace Starwand {
    class OpenGLVertexArray : public VertexArray {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray();

        void Bind() const override;
        void Unbind() const override;

        void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vb) override;
        void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& ib) override;

        const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override;
        const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override;

    private:
        uint32_t m_rendererId;
        std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
        uint32_t m_vertexBufferIndex = 0;
        std::shared_ptr<IndexBuffer> m_indexBuffer;
    };
}