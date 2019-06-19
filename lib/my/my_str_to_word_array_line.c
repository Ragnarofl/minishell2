/*
** EPITECH PROJECT, 2018
** my_str_to_word_array_line.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

int count_words_line(char const *str)
{
    int count = 0;
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (IS_RETURN && i != 0)
            count++;
        while (IS_RETURN && i < len)
            i++;
    }
    return (count);
}

char **my_str_to_word_array_line(char const *str)
{
    int x = 0;
    int len;
    int wordnumber;
    char **word_array;

    if (!str)
        return (NULL);
    len = my_strlen(str);
    wordnumber = count_words_line(str);
    word_array = malloc(sizeof(char *) * (wordnumber + 1));
    for (int i = 0, j = 0; i <= len && x < wordnumber; i++) {
        if (IS_RETURN && i != 0) {
            word_array[x++] = create_word(str, j, i);
            j = i;
        }
        for (;IS_RETURN; j++, i++);
    }
    word_array[x] = NULL;
    return (word_array);
}
