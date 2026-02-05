#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <glad/glad.h>

namespace Starwand {
    enum class ShaderDataType {
        Int, Int2, Int3, Int4,
        Float, Float2, Float3, Float4,
        Bool
    };

    static uint32_t ShaderDataTypeSize(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::Int:       return 4;
            case ShaderDataType::Int2:       return 4 * 2;
            case ShaderDataType::Int3:       return 4 * 3;
            case ShaderDataType::Int4:       return 4 * 4;

            case ShaderDataType::Float:       return 4;
            case ShaderDataType::Float2:       return 4 * 2;
            case ShaderDataType::Float3:       return 4 * 3;
            case ShaderDataType::Float4:       return 4 * 4;

            case ShaderDataType::Bool:       return 1;
        }
        
        return 0;
    }

    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::Float:
            case ShaderDataType::Float2:
            case ShaderDataType::Float3:
            case ShaderDataType::Float4:
                return GL_FLOAT;

            case ShaderDataType::Int:
            case ShaderDataType::Int2:
            case ShaderDataType::Int3:
            case ShaderDataType::Int4:
                return GL_INT;

            case ShaderDataType::Bool:
                return GL_BOOL;
        }

        return 0;
    }

    struct BufferElement {
        std::string Name;
        ShaderDataType Type;
        uint32_t Size;
        uint32_t Offset;
        bool Normalized;
        
        BufferElement(ShaderDataType type, const std::string& name, bool normalized)
            : Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized) {}

        uint32_t GetComponentCount() const {
            switch (Type) {
                case ShaderDataType::Float:     return 1;
                case ShaderDataType::Float2:    return 2;
                case ShaderDataType::Float3:    return 3;
                case ShaderDataType::Float4:    return 4;

                case ShaderDataType::Int:       return 1;
                case ShaderDataType::Int2:      return 2;
                case ShaderDataType::Int3:      return 3;
                case ShaderDataType::Int4:      return 4;

                case ShaderDataType::Bool:      return 1;   
            }

            return 0;
        }
    };

    class BufferLayout {
    public:
        BufferLayout() = default;

        BufferLayout(std::initializer_list<BufferElement> elements)
            : m_elements(elements) {
                CalculateOffsetsAndStride();
        }
        
        uint32_t GetStride() const { return m_stride; }
        const std::vector<BufferElement>& GetElements() const { return m_elements; }
        
    private:
        void CalculateOffsetsAndStride() {
            uint32_t offset = 0;
            m_stride = 0;

            for (auto& elm : m_elements) {
                elm.Offset = offset;
                offset += elm.Size;
                m_stride += elm.Size;
            }
        }
    
    private:
        std::vector<BufferElement> m_elements;
        uint32_t m_stride;
    };
}