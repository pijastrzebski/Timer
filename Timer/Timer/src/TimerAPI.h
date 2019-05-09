#pragma once

#ifdef TIMER_BUILD_DLL
#define TIMER_API __declspec(dllexport)
#else
#define TIMER_API __declspec(dllimport)
#endif
