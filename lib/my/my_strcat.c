/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 1);

    if (src == NULL)
        src = "";
    for (int j = 0; dest[j] != '\0'; j++, i++)
        str[i] = dest[j];
    for (int j = 0; src[j] != '\0'; j++, i++)
        str[i] = src[j];
    str[i] = 0;
    return (str);
}
