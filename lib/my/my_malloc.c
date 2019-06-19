/*
** EPITECH PROJECT, 2018
** my_malloc.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

char *my_malloc_str(char *mem, int lenght)
{
    mem = malloc(sizeof(char) * lenght);

    for (int i = 0; i < lenght; i++)
        mem[i] = 0;
    return (mem);
}
