//
// Created by NHCM on 2026/10/26.
//

#define NWLIBC_STRING_NO_GENERIC
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void* memcpy(void* NWLIBC_RESTRICT destination, const void* NWLIBC_RESTRICT source, size_t byte_count)
{
    unsigned char* destination_bytes = destination;
    const unsigned char* source_bytes = source;

    for (size_t index = 0; index < byte_count; index++)
    {
        destination_bytes[index] = source_bytes[index];
    }

    return destination;
}

void* memmove(void* destination, const void* source, size_t byte_count)
{
    unsigned char* destination_bytes = destination;
    const unsigned char* source_bytes = source;

    uintptr_t destination_address = (uintptr_t)destination;
    uintptr_t source_address = (uintptr_t)source;

    if (destination_address == source_address || byte_count == 0)
    {
        return destination;
    }

    if (destination_address < source_address ||
        destination_address - source_address >= byte_count)
    {
        for (size_t index = 0; index < byte_count; index++)
        {
            destination_bytes[index] = source_bytes[index];
        }
    }
    else
    {
        for (size_t index = byte_count; index > 0; index--)
        {
            destination_bytes[index - 1] = source_bytes[index - 1];
        }
    }

    return destination;
}

void* memccpy(void* NWLIBC_RESTRICT destination, const void* NWLIBC_RESTRICT source, int character, size_t byte_count)
{
    unsigned char* destination_bytes = destination;
    const unsigned char* source_bytes = source;
    unsigned char target_byte = (unsigned char)character;

    for (size_t index = 0; index < byte_count; index++)
    {
        destination_bytes[index] = source_bytes[index];

        if (source_bytes[index] == target_byte)
        {
            return destination_bytes + index + 1;
        }
    }

    return NULL;
}

char* strcpy(char* NWLIBC_RESTRICT destination, const char* NWLIBC_RESTRICT source)
{
    size_t index = 0;

    do
    {
        destination[index] = source[index];
    }
    while (source[index++] != '\0');

    return destination;
}

char* strncpy(char* NWLIBC_RESTRICT destination, const char* NWLIBC_RESTRICT source, size_t character_count)
{
    size_t index = 0;

    for (; index < character_count && source[index] != '\0'; index++)
    {
        destination[index] = source[index];
    }

    for (; index < character_count; index++)
    {
        destination[index] = '\0';
    }

    return destination;
}

char* strcat(char* NWLIBC_RESTRICT destination, const char* NWLIBC_RESTRICT source)
{
    size_t destination_length = strlen(destination);
    size_t index = 0;

    do
    {
        destination[destination_length + index] = source[index];
    }
    while (source[index++] != '\0');

    return destination;
}

char* strncat(char* NWLIBC_RESTRICT destination, const char* NWLIBC_RESTRICT source, size_t character_count)
{
    size_t destination_length = strlen(destination);
    size_t index = 0;

    for (; index < character_count && source[index] != '\0'; index++)
    {
        destination[destination_length + index] = source[index];
    }

    destination[destination_length + index] = '\0';

    return destination;
}

int memcmp(const void* first_buffer, const void* second_buffer, size_t byte_count)
{
    const unsigned char* first_bytes = first_buffer;
    const unsigned char* second_bytes = second_buffer;

    for (size_t index = 0; index < byte_count; index++)
    {
        if (first_bytes[index] != second_bytes[index])
        {
            return first_bytes[index] - second_bytes[index];
        }
    }

    return 0;
}

int strcmp(const char* first_string, const char* second_string)
{
    size_t index = 0;

    while (first_string[index] == second_string[index])
    {
        if (first_string[index] == '\0')
        {
            return 0;
        }

        index++;
    }

    return (unsigned char)first_string[index]
        - (unsigned char)second_string[index];
}

int strncmp(const char* first_string, const char* second_string, size_t character_count)
{
    for (size_t index = 0; index < character_count; index++)
    {
        unsigned char first = (unsigned char)first_string[index];
        unsigned char second = (unsigned char)second_string[index];

        if (first != second)
        {
            return first - second;
        }

        if (first == '\0')
        {
            return 0;
        }
    }

    return 0;
}

