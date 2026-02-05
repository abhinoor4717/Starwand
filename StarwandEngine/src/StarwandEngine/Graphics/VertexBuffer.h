#pragma once

#include <cstdint>
#include <memory>

#include "BufferLayout.h"

namespace Starwand {

    enum class BufferUsage {
        Static,
        Dynamic
    };

    class VertexBuffer {
    public:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;    

        virtual void SetData(const void* data, uint32_t size, BufferUsage usage) = 0;

        virtual const BufferLayout& GetLayout() const = 0;
        virtual void SetLayout(const BufferLayout& layout) = 0;
    
        static std::shared_ptr<VertexBuffer> Create(
            const void* data,
            uint32_t size,
            BufferUsage usage
        );
    };
}