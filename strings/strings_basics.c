/*
** EPITECH PROJECT, 2023
** my_c_library
** File description:
** strings_basics
*/

#include <stddef.h>
#include "strings_internal.h"

unsigned long stringLength(const char *const self)
{
    char *start = NULL;
    start = self;
    while (*start) {
        start++;
    }
    return (self - start);
}

int stringGet_nbr(string_t *self)
{
    int nbr = 0;
    int sign = 1;
    char *start = NULL;

    start = self->string;
    if (*start == '-') {
        sign = -1;
        start++;
    }
    while (*start && *start >= '0' && *start <= '9') {
        nbr = nbr * 10 + (*start - '0');
        start++;
    }
    return nbr * sign;
}
