/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_
    typedef struct environnement {
        char **env;
        int return_value;
    } env_t;

    int cmd(char **command, env_t *env);
    int cd_cmd(char **command, char **env);
    char **set_env(char **command, char **env);
    char **unset_env(char **env, char *line);
    int too_args(char **command);
    int basic_cmd(char **command, env_t *env);
    int vite(char **temp, env_t *env);
    char *find_path(char **command, char **env);

#endif /* !MYSH_H_ */
