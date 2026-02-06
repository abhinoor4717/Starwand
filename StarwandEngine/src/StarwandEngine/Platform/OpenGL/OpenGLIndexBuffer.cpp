#include "Platform/OpenGL/OpenGLIndexBuffer.h"

#include <glad/glad.h>

namespace Starwand {
    OpenGLIndexBuffer::OpenGLIndexBuffer(const uint32_t* data, uint32_t size) : m_count(size / sizeof(uint32_t)) {
        glGenBuffers(1, &m_rendererId);
        Bind();
        SetData(data, size);
        Unbind();
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer() {
        glDeleteBuffers(1, &m_rendererId);
    }

    void OpenGLIndexBuffer::Bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererId);
    }
    
    void OpenGLIndexBuffer::Unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void OpenGLIndexBuffer::SetData(const uint32_t* data, uint32_t size) {
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    uint32_t OpenGLIndexBuffer::GetCount() const {
        return m_count;
    }
}