/*
** EPITECH PROJECT, 2023
** putchar
** File description:
** my_putchar
*/

#include <unistd.h>
#include "../include/imports.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
