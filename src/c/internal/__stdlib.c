//
// Created by NHCM on 2026/10/27.
//

#include <windows.h>
#include <internal/__stdlib.h>
#include <errno.h>
#include <stdint.h>

void* __stdlib_malloc(size_t size)
{
    if (size == 0)
    {
        size = 1;
    }
    void* result = HeapAlloc(GetProcessHeap(), 0, size);
    if (result == NULL)
    {
        errno = ENOMEM;
    }
    return result;
}

void* __stdlib_calloc(size_t count, size_t size)
{
    if (size != 0 && count > SIZE_MAX / size)
    {
        errno = ENOMEM;
        return NULL;
    }
    size_t total = count * size;
    if (total == 0)
    {
        total = 1;
    }
    void* result = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, total);
    if (result == NULL)
    {
        errno = ENOMEM;
    }
    return result;

}
void* __stdlib_realloc(void *ptr, size_t new_size)
{
    if (ptr == NULL)
    {
        return __stdlib_malloc(new_size);
    }

    void* result = HeapReAlloc(GetProcessHeap(), 0, ptr, new_size);
    if (result == NULL)
    {
        errno = ENOMEM;
    }
    return result;
}

void __stdlib_free(void* pointer)
{
    if (pointer == NULL)
    {
        return;
    }
    HeapFree(GetProcessHeap(),0,pointer);
}
