//
// Created by NHCM on 2026/10/27.
//

#ifndef NWLIBC_STDNORETURN_H
#define NWLIBC_STDNORETURN_H

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && __STDC_VERSION__ < 202311L

#define noreturn _Noreturn

#endif

#endif // NWLIBC_STDNORETURN_H