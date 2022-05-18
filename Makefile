##
## EPITECH PROJECT, 2022
## arcade
## File description:
## Makefile
##

SRC	=	Reception/Reception.cpp				\
		Pizza/Pizza.cpp						\
		LogEngine/Log.cpp					\
		Kitchen/Kitchen.cpp					\
		Kitchen/ProcessEncapsulation.cpp 	\
		Kitchen/SplitString.cpp				\
		Kitchen/Timer.cpp					\
		Kitchen/Ipc.cpp						\
		Kitchen/ThreadEncapsulation.cpp		\
		plazza.cpp

NAME	=	plazza

CC	=	g++

CPPFLAGS	=	-fPIC	-Wall	-Wextra	-Werror -g3

all:
	$(CC)	$(CPPFLAGS)	-o	$(NAME)	$(SRC)

clean:
	rm -rf *.o

fclean:	clean
	rm	-f	$(NAME)

re:	fclean	all