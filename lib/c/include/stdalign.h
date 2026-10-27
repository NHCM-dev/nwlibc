//
// Created by NHCM on 2026/10/27.
//

#ifndef NWLIBC_STDALIGN_H
#define NWLIBC_STDALIGN_H

#include <internal/__cdefs.h>

#if NWLIBC_STDC_BEFORE(NWLIBC_STDC_C23)

#define alignas _Alignas
#define alignof _Alignof

#endif

#define __alignas_is_defined 1

#endif // NWLIBC_STDALIGN_H
