#include "Platform/OpenGL/OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Starwand {
    OpenGLVertexArray::OpenGLVertexArray() {
        glGenVertexArrays(1, &m_rendererId);
    }

    OpenGLVertexArray::~OpenGLVertexArray() {
        glDeleteVertexArrays(1, &m_rendererId);
    }

    void OpenGLVertexArray::Bind() const {
        glBindVertexArray(m_rendererId);
    }

    void OpenGLVertexArray::Unbind() const {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vb) {
        Bind();
        vb->Bind();

        const auto& layout = vb->GetLayout();

        for (const auto& elm : layout.GetElements()) {
            uint32_t index = m_vertexBufferIndex;
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(
                index,
                elm.GetComponentCount(),
                ShaderDataTypeToOpenGLBaseType(elm.Type),
                elm.Normalized ? GL_TRUE : GL_FALSE,
                layout.GetStride(),
                (const void*)(uintptr_t)elm.Offset
            );

            m_vertexBufferIndex++;
        }

        m_vertexBuffers.push_back(vb);
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& ib) {
        Bind();
        ib->Bind();

        m_indexBuffer = ib;
    }

    const std::vector<std::shared_ptr<VertexBuffer>>& OpenGLVertexArray::GetVertexBuffers() const {
        return m_vertexBuffers;
    }
    const std::shared_ptr<IndexBuffer>& OpenGLVertexArray::GetIndexBuffer() const {
        return m_indexBuffer;
    }

}