//
// Created by NHCM on 2026/10/27.
//

#ifndef NWLIBC___CTYPE_H
#define NWLIBC___CTYPE_H

int __ctype_isalnum(int character);
int __ctype_isalpha(int character);
int __ctype_isupper(int character);
int __ctype_islower(int character);
int __ctype_isdigit(int character);
int __ctype_isblank(int character);
int __ctype_iscntrl(int character);
int __ctype_isgraph(int character);

int __ctype_isprint(int character);
int __ctype_ispunct(int character);
int __ctype_isspace(int character);

int __ctype_isxdigit(int character);

int __ctype_tolower(int character);
int __ctype_toupper(int character);

#endif //NWLIBC___CTYPE_H
