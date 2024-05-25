/*
** EPITECH PROJECT, 2024
** Epitech my_strdup function
** File description:
** Day08
*/
#include <stdlib.h>
#include "imports.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (i < my_strlen(src)) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
