/*
** EPITECH PROJECT, 2023
** task03
** File description:
** task03
*/

#include "../include/imports.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}