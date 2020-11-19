/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Print the integers
*/

#include "my.h"

int my_put_unsigned_int(unsigned int nb)
{
    int i = 0;
    unsigned long j = 10;

    for (unsigned int copy = nb; copy / 10 > 0; copy = copy / 10) {
        i++;
        j = j * 10;
    }
    while (i >= 0) {
        my_putchar((nb % j) / (j / 10) + '0');
        j = j / 10;
        i--;
    }
    return (0);
}
