#include "Graphics/Shader.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace Starwand {
    std::shared_ptr<Shader> Shader::Create(const std::string& vertSrc, const std::string& fragSrc) {
        return std::make_shared<OpenGLShader>(vertSrc, fragSrc);
    }
}