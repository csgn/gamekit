#ifndef GAMEKIT_API_COMMON_H
#define GAMEKIT_API_COMMON_H
#pragma once

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

#define CALL_TYPE __cdecl

#endif	// GAMEKIT_API_COMMON_H
