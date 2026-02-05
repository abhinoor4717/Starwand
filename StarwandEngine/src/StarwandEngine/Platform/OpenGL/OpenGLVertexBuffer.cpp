#include "OpenGLVertexBuffer.h"

#include <stdexcept>

#include <glad/glad.h>

namespace Starwand {
    OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, uint32_t size, BufferUsage usage) {
        glGenBuffers(1, &m_rendererId);
        Bind();
        SetData(data, size, usage);
        Unbind();
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer() {
        glDeleteBuffers(1, &m_rendererId);
    }

    void OpenGLVertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_rendererId);
    }

    void OpenGLVertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLVertexBuffer::SetData(const void* data, uint32_t size, BufferUsage usage) {
        Bind();
        
        switch (usage) {
            case BufferUsage::Static:       glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW); break;
            case BufferUsage::Dynamic:      glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW); break;
        }
    }

    const BufferLayout& OpenGLVertexBuffer::GetLayout() const {
        return m_layout;
    }

    void OpenGLVertexBuffer::SetLayout(const BufferLayout& layout) {
        m_layout = layout;
    }
}