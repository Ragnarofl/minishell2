/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** simon-perraud
*/

#include <limits.h>
#include <unistd.h>
#include "../../include/my.h"

void my_printnbr(int c, char m, int fd)
{
    char mhexa[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char Mhexa[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

    if (c > 9 && m == 'm')
        my_putchar(mhexa[c - 10], fd);
    else if (c > 9 && m == 'M')
        my_putchar(Mhexa[c - 10], fd);
    else
        my_putchar(c + 48, fd);
}

long int my_putnbr_base(long int nb, char *base, char m, int fd)
{
    int i;
    int b = my_getnbr(base);

    if (nb == INT_MIN) {
        write(fd, "-2147483648", 11);
        return (0);
    }
    if (nb < 0) {
        my_putchar('-', fd);
        nb *= -1;
    }
    if (nb != 0) {
        i = (nb % b);
        nb = nb / b;
        if (nb != 0)
            my_putnbr_base(nb, base, m, fd);
    }
    my_printnbr(i, m, fd);
    return (0);
}
