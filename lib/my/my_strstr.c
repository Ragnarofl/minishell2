/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** simon-perraud
*/

#include <unistd.h>

char *my_strstr(char *str, char const *to_find)
{
    int check = 0;

    if (!str || !to_find)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; str[i + j] == to_find[j]; j++)
            check = to_find[j + 1] == '\0' ? i : 0;
    }
    return (check != 0 ? str + check : NULL);
}
