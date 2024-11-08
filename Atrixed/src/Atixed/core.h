#pragma once

#ifdef AX_PLATFORM_WINDOWS

	#ifdef AX_BUILD_DLL
			#define ATRIXED_API  __declspec(dllexport)
	#else 
			#define ATRIXED_API  __declspec(dllimport)
	#endif

#else
	#error Atrixed Only Support Windows

#endif 

