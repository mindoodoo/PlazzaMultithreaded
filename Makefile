##
## EPITECH PROJECT, 2022
## arcade
## File description:
## Makefile
##

SRC	=	Reception/reception.cpp				\
		Pizza/Pizza.cpp

NAME	=	plazza

CC	=	g++

CPPFLAGS	=	-fPIC	-Wall	-Werror	-Wextra

all:
	$(CC)	$(CPPFLAGS)	-o	$(NAME)	$(SRC)

clean:
	rm -rf *.o

fclean:	clean
	rm	-f	$(NAME)

re:	fclean	all