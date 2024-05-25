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
extern char **environ;

static char **split_commands(char *buffer, const char *delimiter)
{
    char **commands = malloc(64 * sizeof(char *));
    char *command;
    int i = 0;

    command = strtok(buffer, delimiter);
    while (command != NULL) {
        commands[i] = command;
        i++;
        command = strtok(NULL, delimiter);
    }
    commands[i] = NULL;
    return commands;
}

static void execvp_custom2(const char *file, char *path, char *const argv[])
{
    char *token = strtok(path, ":");
    int found = 0;
    char full_path[1024];

    while (token != NULL) {
        my_strcpy(full_path, token);
        my_strcat(full_path, "/");
        my_strcat(full_path, file);
        if (access(full_path, X_OK) == 0) {
            execve(full_path, argv, environ);
            perror("execve");
            return;
        }
        token = strtok(NULL, ":");
    }
    perror("Aucun chemin valide trouvé pour execve");
}

static int execvp_custom(const char *file, char *const argv[])
{
    char *path;
    char *env_path = getenv("PATH");

    if (file == NULL || argv == NULL || env_path == NULL) {
        perror("execvp_custom");
        return -1;
    }
    if (access(file, X_OK) == 0) {
        execve(file, argv, environ);
        perror("execve");
        return -1;
    }
    path = my_strdup(env_path);
    if (path == NULL) {
        perror("strdup");
        return -1;
    }
    execvp_custom2(file, path, argv);
    free(path);
    return -1;
}

void execute_piped_commands2(char **commands, int fd_in, int pipefd[2])
{
    char **res = split_commands(*commands, " ");

    dup2(fd_in, 0);
    if (*(commands + 1) != NULL) {
        dup2(pipefd[1], 1);
        }
        close(pipefd[0]);
        execvp_custom(res[0], res);
        perror("execvp");
        exit(EXIT_FAILURE);
}

void create_wait(char **commands, int pipefd[2], int fd_in, pid_t pid)
{
    if (pid != 0) {
        wait(NULL);
        close(pipefd[1]);
        fd_in = pipefd[0];
        commands++;
        fork;
    }
}

void execute_piped_commands(char **commands)
{
    int pipefd[2];
    pid_t pid;
    int fd_in = 0;

    while (*commands != NULL) {
        pipe(pipefd);
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            execute_piped_commands2(commands, fd_in, pipefd);
        }
        if (pid != 0) {
            wait(NULL);
            close(pipefd[1]);
            fd_in = pipefd[0];
            commands++;
        }
    }
}

void execute_command(char **env, char *buffer)
{
    char **commands = split_commands(buffer, ";");
    char **piped_commands;

    for (int i = 0; commands[i] != NULL; i++) {
        if (my_strchr(commands[i], '|')) {
            piped_commands = split_commands(commands[i], "|");
            execute_piped_commands(piped_commands);
            free(piped_commands);
        } else {
            check_command(env, commands[i]);
        }
    }
    free(commands);
}
