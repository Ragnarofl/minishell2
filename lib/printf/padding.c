/*
** EPITECH PROJECT, 2018
** padding.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

int padding_char(padding_t *pad)
{
    if (!pad || pad->type == -1)
        return (0);
    if (pad->type == 0) {
        pad->diff += my_getnbr(pad->s + 1) - 1;
        print_xchar('0', pad->diff, pad->fd);
    } else if (pad->type == 1) {
        pad->diff += my_getnbr(pad->s) - 1;
        print_xchar(' ', pad->diff, pad->fd);
    }
    return (pad->diff);
}

int padding_nbr(padding_t *pad, int base, long int arg)
{
    if (!pad || pad->type == -1)
        return (0);
    if (arg < 0)
        pad->diff -= 1;
    if (pad->type == 0) {
        pad->diff += my_getnbr(pad->s + 1) - my_nbrlen(arg, base);
        print_xchar('0', pad->diff, pad->fd);
    } else if (pad->type == 1) {
        pad->diff += my_getnbr(pad->s) - my_nbrlen(arg, base);
        print_xchar(' ', pad->diff, pad->fd);
    }
    return (pad->diff);
}

int padding_str(padding_t *pad, char *arg)
{
    if (!pad || pad->type == -1)
        return (0);
    if (pad->type == 0) {
        pad->diff += my_getnbr(pad->s + 1) - my_strlen(arg);
        print_xchar('0', pad->diff, pad->fd);
    } else if (pad->type == 1) {
        pad->diff += my_getnbr(pad->s) - my_strlen(arg);
        print_xchar(' ', pad->diff, pad->fd);
    }
    return (pad->diff);
}
