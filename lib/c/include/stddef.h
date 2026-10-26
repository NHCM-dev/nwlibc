//
// Created by NHCM on 2026/10/26.
//

#ifndef NWLIBC_STDDEF_H
#define NWLIBC_STDDEF_H

#include <internal/__stddef.h>

typedef __nwlibc_size_t size_t;
typedef __nwlibc_ptrdiff_t ptrdiff_t;

#ifndef NULL
#ifdef __cplusplus
#define NULL nullptr
#else
#define NULL ((void *)0)
#endif
#endif

#endif //NWLIBC_STDDEF_H
