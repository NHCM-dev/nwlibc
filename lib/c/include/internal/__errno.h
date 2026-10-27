#ifndef NWLIBC_INTERNAL_ERRNO_H
#define NWLIBC_INTERNAL_ERRNO_H

#include <internal/__cdefs.h>

NWLIBC_BEGIN_DECLS
int *__nwlibc_errno_location(void);
NWLIBC_END_DECLS

#endif
