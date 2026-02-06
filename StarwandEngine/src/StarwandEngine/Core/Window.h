#pragma once

#include <cstdint>
#include <string>
#include <memory>

namespace Starwand {
    class Window {
    public:
        ~Window() = default;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        virtual std::string GetTitle() const = 0;
        virtual void* GetNativeWindow() const = 0;

        static std::shared_ptr<Window> Create(const std::string& title, uint32_t width, uint32_t height);
    };
}