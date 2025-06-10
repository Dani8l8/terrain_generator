CC=gcc
CFLAGS=-Wall -lraylib -lm

default: main.c
	$(CC) main.c -o ./terrain $(CFLAGS) && ./terrain
