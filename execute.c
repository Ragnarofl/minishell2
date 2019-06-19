/*
** EPITECH PROJECT, 2018
** core.c
** File description:
** simon-perraud
*/

#include "include/my.h"

static const builtin_fptr_t builtins[] = {
    {"exit", &my_exit},
    {"cd", &my_cd},
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {"env", &my_env}
};

void check_access(char **buff, env_t *env)
{
    char *folder;
    char *path = get_var(env, "PATH");
    char **folders = my_str_to_word_array(path, ":");
    int check = 0;

    for (int i = 0; folders[i]; i++) {
        folder = my_strcat(folders[i], my_strcat("/", buff[0]));
        check = access(folder, F_OK);
        if (check == 0) {
            buff[0] = folder;
            return;
        }
    }
}

int my_exec(char *buff, env_t *env, int *fd)
{
    int status = 0;
    char **path = my_str_to_word_array(buff, " \n\t");

    if (!fork()) {
        if (fd[0] != 0)
            dup2(fd[0], 0);
        if (fd[1] != 1)
            dup2(fd[1], 1);
        check_access(path, env);
        execve(path[0], path, list_to_char2(env));
        exit(84);
    } else {
        wait(&status);
        sig_status(status);
        close_fd(fd);
    }
    return (1);
}

int check_builtin(char *buff, env_t *env, int *fd)
{
    int ac = 0;
    char **path = my_str_to_word_array(buff, " \n\t");

    for (; path[ac]; ac++);
    for (int i = 0; i < 5; i++)
        if (my_strcmp(builtins[i].name, path[0]) == 0) {
            builtins[i].function(env, path, ac, fd);
            return (1);
        }
    return (0);
}

int get_fd(int fd[2], int newfd[2], node_t *tree, env_t *env)
{
    int pipefd[2];

    fd[1] = (tree->opt == 2) ? open(tree->right->str, O_WRONLY | O_CREAT |
    O_TRUNC, S_IRWXU) : fd[1];
    fd[1] = (tree->opt == 3) ? open(tree->right->str, O_WRONLY | O_CREAT |
    O_APPEND, S_IRWXU) : fd[1];
    fd[0] = (tree->opt == 4) ? open(tree->right->str, O_RDONLY) : fd[0];
    newfd[0] = 0;
    newfd[1] = 1;
    if (tree->opt == 1) {
        pipe(pipefd);
        fd[1] = pipefd[1];
        newfd[0] = pipefd[0];
        if (!fork()) {
            close(fd[1]);
            check_commands(env, tree->right, newfd);
            exit(0);
        } else {
            close(newfd[0]);
            check_commands(env, tree->left, fd);
        }
        wait(NULL);
    }
    return (0);
}
