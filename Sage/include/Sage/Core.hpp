#pragma once

#ifdef SAGE_PLATFORM_WINDOWS
	#ifdef SAGE_BUILD_DLL
		#define SAGE_API __declspec(dllexport)
	#else
		#define SAGE_API __declspec(dllimport)
	#endif
#else
	#error Sage only supports Windows for now!
#endif

#ifdef SAGE_ENABLE_ASSERTS
	#define SAGE_ASSERT(x, ...) {if(!(x)) {SAGE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define SAGE_CORE_ASSERT(x, ...) {if(!(x)) {SAGE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
#else 
	#define SAGE_ASSERT(x, ...)
	#define SAGE_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)
