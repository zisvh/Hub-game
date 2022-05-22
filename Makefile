##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = 	$(wildcard *.c **/*.c **/**/*.c)

OBJ =   $(SRC:.c=.o)

NAME = Tek-Party

CFLAGS = -Wno-deprecated -Wall -Wextra -Iinclude/

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
