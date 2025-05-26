#pragma once
#include <cassert>

#define TORNASOL_ASSERT(x) assert(x)

#if !defined(TORNASOL_EXPORT)
    #if defined(TORNASOL_SHARED)
        #if defined(_WIN32)
            #if defined(_TORNASOL_BUILD_SHARED)
                #define TORNASOL_EXPORT __declspec(dllexport)
            #else
                #define TORNASOL_EXPORT __declspec(dllimport)
            #endif
        #else
            #define TORNASOL_EXPORT __attribute__((visibility("default")))
        #endif
    #else
        #define TORNASOL_EXPORT
    #endif
#endif