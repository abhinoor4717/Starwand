#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <functional>
#include "Events/Events.h"

namespace Starwand {
    class Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        ~Window() = default;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        virtual std::string GetTitle() const = 0;
        virtual void* GetNativeWindow() const = 0;
        
        virtual void SetEventCallback(EventCallbackFn callback) = 0;

        virtual void Update() = 0;

        static std::shared_ptr<Window> Create(const std::string& title, uint32_t width, uint32_t height);

        struct WindowData {
            std::string Title;
            uint32_t Width, Height;
            EventCallbackFn EventCallback;
        };
    };
}