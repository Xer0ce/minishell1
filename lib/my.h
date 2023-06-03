/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H
    char **str_to_word_array (char *str, char separator);
    int my_strlen(char const *str);
    char *my_strcat(char *dest, const char *src);
    int my_strcmp(const char *str1, const char *str2);
    int my_putstr(char const *str);
    int my_printf(const char *restrict format, ...);
    void my_putchar(char c);
    int my_put_nbr(int b);
    int my_putstr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    int my_strncmp(char *str1, char *str2, int n);
    void my_putarray(char **array, char return_line);
    char **array_cpy(char **dest, char **src);
    char **array_cpy_noalloc(char **dest, char **src);
    void clean_str(char *str);

#endif
