/*
** EPITECH PROJECT, 2018
** convert_dec_to_octal
** File description:
** convert_dec_to_octal
*/

#include "my.h"

char *convert_dec_to_octal(unsigned int nb, bool nprint)
{
    int i = 0;
    unsigned int nb2 = nb;
    char *result = malloc(sizeof(char) * (my_intlen(nb) + 4));

    result = my_memset(result, '0', my_intlen(nb) + 4);
    if (nb == 0)
        i = 1;
    for (; nb > 0; i++) {
        result[i] = '0' + nb % 8;
        if (result[i] > '9')
            result[i] += 39;
        nb /= 8;
    }
    while (nprint == true && i < 3)
        i++;
    result[i] = 0;
    return (my_revstr(result));
}
