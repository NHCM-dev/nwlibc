//
// Created by NHCM on 2026/10/26.
//

#ifndef NWLIBC_STDLIB_H
#define NWLIBC_STDLIB_H

#include <internal/__stdlib.h>
#include <internal/__cdefs.h>

NWLIBC_BEGIN_DECLS

void* malloc(size_t size);
void free(void* pointer);

NWLIBC_END_DECLS

#endif //NWLIBC_STDLIB_H
