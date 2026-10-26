//
// Created by NHCM on 2026/10/26.
//

#ifndef NWLIBC___STDDEF_H
#define NWLIBC___STDDEF_H

#if defined(__x86_64__) || defined(_M_X64)
typedef unsigned long long __nwlibc_size_t;
typedef long long          __nwlibc_ptrdiff_t;
#elif defined(__i386__) || defined(_M_IX86)
typedef unsigned int __nwlibc_size_t;
typedef int          __nwlibc_ptrdiff_t;
#else
#error Unsupported architecture
#endif

#endif //NWLIBC___STDDEF_H
