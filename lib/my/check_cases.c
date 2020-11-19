/*
** EPITECH PROJECT, 2018
** check_cases
** File description:
** check cases
*/

#include "my.h"

void check_case3(char c, va_list list)
{
    unsigned int nb;

    if (c == 'p') {
        nb = va_arg(list, unsigned int);
        if (nb) {
            my_putstr("0x");
            my_putstr(convert_dec_to_hexa(nb, 39));
        }
        else
            my_putstr("(nil)");
    }
}

void check_case2(char c, va_list list)
{
    switch (c) {
    case 'S':
        my_putstr_non_print(va_arg(list, char *));
        break;
    case 'b':
        my_putstr(convert_dec_to_binary(va_arg(list, unsigned int)));
        break;
    default:
        check_case3(c, list);
        break;
    }
}

void check_case(char c, va_list list)
{
    switch (c) {
    case 's':
        my_putstr(va_arg(list, char *));
        break;
    case 'c':
        my_putchar(va_arg(list, int));
        break;
    case 'C':
        my_putchar_non_print(va_arg(list, unsigned int));
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        check_case2(c, list);
        break;
    }
}
