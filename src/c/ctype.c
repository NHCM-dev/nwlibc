//
// Created by NHCM on 2026/10/27.
//

#include <ctype.h>
#include <internal/__ctype.h>

int isalnum(int character)
{
    return __ctype_isalnum(character);
}

int isalpha(int character)
{
    return __ctype_isalpha(character);
}

int isupper(int character)
{
    return __ctype_isupper(character);
}

int islower(int character)
{
    return __ctype_islower(character);
}

int isdigit(int character)
{
    return __ctype_isdigit(character);
}

int isblank(int character)
{
    return __ctype_isblank(character);
}

int iscntrl(int character)
{
    return __ctype_iscntrl(character);
}

int isgraph(int character)
{
    return __ctype_isgraph(character);
}

int isprint(int character)
{
    return __ctype_isprint(character);
}

int ispunct(int character)
{
    return __ctype_ispunct(character);
}

int isspace(int character)
{
    return __ctype_isspace(character);
}

int isxdigit(int character)
{
    return __ctype_isxdigit(character);
}

int tolower(int character)
{
    return __ctype_tolower(character);
}

int toupper(int character)
{
    return __ctype_toupper(character);
}