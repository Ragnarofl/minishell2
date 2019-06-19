/*
** EPITECH PROJECT, 2018
** sh.h
** File description:
** simon-perraud
*/

#ifndef __SH__
#define __SH__

typedef struct node_s
{
    int opt;
    char *str;
    struct node_s *right;
    struct node_s *left;
} node_t;

typedef struct var_s
{
    char *name;
    char *value;
    struct var_s *next;
} var_t;

typedef struct env_s
{
    var_t *first;
} env_t;

typedef struct builtin_fptr_s
{
    char *name;
    void (*function)(env_t *, char **, int, int *);
} builtin_fptr_t;

int error_msg(char *msg);
void check_access(char **buff, env_t *env);
int check_builtin(char *buff, env_t *env, int *);
int core(env_t *env);
env_t *get_env(char **envi);
char *get_var(env_t *env, char *name);
void new_endvar(env_t *env, char *var, char *val);
int replace_var(env_t *env, char *var, char *value);
char **list_to_char2(env_t *env);
int my_exec(char *, env_t *, int *);
void my_exit(env_t *env, char **buff, int ac, int *fd);
void my_env(env_t *env, char **buff, int ac, int *fd);
void my_setenv(env_t *env, char **buff, int ac, int *fd);
void my_unsetenv(env_t *env, char **delet, int ac, int *fd);
void my_cd(env_t *env, char **buff, int ac, int *fd);
int str_alphanum(char *str);
int move_dir(env_t *env, char *buff);
void sig_status(int status);
node_t *get_tree(char *str, env_t *);
void print_tree(node_t *root);
char *remove_sep(char *str, char *sep);
int check_commands(env_t *, node_t *, int fd[2]);
void close_fd(int *fd);
int check_tree(node_t *root, env_t *);
int check_valid_command(char *command, env_t *env);
int get_fd(int fd[2], int newfd[2], node_t *tree, env_t *env);

#endif /* __SH__ */
