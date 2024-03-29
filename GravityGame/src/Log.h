#pragma once

#include <spdlog/spdlog.h>

class Log {
public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& getLogger() { return s_logger; }

private:
	static std::shared_ptr<spdlog::logger> s_logger;
};

// MACROS 
#ifdef _DEBUG
#define LOG_TRACE(...)	Log::getLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)	Log::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)	Log::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)	Log::getLogger()->error(__VA_ARGS__)
#else
#define LOG_TRACE
#define LOG_INFO
#define LOG_WARN
#define LOG_ERROR
#endif
// --------------
