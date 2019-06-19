/*
** EPITECH PROJECT, 2018
** core.c
** File description:
** simon-perraud
*/

#include "include/my.h"

int check_commands(env_t *env, node_t *tree, int fd[2])
{
    int newfd[2] = {0, 1};

    get_fd(fd, newfd, tree, env);
    if (tree->right && tree->opt < 1)
        check_commands(env, tree->right, newfd);
    if (tree->str)
        if (!check_builtin(tree->str, env, fd))
            my_exec(tree->str, env, fd);
    if (tree->left && tree->opt != 1)
        check_commands(env, tree->left, fd);
    return (0);
}

int manage_commands(env_t *env, node_t *tree)
{
    check_commands(env, tree->left, (int [2]){0, 1});
    if (tree->right != NULL)
        manage_commands(env, tree->right);
    return (0);
}

int core(env_t *env)
{
    char *buff = NULL;
    size_t zero = 0;
    node_t *tree = NULL;

    if (isatty(0))
        my_printf("\033[1;31m%s\033[0m> ", getcwd(NULL, 255));
    if (getline(&buff, &zero, stdin) == -1) {
        my_printf(isatty(0) ? "exit\n" : "");
        exit(0);
    }
    if (buff[0] == '\n')
        return (0);
    tree = get_tree(buff, env);
    if (tree)
        manage_commands(env, tree);
    return (0);
}
