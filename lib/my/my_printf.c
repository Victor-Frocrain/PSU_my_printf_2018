/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include "my.h"

void my_putchar_non_print(unsigned int c)
{
    if (c < 32 || c >= 127) {
        my_putchar('\\');
        my_putstr(convert_dec_to_octal(c, true));
    }
    else
        my_putchar(c);
}

void my_putstr_non_print(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_putstr(convert_dec_to_octal(str[i], true));
        }
        else
            my_putchar(str[i]);
    }
}

int check_flags(char *s, int i, va_list list)
{
    format *form = init_format(form);
    int j = 1;
    int zero = 0;
    int nb;
    int k = 0;

    for (; s[i] && (s[i] == ' ' || s[i] == '-' || s[i] == '+' ||
    s[i] == '#' || (s[i] >= '0' && s[i] <= '9')); i++) {
        check_format(s[i], form);
        if (s[i] == '0' && s[i - 1] && s[i - 1] == '%')
            zero = i;
        j++;
    }
    if (form->zero == true)
        k = manage_zero(s, list, form, zero + 1);
    if (s[i + k])
        manage_format(s[i + k], list, form);
    free(form);
    return (j + k);
}

int my_printf(char *s, ...)
{
    va_list list;
    int j = 1;

    va_start(list, s);
    for (int i = 0; s[i]; i += j) {
        j = 1;
        if (s[i] == '%' && s[i + 1])
            j = check_flags(s, i + 1, list);
        if (s[i] && s[i] == '%' && s[i + j]) {
            check_case(s[i + j], list);
            i++;
        }
        else if (s[i] && s[i] != '%')
            my_putchar(s[i]);
    }
    va_end(list);
    return (MY_EXIT_SUCCESS);
}
