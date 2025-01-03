#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Atrixed {
	class ATRIXED_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core Loger
#define AX_CORE_TRACE(...)			::Atrixed::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define AX_CORE_WARN(...)			::Atrixed::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define AX_CORE_INFO(...)			::Atrixed::Log::GetCoreLogger()->info(__VA_ARGS__);
#define AX_CORE_ERROR(...)			::Atrixed::Log::GetCoreLogger()->error(__VA_ARGS__);
#define AX_CORE_FLUSH(...)			::Atrixed::Log::GetCoreLogger()->flush();

// Client Loger
#define AX_CLIENT_TRACE(...)			::Atrixed::Log::GetClientLogger()->trace(__VA_ARGS__);
#define AX_CLIENT_WARN(...)			::Atrixed::Log::GetClientLogger()->warn(__VA_ARGS__);
#define AX_CLIENT_INFO(...)				::Atrixed::Log::GetClientLogger()->info(__VA_ARGS__);
#define AX_CLIENT_ERROR(...)			::Atrixed::Log::GetClientLogger()->error(__VA_ARGS__);
#define AX_CLIENT_FLUSH()			::Atrixed::Log::GetClientLogger()->flush();


