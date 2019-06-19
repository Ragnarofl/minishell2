/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** simon-perraud
*/

int my_swap(int *a, int *b)
{
    int tmp = *b;

    *b = *a;
    *a = tmp;
    return (0);
}
