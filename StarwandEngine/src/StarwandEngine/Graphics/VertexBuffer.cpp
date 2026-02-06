#include "VertexBuffer.h"
#include "Platform/OpenGL/OpenGLVertexBuffer.h"

#include "Core/Log.h"
#include "GraphicsAPI.h"

namespace Starwand {
    std::shared_ptr<VertexBuffer> VertexBuffer::Create(const void* data, uint32_t size, BufferUsage usage) {
        switch (GraphicsAPI::GetAPI()) {
            case GraphicsAPI::API::OpenGL:
                return std::make_shared<OpenGLVertexBuffer>(data, size, usage);
        }

        SWE_FATAL("Unknown GraphicsAPI!");
        return nullptr;
    }
}