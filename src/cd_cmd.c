/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** cd_cmd
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

void set_env_oldpwd(char **env, char *pwd)
{
    int i = 0;

    for (i = 0; my_strncmp(env[i], "OLDPWD", 6) != 1; i++);
    free(env[i]);
    env[i] = malloc(my_strlen(pwd) + 8);
    env[i] = my_strcpy(env[i], "OLDPWD=");
    env[i] = my_strcat(env[i], pwd);
}

void set_env_pwd(char **env, char *pwd)
{
    int i = 0;

    for (i = 0; my_strncmp(env[i], "PWD", 6) != 1; i++);
    free(env[i]);
    env[i] = malloc(my_strlen(pwd) + 5);
    env[i] = my_strcpy(env[i], "PWD=");
    env[i] = my_strcat(env[i], pwd);
}

void cd_cmd_ext(char **env)
{
    char *pwd = NULL;
    int i = 0;
    int j = 0;

    pwd = getcwd(pwd, 0);
    set_env_oldpwd(env, pwd);
    free(pwd);
    for (i = 0; my_strncmp(env[i], "HOME", 4) != 1; i++);
    pwd = malloc(my_strlen(env[i]) - 4);
    for (j = 5; env[i][j] != '\0'; j++)
        pwd[j - 5] = env[i][j];
    pwd[j - 5] = '\0';
    chdir(pwd);
    set_env_pwd(env, pwd);
    free(pwd);
}

void cd_cmd_content(char **command, char **env, char *pwd, char *pwd2)
{
    int i = 0;

    if (my_strcmp(command[1], "-") == 1) {
        for (i = 0; my_strncmp(env[i], "OLDPWD", 6) != 1; i++);
        pwd = malloc(my_strlen(env[i]) - 6);
        for (int j = 7; env[i][j] != '\0'; j++)
            pwd[j - 7] = env[i][j];
        pwd[my_strlen(env[i]) - 7] = '\0';
        pwd2 = getcwd(pwd2, 0);
        set_env_oldpwd(env, pwd2);
        chdir(pwd); set_env_pwd(env, pwd);
    } else {
        pwd = getcwd(pwd, 0);
        if (chdir(command[1]) == -1) {
            my_printf("%s: No such file or directory.\n", command[1]);
        } else {
            set_env_oldpwd(env, pwd); pwd2 = getcwd(pwd2, 0);
            set_env_pwd(env, pwd2);
        }
    }
}

int cd_cmd(char **command, char **env)
{
    char *pwd = NULL;
    char *pwd2 = NULL;

    if (command[1] != NULL) {
        cd_cmd_content(command, env, pwd, pwd2);
    } else
        cd_cmd_ext(env);
    return 0;
}
