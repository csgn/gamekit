#ifndef GAMEKIT_INCLUDE_GAMEKIT_COMMON_API_H
#define GAMEKIT_INCLUDE_GAMEKIT_COMMON_API_H

#include "gamekit/copyright.h"

#ifdef _WIN32
	#if defined(GAMEKIT_EXPORTS)
		#define GAMEKIT_API extern "C" __declspec(dllexport)
	#else
		#define GAMEKIT_API extern "C" __declspec(dllimport)
	#endif
#elif defined(__GNUC__)
	#if defined(GAMEKIT_EXPORTS)
		#define GAMEKIT_API extern "C" __attribute__((visibility("default")))
	#else
		#define GAMEKIT_API extern "C"
	#endif
#else
	#if defined(GAMEKIT_EXPORTS)
		#define GAMEKIT_API extern "C"
	#else
		#define GAMEKIT_API extern "C"
	#endif
#endif

#ifdef _WIN32
	#define CALL_TYPE __cdecl
#else
	#define CALL_TYPE
#endif

#endif // GAMEKIT_INCLUDE_GAMEKIT_COMMON_API_H
