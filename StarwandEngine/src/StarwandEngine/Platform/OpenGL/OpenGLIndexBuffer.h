#pragma once

#include "Graphics/IndexBuffer.h"

namespace Starwand {
    class OpenGLIndexBuffer : public IndexBuffer {
    public:
        OpenGLIndexBuffer(const uint32_t* data, uint32_t size);
        ~OpenGLIndexBuffer();
        
        void Bind() const override;
        void Unbind() const override;
        
        void SetData(const uint32_t* data, uint32_t size) override;

        uint32_t GetCount() const override;

    private:
        uint32_t m_rendererId;
        uint32_t m_count;
    };
}