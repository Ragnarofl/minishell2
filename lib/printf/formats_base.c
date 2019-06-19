/*
** EPITECH PROJECT, 2018
** flags.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

void format_binary(char *s, va_list list, int fd, int *count)
{
    unsigned int u = va_arg(list, int);
    int diff = 0;
    padding_t *pad = get_pad(s, 0, fd);

    diff = padding_nbr(pad, 2, u);
    my_putnbr_base(u, "2", 'm', fd);
    *count += diff + my_nbrlen(u, 2);
    free(pad);
    free(s);
}

void format_octal(char *s, va_list list, int fd, int *count)
{
    unsigned int u = va_arg(list, unsigned int);
    int diff = 0;
    padding_t *pad = get_pad(s, 0, fd);

    pad->diff += (s[0] == '#') ? -1 : 0;
    pad->s += (s[0] == '#') ? 1 : 0;
    diff += padding_nbr(pad, 8, u);
    if (s[0] == '#')
        write(fd, "0", 1);
    my_putnbr_base(u, "8", 'm', fd);
    *count += diff + my_nbrlen(u, 8);
    free(pad);
    free(s);
}

void format_hexa(char *s, va_list list, int fd, int *count)
{
    unsigned int u = va_arg(list, unsigned int);
    int diff = 0;
    padding_t *pad = get_pad(s, 0, fd);

    pad->diff += (s[0] == '#') ? -2 : 0;
    pad->s += (s[0] == '#') ? 1 : 0;
    diff += padding_nbr(pad, 16, u);
    if (s[0] == '#')
        write(fd, "0x", 2);
    my_putnbr_base(u, "16" , 'm', fd);
    *count += diff + my_nbrlen(u, 16);
    free(pad);
    free(s);
}

void format_mhexa(char *s, va_list list, int fd, int *count)
{
    unsigned int u = va_arg(list, unsigned int);
    int diff = 0;
    padding_t *pad = get_pad(s, 0, fd);

    pad->diff += (s[0] == '#') ? -2 : 0;
    pad->s += (s[0] == '#') ? 1 : 0;
    diff += padding_nbr(pad, 16, u);
    if (s[0] == '#')
        write(fd, "0X", 2);
    my_putnbr_base(u, "16", 'M', fd);
    *count += diff + my_nbrlen(u, 16);
    free(pad);
    free(s);
}
