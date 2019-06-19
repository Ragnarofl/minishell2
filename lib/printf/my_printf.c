/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

format_fptr_t format_list[12] = {
    {'d', &format_int},
    {'i', &format_int},
    {'c', &format_char},
    {'s', &format_str},
    {'u', &format_unsigned},
    {'b', &format_binary},
    {'o', &format_octal},
    {'x', &format_hexa},
    {'X', &format_mhexa},
    {'S', &format_showstr},
    {'p', &format_pointer},
    {'%', &format_percent}
};

int format_long(char *s, va_list list, int fd, int *count)
{
    long int arg = va_arg(list, long int);
    int diff = 0;
    padding_t *pad = get_pad(s, 0, fd);

    pad->diff += (s[0] == '+') ? -1 : 0;
    pad->s += (s[0] == '+') ? 1 : 0;
    diff = padding_nbr(pad, 10, arg);
    if (s[0] == '+' && arg > 0)
        write(fd, "+", 1);
    my_put_nbr(arg, fd);
    *count += diff + my_nbrlen(arg, 10);
    return (0);
}

int browse_fptr(char *s, va_list list, int fd, int *count)
{
    int i = my_strlen(s) - 1;

    if (!s)
        return (84);
    if (i + 1 >= 2)
        if (s[my_strlen(s) - 2] == 'l' && (s[i] == 'd' || s[i] == 'i'))
            return (format_long(s, list, fd, count));
    for (int x = 0; x < 12; x++)
        if (s[i] == format_list[x].format) {
            format_list[x].function(s, list, fd, count);
            return (1);
        }
    return (0);
}

int error_handling(char *s)
{
    int check = 0;
    for (int i = 0; s[i] != '\0'; i++)
        for (int x = i + 1; s[i] == '%' && IS_NOT_FLAG(s[x]); x++)
            check = (s[x] == '\0') ? 84 : 0;
    return (check);
}

int my_printf(char *s, ...)
{
    int count = 0;
    int check = 0;
    va_list list;
    va_start(list, s);

    if (error_handling(s) == 84) {
        write(2, "Syntax error\n", 14);
        return (84);
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            i++;
            check = browse_fptr(pf_getexpr(s, &i), list, 1, &count);
        } else {
            my_putchar(s[i], 1);
            count += 1;
        }
        if (check == 84)
            return (84);
    }
    return (count);
}
