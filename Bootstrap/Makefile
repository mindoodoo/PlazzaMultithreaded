##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

CXXFLAGS = -g3 -pthread -I./include

SRC = main.cpp \
	src/Counter.cpp

all: bootstrap clean

bootstrap:
	g++	-o bootstrap $(SRC) $(CXXFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf bootstrap

re: fclean all

.PHONY: re fclean clean
