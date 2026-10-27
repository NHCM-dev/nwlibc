//
// Created by NHCM on 2026/10/27.
//

#ifndef NWLIBC___STDLIB_H
#define NWLIBC___STDLIB_H

#include <stddef.h>

void* __stdlib_malloc(size_t size);
void* __stdlib_calloc(size_t count, size_t size);
void* __stdlib_realloc(void *ptr, size_t new_size);
void __stdlib_free(void* pointer);

#endif //NWLIBC___STDLIB_H
