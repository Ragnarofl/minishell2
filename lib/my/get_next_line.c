/*
** EPITECH PROJECT, 2018
** gnl.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

char *get_return(char **remain)
{
    int x = 0;
    int j = 0;
    char *str;
    char *tmp = *remain;

    for (; tmp[x] != '\n'; x++);
    str = malloc(sizeof(char) * x + 1);
    for (int j = 0; j < x; j++)
        str[j] = tmp[j];
    str[x] = 0;
    *remain = malloc(sizeof(char) * my_strlen(*remain) - x++);
    for (; tmp[x] != '\0'; x++, j++)
        (*remain)[j] = tmp[x];
    (*remain)[j] = 0;
    return (str);
}

char *get_next_line(int fd)
{
    static char *remain = "\0";
    char *str = malloc(sizeof(char) * READ_SIZE + 1);
    static int check = 0;
    int i = 0;

    if (check == 1 && is_char_present('\n', remain) != 1)
        return (NULL);
    for (; is_char_present('\n', remain) != 1;) {
        i = read(fd, str, READ_SIZE);
        if (i == -1)
            return (NULL);
        if (i < READ_SIZE)
            check = 1;
        str[i] = 0;
        remain = my_strcat(remain, str);
    }
    str = get_return(&remain);
    return (str);
}
