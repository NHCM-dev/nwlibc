#ifndef NWLIBC_STDINT_H
#define NWLIBC_STDINT_H

#include <internal/__stdint.h>

#define __STDC_VERSION_STDINT_H__ 202311L

typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;

typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;

typedef __int_fast8_t int_fast8_t;
typedef __int_fast16_t int_fast16_t;
typedef __int_fast32_t int_fast32_t;
typedef __int_fast64_t int_fast64_t;

typedef __uint_fast8_t uint_fast8_t;
typedef __uint_fast16_t uint_fast16_t;
typedef __uint_fast32_t uint_fast32_t;
typedef __uint_fast64_t uint_fast64_t;

typedef __intptr_t intptr_t;
typedef __uintptr_t uintptr_t;

typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;

/* Exact-width integer limits (small integer types undergo integer promotion). */
#define INT8_MIN (-127 - 1)
#define INT8_MAX 127
#define UINT8_MAX 255
#define INT16_MIN (-32767 - 1)
#define INT16_MAX 32767
#define UINT16_MAX 65535
#define INT32_MIN (-2147483647 - 1)
#define INT32_MAX 2147483647
#define UINT32_MAX 4294967295U
#define INT64_MIN (-9223372036854775807LL - 1LL)
#define INT64_MAX 9223372036854775807LL
#define UINT64_MAX 18446744073709551615ULL

/* Minimum-width integer limits. */
#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST8_MAX INT8_MAX
#define UINT_LEAST8_MAX UINT8_MAX
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST16_MAX INT16_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST32_MAX INT32_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define INT_LEAST64_MIN INT64_MIN
#define INT_LEAST64_MAX INT64_MAX
#define UINT_LEAST64_MAX UINT64_MAX

/* Fast types follow the choices made in internal/__stdint.h. */
#define INT_FAST8_MIN INT8_MIN
#define INT_FAST8_MAX INT8_MAX
#define UINT_FAST8_MAX UINT8_MAX
#define INT_FAST16_MIN INT32_MIN
#define INT_FAST16_MAX INT32_MAX
#define UINT_FAST16_MAX UINT32_MAX
#define INT_FAST32_MIN INT32_MIN
#define INT_FAST32_MAX INT32_MAX
#define UINT_FAST32_MAX UINT32_MAX
#define INT_FAST64_MIN INT64_MIN
#define INT_FAST64_MAX INT64_MAX
#define UINT_FAST64_MAX UINT64_MAX

#define INTMAX_MIN INT64_MIN
#define INTMAX_MAX INT64_MAX
#define UINTMAX_MAX UINT64_MAX

/* Widths include the sign bit for signed integer types. */
#define INT8_WIDTH 8
#define UINT8_WIDTH 8
#define INT16_WIDTH 16
#define UINT16_WIDTH 16
#define INT32_WIDTH 32
#define UINT32_WIDTH 32
#define INT64_WIDTH 64
#define UINT64_WIDTH 64

#define INT_LEAST8_WIDTH INT8_WIDTH
#define UINT_LEAST8_WIDTH UINT8_WIDTH
#define INT_LEAST16_WIDTH INT16_WIDTH
#define UINT_LEAST16_WIDTH UINT16_WIDTH
#define INT_LEAST32_WIDTH INT32_WIDTH
#define UINT_LEAST32_WIDTH UINT32_WIDTH
#define INT_LEAST64_WIDTH INT64_WIDTH
#define UINT_LEAST64_WIDTH UINT64_WIDTH

#define INT_FAST8_WIDTH INT8_WIDTH
#define UINT_FAST8_WIDTH UINT8_WIDTH
#define INT_FAST16_WIDTH INT32_WIDTH
#define UINT_FAST16_WIDTH UINT32_WIDTH
#define INT_FAST32_WIDTH INT32_WIDTH
#define UINT_FAST32_WIDTH UINT32_WIDTH
#define INT_FAST64_WIDTH INT64_WIDTH
#define UINT_FAST64_WIDTH UINT64_WIDTH

#define INTMAX_WIDTH INT64_WIDTH
#define UINTMAX_WIDTH UINT64_WIDTH

/* Windows x64 uses LLP64; Windows x86 has 32-bit pointers. */
#if defined(__x86_64__) || defined(_M_X64)
#define INTPTR_MIN INT64_MIN
#define INTPTR_MAX INT64_MAX
#define UINTPTR_MAX UINT64_MAX
#define INTPTR_WIDTH INT64_WIDTH
#define UINTPTR_WIDTH UINT64_WIDTH
#define PTRDIFF_MIN INT64_MIN
#define PTRDIFF_MAX INT64_MAX
#define PTRDIFF_WIDTH INT64_WIDTH
#define SIZE_MAX UINT64_MAX
#define SIZE_WIDTH UINT64_WIDTH
#elif defined(__i386__) || defined(_M_IX86)
#define INTPTR_MIN INT32_MIN
#define INTPTR_MAX INT32_MAX
#define UINTPTR_MAX UINT32_MAX
#define INTPTR_WIDTH INT32_WIDTH
#define UINTPTR_WIDTH UINT32_WIDTH
#define PTRDIFF_MIN INT32_MIN
#define PTRDIFF_MAX INT32_MAX
#define PTRDIFF_WIDTH INT32_WIDTH
#define SIZE_MAX UINT32_MAX
#define SIZE_WIDTH UINT32_WIDTH
#endif

/* Windows ABI choices: sig_atomic_t is int; wchar_t/wint_t are unsigned 16-bit. */
#define SIG_ATOMIC_MIN INT32_MIN
#define SIG_ATOMIC_MAX INT32_MAX
#define SIG_ATOMIC_WIDTH INT32_WIDTH
#define WCHAR_MIN 0
#define WCHAR_MAX UINT16_MAX
#define WCHAR_WIDTH UINT16_WIDTH
#define WINT_MIN 0
#define WINT_MAX UINT16_MAX
#define WINT_WIDTH UINT16_WIDTH

/* Constants have the promoted types of int_leastN_t / uint_leastN_t. */
#define INT8_C(value) value
#define UINT8_C(value) value
#define INT16_C(value) value
#define UINT16_C(value) value
#define INT32_C(value) value
#define UINT32_C(value) value##U
#define INT64_C(value) value##LL
#define UINT64_C(value) value##ULL
#define INTMAX_C(value) value##LL
#define UINTMAX_C(value) value##ULL

#endif /* NWLIBC_STDINT_H */
