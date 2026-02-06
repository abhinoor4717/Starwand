#include "IndexBuffer.h"
#include "GraphicsAPI.h"

#include "Platform/OpenGL/OpenGLIndexBuffer.h"
#include "Core/Log.h"

namespace Starwand {

    std::shared_ptr<IndexBuffer> IndexBuffer::Create(const uint32_t* data, uint32_t size) {
        switch (GraphicsAPI::GetAPI()) {
            case GraphicsAPI::API::OpenGL:
                return std::make_shared<OpenGLIndexBuffer>(data, size);
        }

        SWE_FATAL("Unknown GraphicsAPI!");
        return nullptr;
    }

}
