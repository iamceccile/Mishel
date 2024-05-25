/*
** EPITECH PROJECT, 2024
** shell programming
** File description:
** minishell1
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include "../include/imports.h"

void check_pwd(void)
{
    char cwd[256];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
            mini_printf("%s\n", cwd);
        } else {
            perror("getcwd() error");
        }
}

static void check_cd3(char *path)
{
    if (chdir(path) != 0) {
        perror("chdir() error");
    }
}



static void check_cd2()
{
    if (chdir("..") != 0) {
        perror("chdir() error");
    }
}

void check_cd(char *path, char *buffer)
{
    char **res = my_strtwa(buffer);

    if (res[1] != NULL) {
        if (*res[1] == *"..") {
            check_cd2();
        } else {
            check_cd3(path);
        }
    } else
        mini_printf("cd: argument manquant\n");
}
