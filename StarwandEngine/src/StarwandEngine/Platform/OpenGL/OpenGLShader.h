#include "Graphics/Shader.h"

#include <cstdint>
#include <string>

namespace Starwand {
    class OpenGLShader : public Shader {
    public:
        OpenGLShader(const std::string& vertSrc, const std::string& fragSrc);
        ~OpenGLShader();

        void Bind() const override;
        void Unbind() const override;

        void SetInt(const std::string& name, int val) override;
        void SetFloat(const std::string& name, float val) override;
        void SetMat4(const std::string& name, const glm::mat4& value) override;

    private:
        uint32_t m_rendererId;
    };
}