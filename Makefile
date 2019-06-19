##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC			=	gcc

CFLAGS		=	-Wall -Wextra -W -I include/ -g3

LIB			=	 -L./lib/my -lmy

SRC			=	main.c		\
				buildtin.c	\
				env.c		\
				core.c		\
				utils.c		\
				tree.c		\
				misc.c		\
				execute.c

CRITERION	=	main.c

OBJ			=	$(SRC:.c=.o)

NAME		=	mysh

all: $(NAME)

$(NAME): $(OBJ)
		make -C lib/my all
		$(CC) $(OBJ) $(LIB) -o $(NAME)

crit:
	make -C lib/my all
	$(CC) $(CRITERION) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	make -C lib/my clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)

re: fclean all

criterion: fclean crit
