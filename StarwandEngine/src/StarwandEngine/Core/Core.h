#pragma once

#ifdef SW_PLATFORM_WINDOWS
    #ifdef SW_BUILD_DLL
        #define SW_API __declspec(dllexport)
    #else
        #define SW_API __declspec(dllimport)
    #endif

#else
    #define SW_API
#endif
