/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** simon-perraud
*/

#include "include/my.h"

int str_alphanum(char *str)
{
    for (int i = 0; str[i]; i++)
        if (is_char_present(str[i], SEPARATOR))
            return (1);
    return (0);
}

int move_dir(env_t *env, char *buff)
{
    int status = 0;

    if (access(buff, X_OK) == -1) {
        my_dprintf(2, "%s: Permission denied.\n", buff);
        return (-2);
    }
    replace_var(env, "OLDPWD", getcwd(NULL, 255));
    status = chdir(buff);
    replace_var(env, "PWD", getcwd(NULL, 255));
    return (status);
}

void sig_status(int status)
{
    int sig = 0;

    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV)
            sig = my_printf("Segmentation fault");
        if (WTERMSIG(status) == SIGFPE)
            sig = my_printf("Floating exception");
        if (WTERMSIG(status) == SIGABRT)
            sig = my_printf("Abort");
        my_printf((WCOREDUMP(status) && sig != 0) ? " (core dumped)\n" : "\n");
    }
}

char **list_to_char2(env_t *env)
{
    int i = 0;
    int len = 0;
    char **tmp;

    for (var_t *n = env->first; n; n = n->next, len++);
    tmp = malloc(sizeof(char *) * (len + 1));
    for (var_t *new = env->first; new; new = new->next, i++)
        tmp[i] = my_strcat(my_strcat(new->name, "="), new->value);
    tmp[i] = NULL;
    return (tmp);
}
