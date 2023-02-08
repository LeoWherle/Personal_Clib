/*
** EPITECH PROJECT, 2023
** my_c_library
** File description:
** strings_core
*/

#include <stdlib.h>
#include "strings_internal.h"

static string_t *copy(char *dest, const char *const src)
{
    char *start = NULL;
    start = dest;
    while (*src) {
        *dest = *src;
        dest++;
        start++;
    }
    *dest = '\0';
    return dest;
}

static void string_init(string_t *self)
{
    self->string = NULL;
    self->length = 0;
    self->destroy = &delete_string;
    self->getNbr = &stringGet_nbr;
    self->isAlpha = &stringIsAlpha;
    self->isNum = &stringIsNum;
    self->isLowerCase = &stringIsLowerCase;
    self->isUpperCase = &stringIsUpperCase;
    self->isPrintable = &stringIsPrintable;
    self->reverse = &stringReverse;
    self->toUpper = &stringToUpper;
    self->toLower = &stringToLower;
    self->concat = &stringConcat;
    self->concatAmount = &stringConcatAmount;
    self->copy = &stringCopy;
    self->copyAmount = &stringCopyAmount;
    self->find = &stringFind;
}

string_t *new_string(const char *const str)
{
    string_t *new = NULL;

    new = malloc(sizeof(string_t));
    if (new == NULL)
        return NULL;
    string_init(new);
    new->length = stringLength(str);
    new->string = malloc(sizeof(char) * (new->length + 1));
    if (new->string == NULL)
        return NULL;
    new->string = copy(new->string, str);
    return new;
}

string_t *new_empty_string(unsigned long size)
{
    string_t *new = NULL;

    new = malloc(sizeof(string_t));
    if (new == NULL)
        return NULL;
    strint_init(new);
    new->length = size;
    new->string = malloc(sizeof(char) * (new->length + 1));
    if (new->string == NULL)
        return NULL;
    new->string = copy(new->string, "");
    return new;
}

void delete_string(string_t *self)
{
    free(self->string);
    free(self);
}
