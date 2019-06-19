/*
** EPITECH PROJECT, 2018
** formats.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

void format_char(char *s, va_list list, int fd, int *count)
{
    int arg = va_arg(list, int);
    int diff = 0;
    padding_t *pad = get_pad(s, 0, fd);

    diff = padding_char(pad);
    my_putchar(arg, fd);
    *count += diff + 1;
    free(pad);
    free(s);
}

void format_int(char *s, va_list list, int fd, int *count)
{
    int arg = va_arg(list, int);
    int diff = 0;
    padding_t *pad = get_pad(s, 0, fd);

    pad->diff += (s[0] == '+') ? -1 : 0;
    pad->s += (s[0] == '+') ? 1 : 0;
    diff = padding_nbr(pad, 10, arg);
    if (s[0] == '+' && arg >= 0)
        write(fd, "+", 1);
    my_put_nbr(arg, fd);
    *count += diff + my_nbrlen(arg, 10);
    free(pad);
    free(s);
}

void format_str(char *s, va_list list, int fd, int *count)
{
    char *arg = va_arg(list, char *);
    int diff = 0;
    padding_t *pad = get_pad(s, 0, fd);

    diff = padding_str(pad, arg);
    my_putstr(arg, fd);
    *count += diff + my_strlen(arg);
    free(pad);
    free(s);
}

void format_unsigned(char *s, va_list list, int fd, int *count)
{
    unsigned int x = va_arg(list, unsigned int);
    int diff = 0;
    padding_t *pad = get_pad(s, 0, fd);

    pad->diff += (s[0] == '+') ? -1 : 0;
    pad->s += (s[0] == '+') ? 1 : 0;
    diff = padding_nbr(pad, 10, x);
    if (s[0] == '+')
        write(fd, "+", 1);
    my_put_nbr((long)x, fd);
    *count += diff + my_nbrlen(x, 10);
    free(pad);
    free(s);
}

void format_percent(char *s, va_list list, int fd, int *count)
{
    (void)list;
    (void)count;
    padding_t *pad = get_pad(s, 0, fd);

    padding_char(pad);
    my_putchar('%', fd);
    free(pad);
    free(s);
}
