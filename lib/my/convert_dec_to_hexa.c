/*
** EPITECH PROJECT, 2018
** convert_dec_to_hexa
** File description:
** convert_dec_to_hexa
*/

#include "my.h"

char *convert_dec_to_hexa(unsigned int nb, int casse)
{
    int i = 0;
    unsigned int nb2 = nb;
    char *result = malloc(sizeof(char) * (my_intlen(nb) + 1));

    result = my_memset(result, '0', my_intlen(nb) + 1);
    for (i = 0; nb > 0; i++) {
        result[i] = '0' + nb % 16;
        if (result[i] > '9')
            result[i] += casse;
        if (result[i] > 'f')
            result[i + 1] += result[i] - 'f';
        nb /= 16;
    }
    if (i < 2)
        i++;
    result[i] = 0;
    return (my_revstr(result));
}
