
#include <stddef.h>
#include "strings_internal.h"

string_t *stringCopy(string_t *self, const string_t *other)
{
    char *start = NULL;
    char *end = NULL;

    start = self->string;
    end = other->string;
    while (*end) {
        *start = *end;
        start++;
        end++;
    }
    *start = '\0';
    return self;
}

string_t *stringCopyAmount(string_t *self, const string_t *other, size_t amount)
{
    char *start = NULL;
    char *end = NULL;

    start = self->string;
    end = other->string;
    while (*end && amount) {
        *start = *end;
        start++;
        end++;
        amount--;
    }
    *start = '\0';
    return self;
}

string_t *stringCopyFrom(string_t *self, const string_t *other, size_t index)
{
    char *start = NULL;
    char *end = NULL;

    start = self->string;
    end = other->string + index;
    while (*end) {
        *start = *end;
        start++;
        end++;
    }
    *start = '\0';
    return self;
}

string_t *stringConcat(string_t *self, const string_t *other)
{
    string_t *new = NULL;

    new = new_empty_string(self->length + other->length);
    new->copy(new, self);
    new->copyFrom(new, other, self->length);
    return new;
}

string_t *stringConcatAmount(string_t *self, const string_t *other, size_t amount)
{
    string_t *new = NULL;
    size_t cpamount = 0;

    if (other->length < amount)
        cpamount = other->length;
    else
        cpamount = amount;
    new = new_empty_string(self->length + )
}

