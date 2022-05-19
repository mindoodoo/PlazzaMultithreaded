##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

CXXFLAGS = -I./Kitchen -I./Pizza -g3 -fPIC -Wall -Wextra

SRC =	Pizza/Pizza.cpp						\
		LogEngine/Log.cpp					\
		Kitchen/Kitchen.cpp					\
		Kitchen/ProcessEncapsulation.cpp 	\
		Kitchen/SplitString.cpp				\
		Kitchen/MutexEncapsulation.cpp		\
		Kitchen/Timer.cpp					\
		Kitchen/Ipc.cpp						\
		main.cpp

all: server clean

server:
	g++	-o testBin $(SRC) $(CXXFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf testBin

re: fclean all

.PHONY: re fclean clean