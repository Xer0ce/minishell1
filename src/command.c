/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** exit
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void child_content(char **command, env_t *env)
{
    char *path = NULL;

    if (command[0][0] != '.' || command[0][1] != '/') {
        path = find_path(command, env->env);
        if (path != NULL)
            execve(path, command, env->env);
        else {
            my_printf("%s: Command not found.\n", command[0]);
            exit(1);
        }
    } else {
        if (execve(command[0], command, env->env) == -1) {
            my_printf("%s: Command not found.\n", command[0]);
            exit(1);
        }
    }
}

void normal_end(int status, env_t *env)
{
    if (WIFEXITED(status)) {
        if (WIFEXITED(status))
            env->return_value = WEXITSTATUS(status);
    }
}

void child_process(char **command, env_t *env)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
        child_content(command, env);
    else {
        waitpid(pid, &status, 0);
        normal_end(status, env);
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV) {
            my_printf("Segmentation fault (core dumped)\n");
            env->return_value = 1;
        }
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGFPE) {
            my_printf("Floating exception (core dumped)\n");
            env->return_value = 1;
        }
    }
}

int cmd(char **command, env_t *env)
{
    if (basic_cmd(command, env) == 0)
        return 0;
    if (my_strcmp(command[0], "setenv") == 1) {
        env->env = set_env(command, env->env);
        env->return_value = 0;
        return 0;
    }
    if (my_strcmp(command[0], "unsetenv") == 1) {
        if (too_args(command) == 1)
            return 0;
        env->env = unset_env(env->env, command[1]);
        env->return_value = 0;
        return 0;
    }
    child_process(command, env);
    return 0;
}
