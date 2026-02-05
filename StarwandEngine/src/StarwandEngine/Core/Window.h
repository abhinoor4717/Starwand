#pragma once

#include <cstdint>
#include <string>
#include <memory>

namespace Starwand {
    class Window {
    public:
        ~Window() = default;

        virtual uint32_t GetWidth() const;
        virtual uint32_t GetHeight() const;

        virtual std::string GetTitle() const;

        static std::shared_ptr<Window> Create(const std::string& title, uint32_t width, uint32_t height);
    };
}