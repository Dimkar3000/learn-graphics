#ifdef ERUPT_PLATFORM_WINDOWS
#ifdef ERUPT_BUILD_DLL
#define ERUPT_API __declspec(dllexport)
#else
#define ERUPT_API __declspec(dllimport)
#endif
#else
#error "Only Windows for now"
#endif

#ifdef ERUPT_ENABLE_ASSERTS
	#define ERUPT_ASSERT(x, ...) { if(!(x)) { ERUPT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ERUPT_CORE_ASSERT(x, ...) { if(!(x)) { ERUPT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ERUPT_ASSERT(x, ...)
	#define ERUPT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) 1 << x