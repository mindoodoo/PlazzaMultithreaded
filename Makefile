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
<<<<<<< HEAD
		Kitchen/Ipc.cpp						\
		Kitchen/ThreadEncapsulation.cpp 	\
=======
		ipc/Ipc.cpp							\
>>>>>>> 92e5dfc1f90fcf4a2008e8c5b707012da91092c4
		plazza.cpp

NAME	=	plazza

CC	=	g++

CPPFLAGS	=	-fPIC	-Wall	-Wextra -g3

all:
	$(CC)	$(CPPFLAGS)	-o	$(NAME)	$(SRC)

clean:
	rm -rf *.o

fclean:	clean
	rm	-f	$(NAME)

re:	fclean	all
