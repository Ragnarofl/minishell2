##
## EPITECH PROJECT 2018
## Makefile
## File description:
## Makefile
##

CC		=	gcc

CFLAGS	=	-Wall -Wextra -W -Werror -g3

SRC		=	my_putchar.c				\
			my_put_nbr.c				\
			my_swap.c					\
			my_show_word_array.c		\
			my_getnbr.c					\
			my_itoa.c					\
			my_strlen.c					\
			my_nbrlen.c					\
			my_putstr.c					\
			my_showstr.c				\
			my_strcmp.c					\
			my_strncmp.c				\
			my_strcat.c					\
			my_strncat.c				\
			my_revstr.c					\
			my_strstr.c					\
			my_malloc.c					\
			read_file.c					\
			my_str_to_word_array_line.c	\
			my_str_to_word_array.c		\
			get_next_line.c				\
			../printf/my_printf.c		\
			../printf/my_dprintf.c		\
			../printf/formats.c			\
			../printf/formaters.c		\
			../printf/formats_base.c	\
			../printf/my_putnbr_base.c	\
			../printf/expr.c			\
			../printf/flags.c			\
			../printf/padding.c			\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:	$(OBJ)
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
