#pragma once

#include "Core.h"
#include <iostream>
#include <string>

#include <spdlog/fmt/ostr.h>

namespace Starwand {

    enum class STARWAND_API EventType {
        None,
        WindowClosed, WindowMaximized, WindowMinimized, WindowResized, WindowFocusGained, WindowFocusLost,
        KeyPressed, KeyReleased, KeyDown, KeyUp,
        MouseButtonPressed, MouseButtonReleased, MouseButtonDown, MouseButtonUp, MouseMoved, MouseWheel
    };

    class STARWAND_API Event {
    public:
        inline virtual EventType GetEventType() const = 0;
        inline virtual std::string ToString() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Event& event);
    public:
        bool Handled = false;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& event) {
        return os << event.ToString();
    }

    template <typename T>
    inline T* ConvertEvent(Event& e) {
        if (e.GetEventType() == T::GetStaticType()) {
            return dynamic_cast<T*>(&e);
        }
        return nullptr;
    }
    
}

template <>
struct fmt::formatter<Starwand::Event> {
    constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

    template <typename FormatContext>
    auto format(const Starwand::Event& e, FormatContext& ctx) const {
        return format_to(ctx.out(), "{}", e.ToString());
    }
};
