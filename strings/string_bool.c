
#include <stddef.h>
#include "strings_internal.h"

int stringIsAlpha(string_t *self)
{
    char *start = NULL;

    start = self->string;
    while (*start) {
        if (!(*start >= 'a' && *start <= 'z') 
        && !(*start >= 'A' && *start <= 'Z')) {
            return 0;
        }
        start++;
    }
    return 1;
}

int stringIsNum(string_t *self)
{
    char *start = NULL;

    start = self->string;
    while (*start) {
        if (!(*start >= '0' && *start <= '9'))
            return 0;
        start++;
    }
    return 1;
}

int stringIsLowerCase(string_t *self)
{
    char *start = NULL;

    start = self->string;
    while (*start) {
        if (!(*start >= 'a' && *start <= 'z'))
            return 0;
        start++;
    }
    return 1;
}

int stringIsUpperCase(string_t *self)
{
    char *start = NULL;

    start = self->string;
    while (*start) {
        if (!(*start >= 'A' && *start <= 'Z'))
            return 0;
        start++;
    }
    return 1;
}
