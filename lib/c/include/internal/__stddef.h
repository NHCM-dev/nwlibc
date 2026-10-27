#ifndef NWLIBC___STDDEF_H
#define NWLIBC___STDDEF_H

#if defined(__x86_64__) || defined(_M_X64)

typedef unsigned long long __size_t;
typedef long long __ptrdiff_t;

#elif defined(__i386__) || defined(_M_IX86)

typedef unsigned int __size_t;
typedef int __ptrdiff_t;

#else
#error Unsupported architecture
#endif

typedef unsigned short __nwlibc_wchar_t;

#endif
