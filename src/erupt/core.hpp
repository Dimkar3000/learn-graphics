#ifdef ERUPT_PLATFORM_WINDOWS
#ifdef ERUPT_BUILD_DLL
#define ERUPT_API __declspec(dllexport)
#else
#define ERUPT_API __declspec(dllimport)
#endif
#else
#error "Only Windows for now"
#endif