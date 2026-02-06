#include "Core/Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Starwand {
    std::shared_ptr<spdlog::logger> Log::s_engineLogger;
    std::shared_ptr<spdlog::logger> Log::s_appLogger;

    void Log::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        consoleSink->set_pattern("%^[%T] %n: %v%$");

        auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
            "Starwand.log", true
        );

        std::vector<spdlog::sink_ptr> sinks{ consoleSink, fileSink };

        s_engineLogger = std::make_shared<spdlog::logger>("ENGINE", sinks.begin(), sinks.end());
        s_appLogger    = std::make_shared<spdlog::logger>("APP", sinks.begin(), sinks.end());

        spdlog::register_logger(s_engineLogger);
        spdlog::register_logger(s_appLogger);

        s_engineLogger->set_level(spdlog::level::trace);
        s_appLogger->set_level(spdlog::level::trace);
    }
}