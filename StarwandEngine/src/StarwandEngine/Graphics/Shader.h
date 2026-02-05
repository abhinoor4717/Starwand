#pragma once

#include <string>
#include <memory>
#include <glm/glm.hpp>

namespace Starwand {
    class Shader {
    public:
        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void SetInt(const std::string& name, int val) = 0;
        virtual void SetFloat(const std::string& name, float val) = 0;
        virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;

        static std::shared_ptr<Shader> Create(const std::string& vertSrc, const std::string& fragSrc);
    };
}