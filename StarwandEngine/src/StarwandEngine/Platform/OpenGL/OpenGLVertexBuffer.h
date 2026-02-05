#pragma once

#include "Graphics/VertexBuffer.h"

namespace Starwand {
    class OpenGLVertexBuffer : public VertexBuffer {
    public:
        OpenGLVertexBuffer(const void* data, uint32_t size, BufferUsage usage);
        ~OpenGLVertexBuffer();

        void Bind() const override;
        void Unbind() const override;
        void SetData(const void* data, uint32_t size, BufferUsage usage) override;

        const BufferLayout& GetLayout() const override;
        void SetLayout(const BufferLayout& layout) override;

    private:
        uint32_t m_rendererId;
        BufferLayout m_layout;
    };
}