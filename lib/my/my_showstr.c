/*
** EPITECH PROJECT, 2018
** my_showstr.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

int my_showstr(char const *str, int lenght)
{
    for (int i = 0; i < lenght; i++) {
        if (str[i] == 0) {
            write(1, "\\", 1);
            write(1, "0", 1);
        } else if (str[i] == 10) {
            write(1, "\\", 1);
            write(1, "n", 1);
        } else
            my_put_nbr(str[i], 1);
        write(1, " ", 1);
    }
    write(1, "\n", 1);
    return (0);
}
