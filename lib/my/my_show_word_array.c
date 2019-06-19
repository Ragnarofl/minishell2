/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

void my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i], 1);
        write(1, "\n", 1);
    }
}
