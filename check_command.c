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
#include "imports.h"

void check_command3(char *buffer, int count)
{
    char **res = my_strtwa(buffer);
    int result = my_strlen(res[0]);

    res[0][result] = '\0';
    if (my_strcmp(res[0], "pwd") == 0) {
        check_pwd();
        count = 1;
        } else if (my_strcmp(res[0], "cd") == 0) {
        check_cd(res[1], buffer);
        count = 1;
    }
    if (!count) {
        mini_printf("%s: Commande introuvable.\n", buffer);
        return 84;
    }
}

void check_command2(char **env, char *buffer, int count)
{
    int i = 0;
    char **res = my_strtwa(buffer);
    int result = my_strlen(res[0]);

    res[0][result] = '\0';
    if (my_strcmp(res[0], "env") == 0) {
        while (env[i] != NULL) {
            mini_printf("%s\n", env[i]);
            i++;
        }
        count = 1;
    }
    check_command3(buffer, count);
}


/*void check_command2(char **env, char *buffer, int count)
{
    int i = 0;
    char **res = my_strtwa(buffer);
    int result = my_strlen(res[0]);

    res[0][result] = '\0';
    if (my_strcmp(res[0], "env") == 0) {
        while (env[i] != NULL) {
            mini_printf("%s\n", env[i]);
            i++;
        }
        count = 1;
    }
    check_command3(env, buffer, count);
}*/

void check_command(char **env, char *buffer)
{
    char **res = my_strtwa(buffer);
    int result = my_strlen(res[0]);
    int pid = fork();
    int status = 0;
    int count = 0;

    res[0][result] = '\0';
    if (pid == 0) {
        // Vérification de la redirection '>'
        char *redir = strstr(buffer, ">");
        if (redir != NULL) {
            *redir = '\0';
            redir++;
            while (*redir == ' ') redir++;
            char *args = strtok(buffer, " ");
            char *cmd_args[128];
            int i = 0;
            while (args != NULL) {
                cmd_args[i++] = args;
                args = strtok(NULL, " ");
            }
            cmd_args[i] = NULL;
            execute_command_with_redirection(cmd_args, env, redir);
            exit(0);
        }

        if (my_strcmp(res[0], "ls") == 0) {
            execve("/bin/ls", res, env);
            count = 1;
        } else {
            check_command2(env, buffer, count);
        }
    }
    if (pid > 0) {
        waitpid(pid, &status, 0);
    }
}

/*void check_command(char **env, char *buffer)
{
    char **res = my_strtwa(buffer);
    int result = my_strlen(res[0]);
    int pid = fork();
    int status = 0;
    int count = 0;

    res[0][result] = '\0';
    if (pid == 0) {
        if (my_strcmp(res[0], "ls") == 0) {
            execve("/bin/ls", res, env);
            count = 1;
        } else {
            check_command2(env, buffer, count);
        }
    }
    if (pid > 0) {
        waitpid(pid, &status, 0);
    }
}*/
