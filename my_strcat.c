/*
** EPITECH PROJECT, 2023
** task01
** File description:
** task 01
*/

#include <stdio.h>
#include "../include/imports.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = my_strlen(dest);
    int k = my_strlen(src);

    while (i < k) {
        dest[j + i] = src[i];
        i++;
    }
    dest[j + k] = '\0';
    return dest;
}
