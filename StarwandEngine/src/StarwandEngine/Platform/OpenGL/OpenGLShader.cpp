#include "OpenGLShader.h"

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <stdexcept>

namespace Starwand {
    OpenGLShader::OpenGLShader(const std::string& vertPath, const std::string& fragPath) {
        std::ifstream vertFile(vertPath);
        if (!vertFile.is_open()) {
            throw std::runtime_error("Vertex shader not found at path: " + vertPath);
        }

        std::string vertSrc(std::istreambuf_iterator<char>(vertFile), std::istreambuf_iterator<char>());

        std::ifstream fragFile(vertPath);
        if (!fragFile.is_open()) {
            throw std::runtime_error("Fragment shader not found at path: " + vertPath);
        }

        std::string fragSrc(std::istreambuf_iterator<char>(vertFile), std::istreambuf_iterator<char>());
        const char* src = ;
        GLuint vs = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vs, 1, &src, nullptr);
        glCompileShader(vs);
    }
}