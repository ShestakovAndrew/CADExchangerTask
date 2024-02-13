#pragma once

#ifdef CURVESLIBRARY_EXPORTS
#define CURVESLIBRARY_API __declspec(dllexport)
#else
#define CURVESLIBRARY_API __declspec(dllimport)
#endif

extern "C" CURVESLIBRARY_API void fibonacci_init(
	const unsigned long long a, const unsigned long long b);

extern "C" CURVESLIBRARY_API bool fibonacci_next();

extern "C" CURVESLIBRARY_API unsigned long long fibonacci_current();

extern "C" CURVESLIBRARY_API unsigned fibonacci_index();