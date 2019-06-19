/*
** EPITECH PROJECT, 2018
** buildtin.c
** File description:
** simon-perraud
*/

#include "include/my.h"

void my_exit(env_t *env, char **buff, int ac, int *fd)
{
    (void)env;
    (void)buff;
    (void)ac;
    (void)fd;
    exit(0);
}

void my_env(env_t *env, char **buff, int ac, int *fd)
{
    (void)buff;
    (void)ac;
    if (!fork()) {
        if (fd[0] != 0)
            dup2(fd[0], 0);
        if (fd[1] != 1)
            dup2(fd[1], 1);
        for (var_t *new = env->first; new; new = new->next)
            my_printf("%s=%s\n", new->name, new->value);
        exit(0);
    } else
        close_fd(fd);
}

void my_cd(env_t *env, char **buff, int ac, int *fd)
{
    (void)fd;
    char *pwd;
    int status = 0;

    if (ac > 2) {
        my_dprintf(2, "cd: Too many arguments.\n");
        return;
    }
    if (my_strcmp("-", buff[1]) == 0) {
        pwd = get_var(env, "OLDPWD");
        if (pwd != NULL)
            status = move_dir(env, pwd);
        else
            my_dprintf(2, ": No such file or directory.\n");
    } else if (buff[1] != NULL)
        status = move_dir(env, buff[1]);
    if (ac == 1 || my_strcmp("home", buff[1]) == 0)
        status = move_dir(env, get_var(env, "HOME"));
    if (status == -1)
        my_dprintf(2, "%s: No such file or directory.\n", buff[1]);
}

void my_setenv(env_t *env, char **buff, int ac, int *fd)
{
    (void)fd;
    char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (ac == 2 || ac == 3) {
        if (!is_char_present(buff[1][0], alpha)) {
            my_dprintf(2, "setenv: Variable name must begin with a letter.\n");
            return;
        } else if (str_alphanum(buff[1])) {
            my_dprintf(2, "setenv: Variable name must contain alphanumeric");
            my_dprintf(2, " characters.\n");
            return;
        }
        if (replace_var(env, buff[1], buff[2]))
            new_endvar(env, buff[1], buff[2]);
    } else if (ac == 1)
        for (var_t *new = env->first; new; new = new->next)
            my_printf("%s=%s\n", new->name, new->value);
    if (ac > 3)
        my_dprintf(2, "setenv: Too many arguments.\n");
}

void my_unsetenv(env_t *env, char **del, int ac, __attribute__((unused))int *fd)
{
    var_t *n = env->first;
    var_t *nn = NULL;

    if (ac == 1)
        my_dprintf(2, "unsetenv: Too few arguments.\n");
    if (my_strcmp(del[1], n->name) == 0) {
        env->first = n->next;
        free(n);
        n = env->first;
    }
    (n != NULL) ? nn = n->next : NULL;
    for (; nn != NULL;) {
        if (my_strcmp(del[1], nn->name) == 0) {
            n->next = n->next->next;
            free(nn);
            nn = n->next;
        } else {
            n = n->next;
            (n != NULL) ? nn = n->next : NULL;
        }
    }
}
