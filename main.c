/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** simon-perraud
*/

#include "include/my.h"

int error_msg(char *msg)
{
    my_dprintf(2, "%s\n", msg);
    return (84);
}

void handle_sigint(int sig)
{
    (void)sig;

    if (isatty(0))
        my_printf("\n\033[1;31m%s\033[0m> ", getcwd(NULL, 255));
}

int main(int ac, char **av, char **env)
{
    env_t *environ = get_env(env);
    errno = 0;

    (void)ac;
    (void)av;
    signal(SIGINT, handle_sigint);
    for (; 1;)
        core(environ);
    return (0);
}
