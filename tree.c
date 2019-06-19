/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** simon-perraud
*/

#include "include/my.h"

int check_valid_command(char *str, env_t *env)
{
    char *folder;
    char *builtins[4] = {"cd", "setenv", "unsetenv", "exit"};
    char **command = my_str_to_word_array(str, " \n\t");
    char **folders = my_str_to_word_array(get_var(env, "PATH"), ":");

    if (access(str, X_OK) != 0 && access(str, F_OK) == 0) {
        my_dprintf(2, "%s: Permission denied.\n", str);
        return (1);
    }
    for (int i = 0; i < 4; i++)
        if (my_strcmp(builtins[i], command[0]) == 0)
            return (0);
    for (int i = 0; folders[i]; i++) {
        folder = my_strcat(folders[i], my_strcat("/", command[0]));
        if (access(folder, X_OK) == 0)
            return (0);
    }
    if (!access(str, F_OK))
        return (0);
    my_dprintf(2, "%s: Command not found.\n", str);
    return (1);
}

int check_opt(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ';')
            return (0);
        if (str[i] == '|')
            return (1);
        if (str[i] == '>')
            return (str[i + 1] == '>' ? 3 : 2);
        if (str[i] == '<')
            return (str[i + 1] == '<' ? 5 : 4);
    }
    return (0);
}

node_t *create_node(char *str)
{
    int offset = 1;
    node_t *node = malloc(sizeof(*node));
    char **commands = my_str_to_word_array(str, "|<>");

    node->opt = check_opt(str);
    if (node->opt == 0) {
        node->str = str;
        node->left = NULL;
        node->right = NULL;
    } else {
        if (node->opt == 3 || node->opt == 5)
            offset = 2;
        node->str = NULL;
        node->left = create_node(commands[0]);
        node->right = create_node(str + my_strlen(commands[0]) + offset);
    }
    return (node);
}

node_t *make_tree(char **commands, int i)
{
    node_t *root = malloc(sizeof(*root));

    root->opt = 0;
    root->str = NULL;
    root->left = create_node(commands[i]);
    if (commands[i + 1])
        root->right = make_tree(commands, i + 1);
    else
        root->right = NULL;
    return (root);
}

node_t *get_tree(char *str, env_t *env)
{
    str = remove_sep(str, " \n");
    char **commands = my_str_to_word_array(str, ";");
    node_t *tree = make_tree(commands, 0);

    if (check_tree(tree, env))
        return (NULL);
    return (tree);
}
