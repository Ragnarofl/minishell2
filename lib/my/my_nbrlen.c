/*
** EPITECH PROJECT, 2018
** my_nbrlen.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

int my_nbrlen(long int nb, int base)
{
    int res = 0;

    for (; nb > base; res++)
        nb /= base;
    if (nb == base)
        res += 1;
    return (res += 1);
}
