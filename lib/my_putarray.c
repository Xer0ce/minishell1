/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_putarray
*/

#include <stddef.h>
#include "my.h"

void my_putarray(char **array, char return_line)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        if (return_line == '\n')
            my_putchar('\n');
    }
}
