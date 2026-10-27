//
// Created by NHCM on 2026/10/26.
//

#include <stdlib.h>

void* malloc(size_t size)
{
    return __stdlib_malloc(size);
}

void free(void* pointer)
{
    __stdlib_free(pointer);
}
