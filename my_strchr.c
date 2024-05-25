/*
** EPITECH PROJECT, 2024
** shell programming
** File description:
** minishell1
*/

#include <stdio.h>
#include "imports.h"

char *my_strchr(const char *str, int c)
{
    while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}
