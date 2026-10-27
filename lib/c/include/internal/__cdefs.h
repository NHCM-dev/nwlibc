#ifndef NWLIBC_INTERNAL_CDEFS_H
#define NWLIBC_INTERNAL_CDEFS_H

#define NWLIBC_STDC_C95 199409L
#define NWLIBC_STDC_C99 199901L
#define NWLIBC_STDC_C11 201112L
#define NWLIBC_STDC_C17 201710L
#define NWLIBC_STDC_C23 202311L

/* C90 has no __STDC_VERSION__. C++ is not a C language version. */
#ifdef __cplusplus
#define NWLIBC_STDC_IS_C 0
#define NWLIBC_STDC_VERSION 0L
#else
#define NWLIBC_STDC_IS_C 1
#ifdef __STDC_VERSION__
#define NWLIBC_STDC_VERSION __STDC_VERSION__
#else
#define NWLIBC_STDC_VERSION 0L
#endif
#endif

/* Use these predicates in #if / #elif; macros cannot generate directives. */
#define NWLIBC_STDC_AT_LEAST(version) \
    (NWLIBC_STDC_IS_C && NWLIBC_STDC_VERSION >= (version))
#define NWLIBC_STDC_BEFORE(version) \
    (NWLIBC_STDC_IS_C && NWLIBC_STDC_VERSION < (version))
#define NWLIBC_STDC_IN_RANGE(first, limit) \
    (NWLIBC_STDC_AT_LEAST(first) && NWLIBC_STDC_BEFORE(limit))

#ifdef __cplusplus
#define NWLIBC_BEGIN_DECLS extern "C" {
#define NWLIBC_END_DECLS }
#define NWLIBC_RESTRICT
#else
#define NWLIBC_BEGIN_DECLS
#define NWLIBC_END_DECLS
#define NWLIBC_RESTRICT restrict
#endif
#endif
