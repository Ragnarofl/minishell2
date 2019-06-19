/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** simon-perraud
*/

#include "include/my.h"

int check_tree(node_t *root, env_t *env)
{
    int check = 0;

    if (root->left != NULL)
        check = check_tree(root->left, env);
    if (root->str)
        check = check_valid_command(root->str, env);
    if (root->right != NULL)
        check = check_tree(root->right, env);
    return (check);
}

void close_fd(int *fd)
{
    if (fd[0] > 2)
        close(fd[0]);
    if (fd[1] > 2)
        close(fd[1]);
}

char *clean_str(char *str, char *new, char *sep)
{
    for (int i = 0, j = 0, check = 0, checker = 0; str[i]; i++) {
        if (is_char_present(str[i], sep)) {
            check = 1;
            continue;
        }
        if (is_char_present(str[i], "|><;")) {
            new[j++] = str[i];
            checker = 1;
            continue;
        }
        if (check == 1 && checker == 0) {
            new[j++] = ' ';
            i--;
        } else
            new[j++] = str[i];
        check = 0;
        checker = 0;
    }
    return (new);
}

char *remove_sep(char *str, char *sep)
{
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *final = NULL;

    for (int i = 0; i < my_strlen(str); i++)
        new[i] = 0;
    new = clean_str(str, new, sep);
    final = malloc(sizeof(char) * my_strlen(new) + 1);
    final[my_strlen(new)] = 0;
    for (int i = 0; new[i]; i++)
        final[i] = new[i];
    free(new);
    return (final);
}
