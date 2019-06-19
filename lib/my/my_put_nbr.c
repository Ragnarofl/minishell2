/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

long int my_put_nbr(long int nb, int fd)
{
    int i = 48;

    if (nb <= INT_MIN) {
        write(fd, "-2147483648", 11);
        return (0);
    }
    if (nb < 0) {
        my_putchar('-', fd);
        nb *= -1;
    }
    if (nb != 0) {
        i = (nb % 10) + 48;
        nb = nb / 10;
        if (nb != 0)
            my_put_nbr(nb, fd);
    }
    my_putchar(i, fd);
    return (0);
}
