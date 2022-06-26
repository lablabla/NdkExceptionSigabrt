#pragma once

#ifdef EXPORT_DEFAULT_VISIBILITY
#define		DLL_EXPORT __attribute__((__visibility__("default")))
#else
#define		DLL_EXPORT
#endif