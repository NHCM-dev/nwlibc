//
// Created by NHCM on 2026/10/26.
//

#ifndef NWLIBC___STDINT_H
#define NWLIBC___STDINT_H

typedef signed char __int8_t;
typedef signed short __int16_t;
typedef signed int __int32_t;
typedef signed long long __int64_t;

typedef unsigned char __uint8_t;
typedef unsigned short __uint16_t;
typedef unsigned int __uint32_t;
typedef unsigned long long __uint64_t;

typedef signed char __int_least8_t;
typedef signed short __int_least16_t;
typedef signed int __int_least32_t;
typedef signed long long __int_least64_t;

typedef unsigned char __uint_least8_t;
typedef unsigned short __uint_least16_t;
typedef unsigned int __uint_least32_t;
typedef unsigned long long __uint_least64_t;

typedef signed char __int_fast8_t;
typedef signed int __int_fast16_t;
typedef signed int __int_fast32_t;
typedef signed long long __int_fast64_t;

typedef unsigned char __uint_fast8_t;
typedef unsigned int __uint_fast16_t;
typedef unsigned int __uint_fast32_t;
typedef unsigned long long __uint_fast64_t;

typedef signed long long __intmax_t;
typedef unsigned long long __uintmax_t;

#if defined(__x86_64__) || defined(_M_X64)

typedef signed long long __intptr_t;
typedef unsigned long long __uintptr_t;

#elif defined(__i386__) || defined(_M_IX86)

typedef signed int __intptr_t;
typedef unsigned int __uintptr_t;

#else
#error Unsupported architecture
#endif

#endif /* NWLIBC___STDINT_H */