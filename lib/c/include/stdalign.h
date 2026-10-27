//
// Created by NHCM on 2026/10/27.
//

#ifndef NWLIBC_STDALIGN_H
#define NWLIBC_STDALIGN_H

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 202311L

#define alignas _Alignas
#define alignof _Alignof

#endif

#define __alignas_is_defined 1

#endif // NWLIBC_STDALIGN_H