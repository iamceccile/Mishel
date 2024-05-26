/*
** EPITECH PROJECT, 2024
** shell programming
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/imports.h"

void check_exit(char *buffer)
{
    if (my_strcmp(buffer, "exit") == 0) {
        free(buffer);
        my_putstr("exit\n");
        exit(0);
    }
}

void prompt(char **env)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    char cwd[1024];

    while (1) {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            mini_printf("%s $> ", cwd);
        }
        if (getline(&buffer, &bufsize, stdin) == -1) {
            break;
        }
        if (buffer[my_strlen(buffer) - 1] == '\n') {
            buffer[my_strlen(buffer) - 1] = '\0';
        }
        check_exit(buffer);
        execute_command(env, buffer);
    }
    free(buffer);
}

int main(int argc, char **args, char **env)
{
    if (argc > 1) {
        perror("Invalid argument");
        exit(EXIT_FAILURE);
    }
    prompt(env);
    return 0;
}
