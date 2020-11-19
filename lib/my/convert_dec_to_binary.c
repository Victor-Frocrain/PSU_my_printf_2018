/*
** EPITECH PROJECT, 2018
** convert_dec_to_binary
** File description:
** convert_dec_to_binary
*/

#include "my.h"

char *convert_dec_to_binary(unsigned int nb)
{
    int i = 0;
    unsigned int nb2 = nb;
    char *result = malloc(sizeof(char) * (my_intlen(nb) * 4 + 1));

    result = my_memset(result, '0', my_intlen(nb) * 4 + 1);
    for (i = 0; nb > 0; i++) {
        result[i] += nb % 2;
        nb /= 2;
    }
    if (i < 2)
        i++;
    result[i] = 0;
    return (my_revstr(result));
}
