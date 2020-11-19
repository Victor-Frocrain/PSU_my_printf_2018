/*
** EPITECH PROJECT, 2018
** check_format
** File description:
** check_format
*/

#include "my.h"

int check_point(char *str, format *form, int result, va_list list)
{
    bool check = true;
    int k = 0;
    int i = 0;

    for (; str[i] && check == true; i++) {
        if (str[i] == '.') {
            form->blank = true;
            k++;
        }
        check = fill_number(str[i], result, form, list);
    }
    return (k);
}

int manage_zero(char *str, va_list list, format *form, int i)
{
    char *number = malloc(sizeof(char) * (my_strlen(str) + 1));
    int k = 0;

    number = my_memset(number, 0, my_strlen(str) + 1);
    if (form->zero == true) {
        while (str[i] && (str[i] < '0' || str[i] > '9') &&
        str[i] != 'd' && str[i] != 'i' && str[i] != 'x' &&
        str[i] != 'X' && str[i] != 'o' && str[i] != 'u') {
            i++;
            k++;
        }
        for (int j = 0; str[i] && (str[i] >= '0' && str[i] <= '9'); i++) {
            number[j] = str[i];
            j++;
        }
        k += check_point(str + i, form, my_getnbr(number), list);
    }
    free(number);
    return (k);
}

format *init_format(format *form)
{
    form = malloc(sizeof(form));
    form->space = false;
    form->plus = false;
    form->sharp = false;
    form->zero = false;
    form->blank = false;
    return (form);
}

void check_format(char c, format *form)
{
    switch (c) {
    case ' ':
        form->space = true;
        break;
    case '+':
        form->plus = true;
        break;
    case '#':
        form->sharp = true;
        break;
    case '0':
        form->zero = true;
        break;
    default:
        break;
    }
}
