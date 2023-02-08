/*
** EPITECH PROJECT, 2023
** my_c_library
** File description:
** strings_internal
*/


#ifndef STRINGS_INTERNAL_H_
    #define STRINGS_INTERNAL_H_

    typedef void (*voidSelf)(string_t *self);
    typedef int (*boolself)(string_t *self);
    typedef string_t *(*strSelf)(string_t *self);
    typedef string_t *(*strSelfCStr)(string_t *self, const string_t *str);
    typedef string_t *(*strSelfCStrSize)(string_t *self, const string_t *str, size_t amount);
   
    typedef struct string_s{
        char *string;
        unsigned int length;

        voidSelf destroy;
        boolself getNbr;
        boolself isAlpha;
        boolself isNum;
        boolself isLowerCase;
        boolself isUpperCase;
        boolself isPrintable;
        strSelf reverse;
        strSelf toUpper;
        strSelf toLower;
        strSelfCStr concat;
        strSelfCStrSize concatAmount;
        strSelfCStr copy;
        strSelfCStrSize copyAmount;
        strSelfCStrSize copyFrom;
        strSelfCStr find;
    } string_t;

string_t *new_string(const char *const str);
string_t *new_empty_string(unsigned long size);
void delete_string(string_t *self);

unsigned long stringLength(const char *const self);
int stringGet_nbr(string_t *self);
int stringIsAlpha(string_t *self);
int stringIsNum(string_t *self);
int stringIsLowerCase(string_t *self);
int stringIsUpperCase(string_t *self);
int stringIsPrintable(string_t *self);
string_t *stringReverse(string_t *self);
string_t *stringToUpper(string_t *self);
string_t *stringToLower(string_t *self);
string_t *stringConcat(string_t *self, const string_t *str);
string_t *stringConcatAmount(string_t *self, const string_t *str, size_t amount);
string_t *stringCopy(string_t *self, const string_t *str);
string_t *stringCopyAmount(string_t *self, const string_t *str, size_t amount);
string_t *stringCopyFrom(string_t *self, const string_t *str, size_t start);
string_t *stringFind(string_t *self, const string_t *str);

#endif /* !STRINGS_INTERNAL_H_ */