//*todo: require actual locale implementation*
int strcoll(const char* first_string, const char* second_string)
{
    return strcmp(first_string, second_string);
}

//*todo: require implementation*
size_t strxfrm(char* NWLIBC_RESTRICT destination, const char* NWLIBC_RESTRICT source, size_t character_count);

void* memchr(const void* buffer, int character, size_t byte_count)
{
    const unsigned char* bytes = buffer;
    unsigned char target = (unsigned char)character;

    for (size_t index = 0; index < byte_count; index++)
    {
        if (bytes[index] == target)
        {
            return (void*)(bytes + index);
        }
    }

    return NULL;
}

char* strchr(const char* string, int character)
{
    unsigned char target = (unsigned char)character;

    for (size_t index = 0;; index++)
    {
        if ((unsigned char)string[index] == target)
        {
            return (char*)string + index;
        }

        if (string[index] == '\0')
        {
            return NULL;
        }
    }
}

char* strrchr(const char* string, int character)
{
    unsigned char target = (unsigned char)character;
    const char* result = NULL;

    for (size_t index = 0;; index++)
    {
        if ((unsigned char)string[index] == target)
        {
            result = string + index;
        }

        if (string[index] == '\0')
        {
            break;
        }
    }

    return (char*)result;
}

size_t strspn(const char* string, const char* accepted_characters)
{
    size_t index = 0;

    for (; string[index] != '\0'; index++)
    {
        if (strchr(accepted_characters, string[index]) == NULL)
        {
            break;
        }
    }

    return index;
}

size_t strcspn(const char* string, const char* rejected_characters)
{
    size_t index = 0;

    for (; string[index] != '\0'; index++)
    {
        if (strchr(rejected_characters, string[index]) != NULL)
        {
            break;
        }
    }

    return index;
}

char* strpbrk(const char* string, const char* accepted_characters)
{
    for (size_t index = 0; string[index] != '\0'; index++)
    {
        if (strchr(accepted_characters, string[index]) != NULL)
        {
            return (char*)string + index;
        }
    }

    return NULL;
}

char* strstr(const char* string, const char* substring)
{
    if (*substring == '\0')
    {
        return (char*)string;
    }

    for (size_t index = 0; string[index] != '\0'; index++)
    {
        size_t substring_index = 0;

        while (
            substring[substring_index] != '\0' &&
            string[index + substring_index] != '\0' &&
            string[index + substring_index] == substring[substring_index]
        )
        {
            substring_index++;
        }

        if (substring[substring_index] == '\0')
        {
            return (char*)string + index;
        }
    }

    return NULL;
}

//*todo: require implementation*
char* strtok(char* NWLIBC_RESTRICT string, const char* NWLIBC_RESTRICT delimiters);

void* memset(void* destination, int value, size_t byte_count)
{
    unsigned char* bytes = destination;
    unsigned char byte = (unsigned char)value;

    for (size_t index = 0; index < byte_count; index++)
    {
        bytes[index] = byte;
    }

    return destination;
}

/* TODO: guarantee that these writes cannot be removed by optimization. */
void* memset_explicit(void* destination, int value, size_t byte_count);

//*todo: require errno.h implementation*
char* strerror(int error_number);

size_t strlen(const char* string)
{
    size_t length = 0;

    while (string[length] != '\0')
    {
        length++;
    }

    return length;
}

char* strdup(const char* string)
{
    size_t length = strlen(string) + 1;

    char* result = malloc(length);

    if (result == NULL)
    {
        return NULL;
    }

    memcpy(result, string, length);

    return result;
}

char* strndup(const char* string, size_t character_count)
{
    size_t copy_length = 0;

    while (
        copy_length < character_count &&
        string[copy_length] != '\0'
    )
    {
        copy_length++;
    }

    char* result = malloc(copy_length + 1);

    if (result == NULL)
    {
        return NULL;
    }

    memcpy(result, string, copy_length);
    result[copy_length] = '\0';

    return result;
}
