/*
** EPITECH PROJECT, 2018
** my_fprintf.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

int my_dprintf(int fd, char *s, ...)
{
    int count = 0;
    va_list list;
    va_start(list, s);

    if (error_handling(s) == 84) {
        write(2, "Syntax error\n", 14);
        return (84);
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            i++;
            browse_fptr(pf_getexpr(s, &i), list, fd, &count);
        } else
            my_putchar(s[i], fd);
    }
    return (count);
}
