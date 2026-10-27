#include <errno.h>

/* Standard C11 thread-local storage; no shared fallback or CRT dependency. */
static _Thread_local int current_errno = 0;

int *__nwlibc_errno_location(void)
{
    return &current_errno;
}
