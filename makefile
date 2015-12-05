# Makefile for okrety

CC = g++
CFLAGS = -Wall -Wextra
all: okrety

okrety: okrety.cpp
	$(CC) $(CFLAGS) -o okrety okrety.cpp

clean:
	rm okrety
