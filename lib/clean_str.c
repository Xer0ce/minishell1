/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-louis.huguet
** File description:
** clean_str
*/

#include "my.h"

void clean_str(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    int j = 0;
    int space = 0;

    for (; str[i] == ' ' || str[i] == '\t'; i++) {}
    for (; i < len; i++) {
        char current = str[i];
        if ((current == ' ' || current == '\t') && !space) {
            str[j++] = ' ';
            space = 1;
        }
        if (current != ' ' && current != '\t') {
            str[j++] = current;
            space = 0;
        }
    }
    if (j > 0 && (str[j - 1] == ' ' || str[j - 1] == '\t'))
        j--;
    str[j] = '\0';
}
