/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** simon-perraud
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i++]);
    return (i - 1);
}
