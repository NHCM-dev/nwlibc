//
// Created by NHCM on 2026/10/27.
//
/*todo:
 * This is only a implementation of default "C" locale,
 * make full implementation after adding support for locale
 */

#ifndef NWLIBC_CTYPE_H
#define NWLIBC_CTYPE_H

#include <internal/__cdefs.h>

NWLIBC_BEGIN_DECLS

int isalnum(int character);
int isalpha(int character);
int isupper(int character);
int islower(int character);
int isdigit(int character);
int isblank(int character);
int iscntrl(int character);
int isgraph(int character);

int isprint(int character);
int ispunct(int character);
int isspace(int character);

int isxdigit(int character);

int tolower(int character);
int toupper(int character);

NWLIBC_END_DECLS

#endif //NWLIBC_CTYPE_H