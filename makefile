# Makefile for okrety

CC = g++
CFLAGS = -g -Wall -Wextra
all: okrety

okrety: okrety.cpp
	$(CC) $(FLAGS) -o okrety okrety.cpp

clean:
	rm okrety
