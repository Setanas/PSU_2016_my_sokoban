##
## Makefile for Makefile in /home/TAN_S/PSU_2016_my_sokoban/test/test3
## 
## Made by Sébastien TAN
## Login   <TAN_S@epitech.net>
## 
## Started on  Fri Dec  9 00:12:17 2016 Sébastien TAN
## Last update Tue Dec 20 16:09:26 2016 Sébastien TAN
##

CFLAGS	= -Wall -Wextra

CFLAGS	+= -I include

CC	= gcc

RM	= rm -f

NAME	= my_sokoban

SRC	= source/main.c \
	  source/fonc_up.c \
	  source/fonc_down.c \
	  source/fonc_left.c \
	  source/fonc_right.c \
	  source/fonc_reset.c \
	  source/my_putchar.c \
	  source/annexe1.c \
	  source/error.c \
	  source/my_putstr.c \
	  source/flag_h.c \
	  source/free_fonction.c \
	  source/game.c

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lncurses

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
