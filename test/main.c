//
// Created by NHCM on 2026/10/26.
//

#include <string.h>
#include <stdlib.h>

int main()
{
    char test[sizeof("testtest2")] = "test";
    const char* test2 = "test2";
    const char* test3 = strcat(test, test2);
    const char* test4 = strdup(test3);
    free((void*)test4);
    return 0;
}
