/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void set_up_return(env_t *env)
{
    if (env->return_value != 1)
        env->return_value = 0;
}

int loop_ext(env_t *env, size_t n)
{
    char *command = NULL;
    char **temp = NULL;
    int empty = 0;

    if (isatty(0))
        my_putstr("$> ");
    if (getline(&command, &n, stdin) == -1) {
        set_up_return(env);
        return 0;
    }
    if (my_strlen(command) == 1)
        empty = 1;
    if (empty != 1) {
        clean_str(command);
        temp = str_to_word_array(command, ' ');
        empty = vite(temp, env);
    }
    if (empty == 42)
        return 0;
    return 56;
}

int init_loop(env_t *env)
{
    int check = 1;
    size_t n = 0;

    while (check == 1) {
        if (loop_ext(env, n) == 0)
            return 0;
    } return 0;
}

int error_gest(int argc, char **argv)
{
    if (argc != 1)
        return 84;
    if (argv[1] != NULL)
        return 84;
    return 0;
}

int main (int argc, char **argv, char **env)
{
    env_t *envt = NULL;

    envt = malloc(sizeof(env_t));
    envt->env = NULL;
    envt->env = array_cpy(envt->env, env);
    if (error_gest(argc, argv) == 84)
        return 84;
    else
        init_loop(envt);
    return envt->return_value;
}
