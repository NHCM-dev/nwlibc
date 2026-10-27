//
// Created by NHCM on 2026/10/27.
//

#include <windows.h>
#include <internal/__stdlib.h>
#include <errno.h>

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

void __stdlib_free(void* pointer)
{
    if (pointer == NULL)
    {
        return;
    }

    HeapFree(GetProcessHeap(),0,pointer);
}
