/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** set_env
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

char **simple_set_ext(char **command, char **env, int check, int i)
{
    char **stock = NULL;

    if (check < i && check != -1) {
        free(env[check]);
        env[check] = malloc(sizeof(char) * (my_strlen(command[1]) + 2));
        env[check] = my_strcpy(env[check], command[1]);
        env[check] = my_strcat(env[check], "=");
        return env;
    } else {
        stock = malloc(sizeof(char *) * (i + 2));
        stock = array_cpy_noalloc(stock, env);
        stock[i] = malloc(sizeof(char) * (my_strlen(command[1]) + 2));
        stock[i] = my_strcpy(stock[i], command[1]);
        stock[i] = my_strcat(stock[i], "=");
        stock[i + 1] = NULL;
        for (int i = 0; env[i] != NULL; i++)
            free(env[i]);
        free(env);
        return stock;
    }
}

char **simple_set(char **command, char **env)
{
    char **stock = NULL;
    int i = 0;
    int check = -1;

    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], command[1], my_strlen(command[1])) == 1)
            check = i;
    }
    stock = simple_set_ext(command, env, check, i);
    return stock;
}

char **double_set(char **command, char **env)
{
    char *s = NULL;
    int i = 0;
    int check = -1;

    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], command[1], my_strlen(command[1])) == 1)
            check = i;
    }
    if (check < i && check != -1)
        i = check;
    s = malloc(sizeof(char) *
    (my_strlen(env[i]) + my_strlen(command[2]) + 1));
    s = my_strcpy(s, env[i]);
    s = my_strcat(s, command[2]);
    free(env[i]);
    env[i] = malloc(sizeof(char) * (my_strlen(s) + 1));
    env[i] = my_strcpy(env[i], s);
    return env;
}

char **set_env(char **command, char **env)
{
    int i = 0;

    if (command[1] == NULL) {
        my_putarray(env, '\n');
        return env;
    }
    if (command[2] == NULL)
        env = simple_set(command, env);
    if (command[2] != NULL && command[3] == NULL) {
        env = simple_set(command, env);
        env = double_set(command, env);
    }
    for (i = 0; command[i] != NULL; i++);
    if (i > 3)
        my_putstr("setenv: Too many arguments.\n");
    return env;
}

int basic_cmd(char **command, env_t *env)
{
    if (my_strcmp(command[0], "exit") == 1)
        exit(env->return_value);
    if (my_strcmp(command[0], "cd") == 1) {
        cd_cmd(command, env->env);
        env->return_value = 0;
        return 0;
    }
    if (my_strcmp(command[0], "env") == 1) {
        my_putarray(env->env, '\n');
        env->return_value = 0;
        return 0;
    }
    if (my_strcmp(command[0], "pwd") == 1) {
        my_putstr(getcwd(NULL, 0));
        my_putchar('\n');
        env->return_value = 0;
        return 0;
    }
    return 2;
}
