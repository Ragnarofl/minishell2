/*
** EPITECH PROJECT, 2018
** test_my_strcmp.c
** File description:
** simon-perraud
*/

#include <unistd.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (!s1 || !s2)
        return (1);
    for (int i = 0; (s1[i] && s2[i]) || i < n; i++)
        if (s1[i] != s2[i])
            return (1);
    return (0);
}
