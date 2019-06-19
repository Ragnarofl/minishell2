/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** simon-perraud
*/

#ifndef __MY__
#define __MY__

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include "printf.h"
#include "get_next_line.h"
#include "sh.h"

#define IS_NOT_NUM (str[i] < '0' || str[i] > '9')
#define IS_NOT_MAJ_ALPHA (str[i] < 'A' || str[i] > 'Z')
#define IS_NOT_ALPHA (str[i] < 'a' || str[i] > 'z')
#define IS_NOT_ALPHANUM IS_NOT_NOT_NUM && IS_NOT_MAJ_ALPHA && IS_NOT_ALPHA
#define SEPARATOR "\n\t!\"#$%&'()*+,-./:;<=>?@[]\\^_`{|}~ "
#define IS_RETURN (str[i] == 10)

void my_putchar(char, int);
long int my_put_nbr(long int, int);
long int my_putnbr_base(long int, char *, char, int);
int my_swap(int *, int *);
int my_putstr(char *, int);
int my_strlen(char const *);
int my_nbrlen(long int, int);
long int my_getnbr(char const*);
char *my_itoa(int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
void my_show_word_array(char * const *tab);
int my_showstr(char const *, int);
char *my_strcat(char *, char *);
char *my_strncat(char *, char const *, int);
char *my_malloc_str(char *, int);
char *read_file(char *);
char **my_str_to_word_array(char *, char *);
char **my_str_to_word_array_line(char const *);
char *create_word(char const *str, int j, int i);
int is_char_present(char c, char *);
int my_printf(char *s, ...);
char *get_next_line(int);

#endif /* __MY__ */
