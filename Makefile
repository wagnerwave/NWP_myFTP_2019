##
## EPITECH PROJECT, 2020
## Alexandre Wagner
## File description:
## Makefile for my_ftp project
##

D_SRC	=	./src/
D_INC	=	./include/

NAME	=	myftp

SRC		=	$(D_SRC)error.c \
			$(D_SRC)help.c \
			$(D_SRC)init.c \
			$(D_SRC)serveur.c \
			$(D_SRC)main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -I$(D_INC)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re	:		fclean all

.PHONY	:	all clean fclean re