#include "Window.h"

#ifdef SW_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.h"
#endif

#include "Log.h"

namespace Starwand {
    std::shared_ptr<Window> Window::Create(const std::string& title, uint32_t width, uint32_t height) {
        #ifdef SW_PLATFORM_WINDOWS
            return std::make_shared<WindowsWindow>(title, width, height);
        #endif
        SWE_FATAL("Only windows is supported!");
        exit(-1);
    }
}