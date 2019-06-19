/*
** EPITECH PROJECT, 2018
** printf.h
** File description:
** simon-perraud
*/

#ifndef __PRINTF__
#define __PRINTF__

#define IS_NOT_FLAG(c)  (is_char_present(c, "discuboxXSp%") != 1)
#define IS_NUM(c)       (is_char_present(c, "123456789") == 1)

typedef struct padding_s
{
    char *s;
    int diff;
    int fd;
    int type;
} padding_t;

typedef struct format_fptr_s
{
    char format;
    void (*function)(char *, va_list, int, int *);
} format_fptr_t;

int my_dprintf(int fd, char *s, ...);
int browse_fptr(char *, va_list, int, int *);
int error_handling(char *);
void print_xchar(char, int, int);
char *pf_getexpr(char *, int *);
void format_char(char *, va_list, int, int *);
void format_int(char *, va_list, int, int *);
void format_str(char *, va_list, int, int *);
void format_unsigned(char *, va_list, int, int *);
void format_binary(char *, va_list, int, int *);
void format_octal(char *, va_list, int, int *);
void format_hexa(char *, va_list, int, int *);
void format_mhexa(char *, va_list, int, int *);
void format_showstr(char *, va_list, int, int *);
void format_percent(char *, va_list, int, int *);
void format_pointer(char *, va_list, int, int *);
int padding_char(padding_t *pad);
int padding_nbr(padding_t *pad, int base, long int arg);
int padding_str(padding_t *pad, char *arg);
padding_t *get_pad(char *s, int diff, int fd);

#endif /* __PRINTF__ */
