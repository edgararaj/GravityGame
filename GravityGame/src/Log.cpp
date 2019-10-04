#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Log::s_logger;

void Log::Init() {
	spdlog::set_pattern("%^[%T] %n: %v%$");

	s_logger = spdlog::stdout_color_mt("Game");
	s_logger->set_level(spdlog::level::trace);

	LOG_INFO("spdlog initialized");
}
