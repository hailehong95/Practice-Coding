// SignLibrary.h - Contains declarations of math functions
// Ref: https://docs.microsoft.com/en-us/windows/win32/seccrypto/example-c-program--verifying-the-signature-of-a-pe-file
#pragma once

#define _UNICODE 1
#define UNICODE 1

#ifdef SIGNLIBRARY_EXPORTS
#define SIGNLIBRARY_API __declspec(dllexport)
#else
#define SIGNLIBRARY_API __declspec(dllimport)
#endif

extern "C" SIGNLIBRARY_API unsigned int signed_check(LPCWSTR pwszSourceFile);
