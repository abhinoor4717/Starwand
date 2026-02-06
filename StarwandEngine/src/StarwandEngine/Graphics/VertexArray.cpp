#include "VertexArray.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"
#include "GraphicsAPI.h"
#include "Core/Log.h"

namespace Starwand {
    std::shared_ptr<VertexArray> VertexArray::Create() {
        switch (GraphicsAPI::GetAPI()) {
            case GraphicsAPI::API::OpenGL:
                return std::make_shared<OpenGLVertexArray>();
        }
        
        SWE_FATAL("Unknown GraphicsAPI!");
        return nullptr;
    }
}