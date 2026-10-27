#ifndef NWLIBC_INTERNAL_WINDOWS_SDK_H
#define NWLIBC_INTERNAL_WINDOWS_SDK_H

#include <stddef.h>

/* The MSVC SDK's stralign.h calls this CRT extension even when our own
 * string.h supplies the standard declarations. No implementation is added.
 */
#ifdef _MSC_VER
#ifdef __cplusplus
extern "C" {
#endif
__declspec(dllimport) int __cdecl _wcsicmp(const wchar_t* first, const wchar_t* second);
#ifdef __cplusplus
}
#endif
#endif

#endif
