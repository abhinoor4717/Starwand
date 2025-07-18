#pragma once

#ifdef SW_PLATFORM_WINDOWS
    #ifdef SW_BUILD_DLL
        #define STARWAND_API __declspec(dllexport)
    #else
        #define STARWAND_API __declspec(dllimport)
    #endif
#elif defined(SW_PLATFORM_LINUX) || defined(SW_PLATFORM_MAC)
    #define STARWAND_API __attribute__ ((visibility ("default")))
#else
    #define STARWAND_API
#endif

#ifdef SW_ENABLE_ASSERTS
	#define SW_ASSERT(x, ...) { if(!(x)) { SW_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SW_CORE_ASSERT(x, ...) { if(!(x)) { SW_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SW_ASSERT(x, ...)
	#define SW_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)