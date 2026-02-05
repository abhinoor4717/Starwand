#include "OpenGLShader.h"

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <stdexcept>

namespace Starwand {
    OpenGLShader::OpenGLShader(const std::string& vertSrc, const std::string& fragSrc) {
        GLuint vs = glCreateShader(GL_VERTEX_SHADER);
        const char* vertexRawSrc = vertSrc.c_str();
        glShaderSource(vs, 1, &vertexRawSrc, nullptr);
        glCompileShader(vs);
        GLint success;
        glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
        if (!success) {
            char log[1024];
            glGetShaderInfoLog(vs, 1024, nullptr, log);

        }
    }

    OpenGLShader::~OpenGLShader() {
        
    }

    void OpenGLShader::Bind() const {

    }

    void OpenGLShader::Unbind() const {

    }

    void OpenGLShader::SetInt(const std::string& name, int val) {

    }
    void OpenGLShader::SetFloat(const std::string& name, float val) {

    }
    void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& value) {

    }
}