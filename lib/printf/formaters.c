/*
** EPITECH PROJECT, 2018
** flagers.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

void manage_fshowstr(char c, int fd)
{
    write(fd, "\\", 1);
    if (c <= 7)
        write(fd, "00", 2);
    else if (c <= 63)
        write(fd, "0", 1);
    my_putnbr_base(c, "8", 'm', fd);
}

int count_nprint(char *s)
{
    int res = 0;
    for (int i = 0; s[i] != '\0'; i++)
        res += (s[i] < 32 || s[i] == 127) ? 3 : 0;
    return (res);
}

void format_showstr(char *s, va_list list, int fd, int *count)
{
    char *str = va_arg(list, char *);
    int nprint = count_nprint(str);
    int diff = 0;

    if (s[0] == '0' || s[0] == '.') {
        diff = my_getnbr(s + 1) - (my_strlen(s) + nprint);
        print_xchar('0', diff, fd);
    } else if (IS_NUM(s[0])) {
        diff = my_getnbr(s) - (my_strlen(s) + nprint) - 1;
        print_xchar(' ', diff, fd);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126)
            manage_fshowstr(str[i], fd);
        else
            my_putchar(str[i], fd);
    }
    *count += diff + (my_strlen(s) + nprint);
    free(s);
}

void format_pointer(char *s, va_list list, int fd, int *count)
{
    int ptr = va_arg(list, int);
    int diff = 0;

    if (s[0] == '0' || s[0] == '.') {
        diff = my_getnbr(s + 1) - my_nbrlen(ptr, 16) - 2;
        print_xchar('0', diff, fd);
    } else if (IS_NUM(s[0])) {
        diff = my_getnbr(s) - my_nbrlen(ptr, 16) - 2;
        print_xchar(' ', diff, fd);
    }
    write(fd, "0x", 2);
    my_putnbr_base(ptr, "16", 'm', fd);
    *count += diff + my_nbrlen(ptr, 16);
    free(s);
}

void format_float(char *s, va_list list, int fd, int *count)
{
    (void)s;
    (void)list;
    (void)fd;
    (void)count;
}
