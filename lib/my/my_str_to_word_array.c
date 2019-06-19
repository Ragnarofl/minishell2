/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

int count_words(char const *str, char *separator)
{
    int i;
    int count = 0;
    int len = my_strlen(str);

    for (i = 0; i < len; i++) {
        if (is_char_present(str[i], separator) && i != 0)
            count++;
        while (is_char_present(str[i], separator) && i < len - 1)
            i++;
    }
    if (str[i] == '\0' && is_char_present(str[i - 1], separator))
        count--;
    return (count + 1);
}

char *create_word(char const *str, int j, int i)
{
    int x = 0;
    char *tmp = malloc(sizeof(char) * (i - j) + 1);

    while (j < i) {
        tmp[x] = str[j];
        j++;
        x++;
    }
    tmp[x] = '\0';
    return (tmp);
}

char **my_str_to_word_array(char *str, char *separator)
{
    int x = 0;
    int len;
    int wordnumber;
    char **word_array;

    if (!str)
        return (NULL);
    len = my_strlen(str);
    wordnumber = count_words(str, separator);
    word_array = malloc(sizeof(char *) * (wordnumber + 1));
    for (int i = 0, j = 0; i <= len && x < wordnumber; i++) {
        if ((is_char_present(str[i], separator) && i != 0) || !str[i]) {
            word_array[x++] = create_word(str, j, i);
            j = i;
        }
        for (;is_char_present(str[i], separator) && i < len - 1; j++, i++);
    }
    word_array[x] = NULL;
    return (word_array);
}
