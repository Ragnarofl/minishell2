/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** simon-perraud
*/

#include <unistd.h>

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}
