#pragma once

#include <memory>
#include <spdlog/spdlog.h>

namespace Starwand {
    class Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_engineLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return s_appLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_engineLogger;
        static std::shared_ptr<spdlog::logger> s_appLogger;
    };
}

// Engine
#define SWE_TRACE(...) ::Starwand::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define SWE_INFO(...)  ::Starwand::Log::GetEngineLogger()->info(__VA_ARGS__)
#define SWE_WARN(...)  ::Starwand::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define SWE_ERROR(...) ::Starwand::Log::GetEngineLogger()->error(__VA_ARGS__)
#define SWE_FATAL(...) ::Starwand::Log::GetEngineLogger()->critical(__VA_ARGS__)

// App
#define SW_TRACE(...) ::Starwand::Log::GetAppLogger()->trace(__VA_ARGS__)
#define SW_INFO(...)  ::Starwand::Log::GetAppLogger()->info(__VA_ARGS__)
#define SW_WARN(...)  ::Starwand::Log::GetAppLogger()->warn(__VA_ARGS__)
#define SW_ERROR(...) ::Starwand::Log::GetAppLogger()->error(__VA_ARGS__)
#define SW_FATAL(...) ::Starwand::Log::GetAppLogger()->critical(__VA_ARGS__)