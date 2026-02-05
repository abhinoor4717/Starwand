#include "IndexBuffer.h"
#include "Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Starwand {
    std::shared_ptr<IndexBuffer> IndexBuffer::Create(const uint32_t* data, uint32_t size) {
        // Defaults to OpenGL implmentation for now
        return std::make_shared<OpenGLIndexBuffer>(data, size);
    }
}