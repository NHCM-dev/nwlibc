//
// Created by NHCM on 2026/10/26.
//

#include <stdlib.h>

void* malloc(size_t size)
{
    return __stdlib_malloc(size);
}

void* calloc(size_t count, size_t size)
{
    return __stdlib_calloc(count, size);
}

void* realloc(void *ptr, size_t new_size)
{
    return __stdlib_realloc(ptr, new_size);
}

void free(void* pointer)
{
    __stdlib_free(pointer);
}
