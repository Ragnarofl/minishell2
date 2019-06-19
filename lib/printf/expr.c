/*
** EPITECH PROJECT, 2018
** expr.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

void print_xchar(char c, int count, int fd)
{
    for (int i = 0; i < count; i++)
        write(fd, &c, 1);
}

char *pf_getexpr(char *s, int *i)
{
    int len = 1;
    char *expr;

    for (int x = *i; IS_NOT_FLAG(s[x]); len++, x++);
    expr = malloc(sizeof(char) * len + 1);
    if (!expr) {
        write(2, "Malloc error\n", 13);
        return (NULL);
    }
    for (int j = 0; j < len; *i += 1, j++)
        expr[j] = s[*i];
    expr[len] = '\0';
    *i -= 1;
    return (expr);
}
