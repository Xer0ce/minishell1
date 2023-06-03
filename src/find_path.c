/*
** EPITECH PROJECT, 2023
** minishell1 [WSL : Ubuntu]
** File description:
** find_path
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

char *find_path(char **command, char **env)
{
    char *dir = NULL;
    char *path = NULL;
    char *test_cmd = NULL;
    int len_path = 0;

    for (len_path = 0; my_strncmp(env[len_path], "PATH=", 5) != 1; len_path++);
    path = malloc(sizeof(char) * (my_strlen(env[len_path]) + 1));
    path = my_strcpy(path, env[len_path]);
    while ((dir = strtok(path, ":")) != NULL) {
        test_cmd = malloc((my_strlen(dir) + my_strlen(command[0]) + 2));
        test_cmd = my_strcpy(test_cmd, dir);
        test_cmd = my_strcat(test_cmd, "/");
        test_cmd = my_strcat(test_cmd, command[0]);
        if (access(test_cmd, F_OK) == 0) {
            command[0] = my_strcpy(command[0], test_cmd);
            return test_cmd;
        }
        free(test_cmd);
        path = NULL;
    } return NULL;
}
