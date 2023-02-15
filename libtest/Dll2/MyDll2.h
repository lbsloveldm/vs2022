#pragma once

#include <iostream>
#include <windows.h>


#define __DLL_EXPORTS__
#ifdef __DLL_EXPORTS__
#define DLLAPI  __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

/*
*   https://learn.microsoft.com/en-us/windows/win32/dlls/creating-a-simple-dynamic-link-library
*/

#ifdef __cplusplus    // If used by C++ code, 
extern "C" {          // we need to export the C interface
#endif


__declspec(dllexport) void __cdecl  dll2Func();

#ifdef __cplusplus
}
#endif