/*
** EPITECH PROJECT, 2023
** minishell1 [WSL : Ubuntu]
** File description:
** unset_env
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int too_args(char **command)
{
    if (command[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    }
    return 0;
}

char **unset_env_cpy_array(char **env, char **stock, int j, char *line)
{
    int i = 0;
    int check = 0;

    for (i = 0; my_strncmp(env[i], line, my_strlen(line)) != 1; i++);
    while (env[j] != NULL) {
        if (j != i) {
            stock[check] = malloc(my_strlen(env[j]) + 1);
            stock[check] = my_strcpy(stock[check], env[j]);
            j++;
            check++;
        } else
            j++;
    }
    stock[check] = NULL;
    return stock;
}

char **unset_env(char **env, char *line)
{
    int i = 0;
    int j = 0;
    int len = 0;
    int check = 0;
    char **stock = NULL;

    for (check = 0; env[check] != NULL; check++);
    for (i = 0; my_strncmp(env[i], line, my_strlen(line)) != 1; i++) {
        if (i == check - 1)
            return env;
    }
    if (env[i][my_strlen(line)] == '=') {
        for (len = 0; env[len] != NULL; len++);
        stock = malloc(sizeof(char *) * (len));
        stock = unset_env_cpy_array(env, stock, j, line);
        for (int k = 0; env[k] != NULL; k++)
            free(env[k]);
        free(env);
        return stock;
    } return env;
}

int vite(char **temp, env_t *env)
{
    if (cmd(temp, env) == 42)
        return 42;
    return 0;
}
