#pragma once
#include "Core.hpp"
#include "spdlog/spdlog.h"
#include <memory>

namespace Sage {

	class SAGE_API Log
	{
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();

		inline static std::shared_ptr < spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr < spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}
//TODO put a guard so we don't ship logging - Dev Only
#define SAGE_CORE_ERROR(...) ::Sage::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SAGE_CORE_WARN(...)  ::Sage::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SAGE_CORE_INFO(...)  ::Sage::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SAGE_CORE_TRACE(...) ::Sage::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SAGE_CORE_FATAL(...) ::Sage::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define SAGE_ERROR(...) ::Sage::Log::GetClientLogger()->error(__VA_ARGS__)
#define SAGE_WARN(...)  ::Sage::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SAGE_INFO(...)  ::Sage::Log::GetClientLogger()->info(__VA_ARGS__)
#define SAGE_TRACE(...) ::Sage::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SAGE_FATAL(...) ::Sage::Log::GetClientLogger()->fatal(__VA_ARGS__)
