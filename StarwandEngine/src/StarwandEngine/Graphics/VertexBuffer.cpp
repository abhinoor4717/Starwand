#include "VertexBuffer.h"
#include "Platform/OpenGL/OpenGLVertexBuffer.h"

namespace Starwand {
    std::shared_ptr<VertexBuffer> VertexBuffer::Create(const void* data, uint32_t size, BufferUsage usage) {
        // Defaults to OpenGL implementation for now
        return std::make_shared<OpenGLVertexBuffer>(data, size, usage);
    }
}