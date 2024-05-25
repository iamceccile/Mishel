##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile Minishell1
##

NAME := mysh

SRC :=main.c\
	my_putstr.c\
	my_putchar.c\
	my_strtwa.c\
	my_strlen.c\
	my_put_nbr.c\
	mini_printf.c\
	my_strcmp.c\
	my_strchr.c\
	my_strcpy.c\
	my_strcat.c\
	my_strdup.c\
	check_command.c\
	command.c\
	pipes.c\
	pipe_advenced.c

OBJ := $(SRC:.c=.o)

CFLAGS := -g3 -Wall -Wextra

all: $(NAME)

clean :
	find . -type f -name '*~' -delete
	find . -type f -name '#*#' -delete
	find . -type f -name '*.o' -delete

fclean : clean
	rm  -f $(NAME)
	rm -f a.out

re : fclean all

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ)

.PHONY : all re fclean clean
