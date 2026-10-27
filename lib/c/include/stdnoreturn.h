//
// Created by NHCM on 2026/10/27.
//

#ifndef NWLIBC_STDNORETURN_H
#define NWLIBC_STDNORETURN_H

#include <internal/__cdefs.h>

#if NWLIBC_STDC_IN_RANGE(NWLIBC_STDC_C11, NWLIBC_STDC_C23)

#define noreturn _Noreturn

#endif

#endif // NWLIBC_STDNORETURN_H
