//
// Created by NHCM on 2026/10/27.
//

#include <internal/__ctype.h>

int __ctype_isalnum(int character)
{
    return __ctype_isalpha(character) || __ctype_isdigit(character);
}

int __ctype_isalpha(int character)
{
    return __ctype_isupper(character) || __ctype_islower(character);
}

int __ctype_isupper(int character)
{
    bool upper_letter = character >= 'A' && character <= 'Z';
    return upper_letter;
}

int __ctype_islower(int character)
{
    bool lower_letter = character >= 'a' && character <= 'z';
    return lower_letter;
}

int __ctype_isdigit(int character)
{
    bool is_digit = character >= '0' && character <= '9';
    return is_digit;
}

int __ctype_isblank(int character)
{
    bool is_space_char = character == ' ';
    bool is_tab_char = character == '\t';
    return is_space_char || is_tab_char;
}

int __ctype_iscntrl(int character)
{
    bool is_cntrl = character >= 0 && character <= 31;
    bool is_del = character == 127;
    return is_cntrl || is_del;
}

int __ctype_isgraph(int character)
{
    bool is_graph_char = character >= '!' && character <= '~';
    return is_graph_char;
}

int __ctype_isprint(int character)
{
    bool is_space_char = character == ' ';
    return __ctype_isgraph(character) || is_space_char;
}

int __ctype_ispunct(int character)
{
    return __ctype_isgraph(character) && !__ctype_isalnum(character);
}

int __ctype_isspace(int character)
{
    bool is_empty_char =
        character == '\t' ||
        character == '\n' ||
        character == '\v' ||
        character == '\f' ||
        character == '\r';

    bool is_space_char = character == ' ';
    return is_empty_char || is_space_char;
}

int __ctype_isxdigit(int character)
{
    if (__ctype_isdigit(character))
    {
        return true;
    }

    bool upper_a_f = character >= 'A' && character <= 'F';
    bool lower_a_f = character >= 'a' && character <= 'f';
    return upper_a_f || lower_a_f;
}

int __ctype_tolower(int character)
{
    if (__ctype_isupper(character))
    {
        return character - 'A' + 'a';
    }

    return character;
}

int __ctype_toupper(int character)
{
    if (__ctype_islower(character))
    {
        return character - 'a' + 'A';
    }

    return character;
}