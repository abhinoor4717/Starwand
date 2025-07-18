#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Starwand {
    class STARWAND_API Logger {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#ifdef SW_DEBUG
    // Core log macros
    #define SW_CORE_TRACE(...)    ::Starwand::Logger::GetCoreLogger()->trace(__VA_ARGS__)
    #define SW_CORE_INFO(...)     ::Starwand::Logger::GetCoreLogger()->info(__VA_ARGS__)
    #define SW_CORE_WARN(...)     ::Starwand::Logger::GetCoreLogger()->warn(__VA_ARGS__)
    #define SW_CORE_ERROR(...)    ::Starwand::Logger::GetCoreLogger()->error(__VA_ARGS__)
    #define SW_CORE_FATAL(...)    ::Starwand::Logger::GetCoreLogger()->critical(__VA_ARGS__)

    // Client log macros
    #define SW_TRACE(...)	      ::Starwand::Logger::GetClientLogger()->trace(__VA_ARGS__)
    #define SW_INFO(...)	      ::Starwand::Logger::GetClientLogger()->info(__VA_ARGS__)
    #define SW_WARN(...)	      ::Starwand::Logger::GetClientLogger()->warn(__VA_ARGS__)
    #define SW_ERROR(...)	      ::Starwand::Logger::GetClientLogger()->error(__VA_ARGS__)
    #define SW_FATAL(...)	      ::Starwand::Logger::GetClientLogger()->critical(__VA_ARGS__)

#else

    #define SW_CORE_TRACE(...)    
    #define SW_CORE_INFO(...)     
    #define SW_CORE_WARN(...)     
    #define SW_CORE_ERROR(...)    
    #define SW_CORE_FATAL(...)    

    // Client log macros
    #define SW_TRACE(...)	      
    #define SW_INFO(...)	      
    #define SW_WARN(...)	      
    #define SW_ERROR(...)	      
    #define SW_FATAL(...)	      

#endif
