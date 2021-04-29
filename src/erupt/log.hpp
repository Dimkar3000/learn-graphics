#pragma once
#include "core.hpp"
#include "spdlog/spdlog.h"
#include <memory>
namespace Erupt
{
  class ERUPT_API Log
  {
  public:
    static void Init();
    inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };
}
#define ERUPT_CORE_ERROR(...) ::Erupt::Log::GetCoreLogger()->error(__VA_ARGS__);
#define ERUPT_CORE_WARN(...) ::Erupt::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define ERUPT_CORE_INFO(...) ::Erupt::Log::GetCoreLogger()->info(__VA_ARGS__);
#define ERUPT_CORE_TRACE(...) ::Erupt::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define ERUPT_CORE_FATAL(...) ::Erupt::Log::GetCoreLogger()->fatal(__VA_ARGS__);

#define ERUPT_ERROR(...) ::Erupt::Log::GetClientLogger()->error(__VA_ARGS__);
#define ERUPT_WARN(...) ::Erupt::Log::GetClientLogger()->warn(__VA_ARGS__);
#define ERUPT_INFO(...) ::Erupt::Log::GetClientLogger()->info(__VA_ARGS__);
#define ERUPT_TRACE(...) ::Erupt::Log::GetClientLogger()->trace(__VA_ARGS__);
#define ERUPT_FATAL(...) ::Erupt::Log::GetClientLogger()->fatal(__VA_ARGS__);
