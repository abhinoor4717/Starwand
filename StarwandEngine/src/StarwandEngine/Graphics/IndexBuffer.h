#pragma once

#include <cstdint>
#include <memory>

namespace Starwand {
    class IndexBuffer {
    public:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void SetData(const uint32_t* data, uint32_t size) = 0;

        virtual uint32_t GetCount() const = 0;

        static std::shared_ptr<IndexBuffer> Create(
            const uint32_t* indices,
            uint32_t count
        );
    };
}