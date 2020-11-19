/*
** EPITECH PROJECT, 2018
** fill_number
** File description:
** fill_number
*/

#include "my.h"

void fill_with_void(format *form, int size)
{
    for (int i = 0; i < size; i++) {
        if (form->blank == true)
            my_putchar(' ');
        else
            my_putchar('0');
    }
}

bool fill_number3(char c, int result, format *form, va_list list)
{
    int len = 0;
    int i = 0;
    unsigned int unb = 0;

    if (form->zero == true && c && (c == 'o')) {
        unb = va_arg(list, unsigned int);
        len = my_strlen(convert_dec_to_octal(unb, false));
        fill_with_void(form, result - len);
        my_putstr(convert_dec_to_octal(unb, false));
        return (false);
    }
    return (true);
}

bool fill_number2(char c, int result, format *form, va_list list)
{
    int len = 0;
    int i = 0;
    unsigned int unb = 0;

    if (form->zero == true && (c == 'x' || c == 'X')) {
        unb = va_arg(list, unsigned int);
        len = my_strlen(convert_dec_to_hexa(unb, c - 81));
        fill_with_void(form, result - len);
        my_putstr(convert_dec_to_hexa(unb, c - 81));
        return (false);
    }
    else if (form->zero == true && c && (c == 'u')) {
        unb = va_arg(list, unsigned int);
        len = my_intlen(unb);
        fill_with_void(form, result - len);
        my_put_unsigned_int(unb);
        return (false);
    }
    return (fill_number3(c, result, form, list));
}

bool fill_number(char c, int result, format *form, va_list list)
{
    int len = 0;
    int i = 0;
    int nb = 0;

    if (form->zero == true && (c == 'd' || c == 'i')) {
        nb = va_arg(list, int);
        len = my_intlen(nb);
        if (form->plus == true && nb >= 0) {
            my_putchar('+');
            len++;
            form->plus = false;
        }
        fill_with_void(form, result - len);
        my_put_nbr(nb);
        return (false);
    }
    return (fill_number2(c, result, form, list));
}
