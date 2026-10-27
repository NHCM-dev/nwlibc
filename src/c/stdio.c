//
// Created by NHCM on 2026/10/27.
//

#include <internal/__stdio.h>

int puts(const char* string)
{
    return __stdio_puts(string);
}