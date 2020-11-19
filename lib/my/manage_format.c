/*
** EPITECH PROJECT, 2018
** manage_format
** File description:
** manage_format
*/

#include "my.h"

void manage_format3(char c, va_list list, format *form)
{
    unsigned int unb = 0;

    if (form->zero == false && c && (c == 'u'))
        my_put_unsigned_int(va_arg(list, unsigned int));
    else if (form->zero == false && c && (c == 'o')) {
        unb = va_arg(list, unsigned int);
        if (form->sharp == true && unb != 0)
            my_putchar('0');
        my_putstr(convert_dec_to_octal(unb, false));
    }
}

void manage_format2(char c, va_list list, format *form)
{
    unsigned int unb = 0;

    if (form->zero == false && c && (c == 'x' || c == 'X')) {
        unb = va_arg(list, unsigned int);
        if (form->sharp == true && unb != 0) {
            my_putchar('0');
            my_putchar(c);
        }
        my_putstr(convert_dec_to_hexa(unb, c - 81));
    }
    else
        manage_format3(c, list, form);
}

void manage_format(char c, va_list list, format *form)
{
    int nb = 0;

    if (form->zero == false && c && (c == 'd' || c == 'i')) {
        nb = va_arg(list, int);
        if (form->plus == true && nb >= 0)
            my_putchar('+');
        else if (form->space == true && nb >= 0)
            my_putchar(' ');
        my_put_nbr(nb);
    }
    else
        manage_format2(c, list, form);
}
