#ifndef NWLIBC_STDDEF_H
#define NWLIBC_STDDEF_H

#include <internal/__stddef.h>

#define __STDC_VERSION_STDDEF_H__ 202311L

typedef __size_t size_t;
typedef __ptrdiff_t ptrdiff_t;
#ifndef __cplusplus
typedef __nwlibc_wchar_t wchar_t;
#endif

#ifdef __cplusplus
typedef decltype(nullptr) nullptr_t;
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
typedef __typeof__(nullptr) nullptr_t;
#endif

typedef struct {
    long long __ll;
    long double __ld;
} max_align_t;

#ifndef NULL
#ifdef __cplusplus
#define NULL nullptr
#else
#define NULL ((void *)0)
#endif
#endif

#define offsetof(type, member) __builtin_offsetof(type, member)

#define unreachable() __builtin_unreachable()

#endif
