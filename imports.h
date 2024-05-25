/*
** EPITECH PROJECT, 2024
** Mishel
** File description:
** Imports file of Mishel
*/

#ifndef IMPORTS
    #define IMPORTS
char **my_str_to_array(char *str);
char my_putstr(char const *str);
void my_putchar(char c);
int execute(char **argv, char **env);
void prompt(char **env);
char **my_str_to_word_array(char *str);
char *get_next_mark(char *str);
char *copy_string(const char *str);
void check_command(char **env, char *buffer);
int my_strlen(char const *str);
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(char const *src);
char **my_strtwa(char *string);
int mini_printf(const char *format, ...);
int my_put_nbr(int nb);
int check_setenv2(char **env, int env_count, char **new_env, char *buffer);
void execute_command(char **env, char *buffer);
char *my_strcat(char *dest, char const *src);
void execute_command_with_redirection(char **args, char **env, char *file);

#endif /* IMPORTS */
