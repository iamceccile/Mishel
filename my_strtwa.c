/*
** EPITECH PROJECT, 2024
** my_strtwa
** File description:
** Main file of My Str to Word Array
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "imports.h"

char **transform(char **saved, char *string, int i, int k)
{
    int j = 0;

    while (string[i] == ' ' || string[i] == '\t')
        i++;
    while (string[i] != '\0' && string[i] != '\n') {
        if (string[i] == ' ' || string[i] == '\t') {
            k = 0;
            if (string[i + 1] != ' ' && string[i + 1] != '\t'
                && string[i + 1] != '\0' && string[i + 1] != '\n') {
                saved[j][k - 1] = '\0';
                j++;
                saved[j] = malloc(sizeof(string));
            }
        } else {
            saved[j][k] = string[i];
            k++;
        }
        i++;
    }
    return saved;
}

char **my_strtwa(char *string)
{
    int i = 0;
    int k = 0;
    char **saved = malloc(sizeof(char *) * 128);

    saved[0] = malloc(sizeof(string));
    saved = transform(saved, string, i, k);
    return saved;
}
