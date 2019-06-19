/*
** EPITECH PROJECT, 2018
** flags.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

padding_t *create_pad(char *s, int diff, int fd, int type)
{
    padding_t *pad = malloc(sizeof(*pad));

    if (!pad)
        return (NULL);
    pad->s = s;
    pad->diff = diff;
    pad->fd = fd;
    pad->type = type;
    return (pad);
}

padding_t *get_pad(char *s, int diff, int fd)
{
    padding_t *pad;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0' || s[i] == '.') {
            pad = create_pad(s, diff, fd, 0);
            return (pad);
        } else if (IS_NUM(s[i])) {
            pad = create_pad(s, diff, fd, 1);
            return (pad);
        }
    }
    return (create_pad(s, 0, fd, -1));
}
