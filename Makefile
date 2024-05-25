##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile Minishell1
##

NAME := mysh

SRC :=main.c\
	lib/my_putstr.c\
	lib/my_putchar.c\
	lib/my_strtwa.c\
	lib/my_strlen.c\
	lib/my_put_nbr.c\
	lib/mini_printf.c\
	lib/my_strcmp.c\
	lib/my_strchr.c\
	lib/my_strcpy.c\
	lib/my_strcat.c\
	lib/my_strdup.c\
	src/check_command.c\
	src/command.c\
	src/pipes.c\
	src/pipe_advenced.c

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
