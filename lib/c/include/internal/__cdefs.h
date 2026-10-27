#ifndef NWLIBC_INTERNAL_CDEFS_H
#define NWLIBC_INTERNAL_CDEFS_H

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
