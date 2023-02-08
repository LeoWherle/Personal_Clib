/*
** EPITECH PROJECT, 2023
** my_c_library
** File description:
** string_manip
*/

#include <stddef.h>
#include "strings_internal.h"

static void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void stringReverse(string_t *self)
{
    char *start = NULL;
    char *end = NULL;

    start = self->string;
    end = self->string + self->length - 1;
    while (start < end) {
        swap(start, end);
        start++;
        end--;
    }
}

void stringToUpper(string_t *self)
{
    char *start = NULL;

    start = self->string;
    while (*start) {
        if (*start >= 'a' && *start <= 'z')
            *start -= 32;
        start++;
    }
}

void stringToLower(string_t *self)
{
    char *start = NULL;

    start = self->string;
    while (*start) {
        if (*start >= 'A' && *start <= 'Z')
            *start += 32;
        start++;
    }
}
