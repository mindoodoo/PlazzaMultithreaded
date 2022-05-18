##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

CXXFLAGS = -I. -g3

SRC = main.cpp

all: server clean

server:
	g++	-o testBin $(SRC) $(CXXFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf testBin

re: fclean all

.PHONY: re fclean clean