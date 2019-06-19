/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

int my_putstr(char *str, int fd)
{
    if (!str)
        return (0);
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i], fd);
    return (0);
}
