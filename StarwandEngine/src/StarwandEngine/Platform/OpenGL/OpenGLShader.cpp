#include "Platform/OpenGL/OpenGLShader.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <iterator>
#include <stdexcept>

#include "Core/Log.h"
#include "Core/Exceptions.h"

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
            throw InvalidVertexShaderException("Invalid vertex shader source: \n" + std::string(log));
        }

        GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
        const char* fragmentRawSrc = fragSrc.c_str();
        glShaderSource(fs, 1, &fragmentRawSrc, nullptr);
        glCompileShader(fs);
        glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
        if (!success) {
            char log[1024];
            glGetShaderInfoLog(fs, 1024, nullptr, log);
            throw InvalidFragmentShaderException("Invalid fragment shader source: \n" + std::string(log));
        }

        m_rendererId = glCreateProgram();
        glAttachShader(m_rendererId, vs);
        glAttachShader(m_rendererId, fs);
        glLinkProgram(m_rendererId);
        glGetProgramiv(m_rendererId, GL_LINK_STATUS, &success);
        if (!success) {
            char log[1024];
            glGetProgramInfoLog(m_rendererId, 1024, nullptr, log);
            throw ShaderLinkException("Shader could not link: \n" + std::string(log));
        }

        glDeleteShader(vs);
        glDeleteShader(fs);
    }

    OpenGLShader::~OpenGLShader() {
        glDeleteProgram(m_rendererId);
    }

    void OpenGLShader::Bind() const {
        glUseProgram(m_rendererId);
    }

    void OpenGLShader::Unbind() const {
        glUseProgram(0);
    }

    void OpenGLShader::SetInt(const std::string& name, int val) {
        GLuint loc = glGetUniformLocation(m_rendererId, name.c_str());
        if (loc == -1) {
            throw InvalidShaderUniformException("Could not find uniform with name: " + name);
        }

        glUniform1i(loc, val);
    }
    void OpenGLShader::SetFloat(const std::string& name, float val) {
        GLuint loc = glGetUniformLocation(m_rendererId, name.c_str());
        if (loc == -1) {
            throw InvalidShaderUniformException("Could not find uniform with name: " + name);
        }

        glUniform1f(loc, val);
    }
    void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& value) {
        GLuint loc = glGetUniformLocation(m_rendererId, name.c_str());
        if (loc == -1) {
            throw InvalidShaderUniformException("Could not find uniform with name: " + name);
        }

        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
    }
}