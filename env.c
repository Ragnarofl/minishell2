/*
** EPITECH PROJECT, 2018
** env.c
** File description:
** simon-perraud
*/

#include "include/my.h"

char *get_var(env_t *env, char *name)
{
    for (var_t *new = env->first; new; new = new->next) {
        if (my_strcmp(name, new->name) == 0)
            return (new->value);
    }
    return (NULL);
}

int replace_var(env_t *env, char *var, char *value)
{
    for (var_t *new = env->first; new; new = new->next)
        if (my_strcmp(var, new->name) == 0) {
            new->value = value;
            return (0);
        }
    return (1);
}

void new_endvar(env_t *env, char *var, char *val)
{
    var_t *new = malloc(sizeof(*new));
    var_t *n = env->first;

    for (; n->next != NULL; n = n->next);
    if (!new)
        exit(84);
    new->name = var;
    new->value = val;
    new->next = NULL;
    n->next = new;
}

void new_var(env_t *env, char *var)
{
    int i = 0;
    var_t *new = malloc(sizeof(*new));

    if (!new)
        exit(84);
    for (; var[i] != '='; i++);
    new->name = malloc(sizeof(char) * (i + 1));
    for (int j = 0; j < i; j++)
        new->name[j] = var[j];
    new->name[i++] = 0;
    new->value = malloc(sizeof(char) * (my_strlen(var) - i + 1));
    new->value[my_strlen(var) - i] = 0;
    for (int j = 0; var[i]; j++, i++)
        new->value[j] = var[i];
    new->next = env->first;
    env->first = new;
}

env_t *get_env(char **envi)
{
    int i = 0;
    env_t *env = malloc(sizeof(*env));
    char *path1 = "/home/simon-perraud/bin:/home/simon-perraud/.local/bin";
    char *path2 = my_strcat(path1, ":/usr/local/sbin:/usr/local/bin:/usr/sbin");
    char *path3 = ":/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
    char *path = my_strcat(path2, path3);

    if (!env)
        exit(84);
    if (!envi[0]) {
        new_var(env, "HOME=/home/simon-perraud");
        new_var(env, my_strcat("PWD=", getcwd(NULL, 255)));
        new_var(env, "OLDPWD=/home/simon-perraud");
        new_var(env, my_strcat("PATH=", path));
        return (env);
    }
    env->first = NULL;
    for (; envi[i + 1]; i++);
    for (; i >= 0; i--)
        new_var(env, envi[i]);
    return (env);
}
