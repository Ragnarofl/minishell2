/*
** EPITECH PROJECT, 2018
** my_get_nbr.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

int is_char_present(char c, char *cmp)
{
    for (int i = 0; cmp[i]; i++) {
        if (c == cmp[i])
            return (1);
    }
    return (0);
}

long int my_getnbr(char const *str)
{
    int sign = 1;
    long int nbr = 0;

    if (!str)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            sign *= -1;
        if ((is_char_present(str[i], "0123456789-+") != 1))
            return (0);
        for (; str[i] >= '0' && str[i] <= '9' && nbr <= INT_MAX; i++) {
            nbr *= 10;
            nbr += (str[i] - 48);
        }
        if (nbr != 0)
            return (nbr);
    }
    return (nbr);
}
