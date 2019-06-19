/*
** EPITECH PROJECT, 2018
** read_file.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

char *read_file(char *path)
{
    struct stat sb;
    int fd = open(path, O_RDONLY);
    char *file = NULL;
    int ret = 0;

    stat(path, &sb);
    file = malloc(sizeof(char) * (long long int)sb.st_size + 1);
    ret = read(fd, file, sb.st_size);
    if (ret == -1)
        return (NULL);
    file[ret] = 0;
    close(fd);
    return (file);
}
