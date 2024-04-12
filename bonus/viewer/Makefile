##
## EPITECH PROJECT, 2023
## a-maze-d
## File description:
## Makefile
##

CC=gcc

CFLAGS=-Wall -Werror -Wextra

C_FILES = $(wildcard src/*.c)	\
			$(wildcard ../../src/*.c)

O_FILES = $(C_FILES:.c=.o)

NAME=viewer

$(NAME): ../../lib/libmy.a $(O_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) lib/libmy.a

all: $(NAME)

clean:
	make -C ../../lib/my clean
	rm -f $(O_FILES) test_$(NAME)

fclean: clean
	make -C ../../lib/my fclean
	rm -f $(NAME)

lib/libmy.a:
	make -C lib/my

re: fclean all

.PHONY: all clean fclean re
