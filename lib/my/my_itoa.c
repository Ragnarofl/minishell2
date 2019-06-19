/*
** EPITECH PROJECT, 2018
** my_itoa.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

char *my_itoa(int nb)
{
    int i = 0;
    int res = nb;
    int lenght = my_nbrlen(nb, 10);
    char *reverse = malloc(sizeof(char) * lenght + 1);

    if (res < 0) {
        res *= -1;
        reverse[lenght - 1] = '-';
    }
    reverse[0] = '0';
    for (; i < lenght && res > 0; i++) {
        reverse[i] = (res % 10) + 48;
        res /= 10;
    }
    reverse[lenght] = '\0';
    return (my_revstr(reverse));
}
