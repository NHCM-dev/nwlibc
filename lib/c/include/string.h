//
// Created by NHCM on 2026/10/26.
//

#ifndef NWLIBC_STRING_H
#define NWLIBC_STRING_H

#include <stddef.h>
#include <internal/__cdefs.h>

#define __STDC_VERSION_STRING_H__ 202311L

NWLIBC_BEGIN_DECLS

void* memcpy(void* NWLIBC_RESTRICT destination, const void* NWLIBC_RESTRICT source, size_t byte_count);

void* memmove(void* destination, const void* source, size_t byte_count);

void* memccpy(void* NWLIBC_RESTRICT destination, const void* NWLIBC_RESTRICT source, int character, size_t byte_count);

char* strcpy(char* NWLIBC_RESTRICT destination, const char* NWLIBC_RESTRICT source);

char* strncpy(char* NWLIBC_RESTRICT destination, const char* NWLIBC_RESTRICT source, size_t character_count);

char* strcat(char* NWLIBC_RESTRICT destination, const char* NWLIBC_RESTRICT source);

char* strncat(char* NWLIBC_RESTRICT destination, const char* NWLIBC_RESTRICT source, size_t character_count);

int memcmp(const void* first_buffer, const void* second_buffer, size_t byte_count);

int strcmp(const char* first_string, const char* second_string);

int strncmp(const char* first_string, const char* second_string, size_t character_count);

int strcoll(const char* first_string, const char* second_string);

size_t strxfrm(char* NWLIBC_RESTRICT destination, const char* NWLIBC_RESTRICT source, size_t character_count);

void* memchr(const void* buffer, int character, size_t byte_count);

char* strchr(const char* string, int character);

char* strrchr(const char* string, int character);

size_t strspn(const char* string, const char* accepted_characters);

size_t strcspn(const char* string, const char* rejected_characters);

char* strpbrk(const char* string, const char* accepted_characters);

char* strstr(const char* string, const char* substring);

char* strtok(char* NWLIBC_RESTRICT string, const char* NWLIBC_RESTRICT delimiters);

void* memset(void* destination, int value, size_t byte_count);

void* memset_explicit(void* destination, int value, size_t byte_count);

char* strerror(int error_number);

size_t strlen(const char* string);

char* strdup(const char* string);

char* strndup(const char* string, size_t character_count);

/* Optional functions */

char* strerror(int error_number);

NWLIBC_END_DECLS

/* C23 7.26.5: search expressions preserve the searched array's const qualification.
 * Parenthesizing a function name still exposes its external C function.
 * Library implementation files suppress these macros before including this header.
 */
#if !defined(__cplusplus) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L && \
    !defined(NWLIBC_STRING_NO_GENERIC)

/* The nested cast is not a null pointer constant: the conditional's type is
 * void* or const void*, even when pointer is a char*, int*, or an array.
 * Its controlling expression is not evaluated by _Generic.
 */
#define NWLIBC_STRING_SEARCH(pointer, element_type, call) \
    _Generic((1 ? (pointer) : (void*)(char*)0), \
        void*: (element_type*)(call), \
        const void*: (const element_type*)(call))

#define memchr(buffer, character, byte_count) \
    NWLIBC_STRING_SEARCH(buffer, void, (memchr)((buffer), (character), (byte_count)))

#define strchr(string, character) \
    NWLIBC_STRING_SEARCH(string, char, (strchr)((string), (character)))

#define strrchr(string, character) \
    NWLIBC_STRING_SEARCH(string, char, (strrchr)((string), (character)))

#define strpbrk(string, accepted_characters) \
    NWLIBC_STRING_SEARCH(string, char, (strpbrk)((string), (accepted_characters)))

#define strstr(string, substring) \
    NWLIBC_STRING_SEARCH(string, char, (strstr)((string), (substring)))

#endif

#endif //NWLIBC_STRING_H
