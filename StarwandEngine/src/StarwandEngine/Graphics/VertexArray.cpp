#include "VertexArray.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Starwand {
    std::shared_ptr<VertexArray> VertexArray::Create() {
        return std::make_shared<OpenGLVertexArray>();
    }
}