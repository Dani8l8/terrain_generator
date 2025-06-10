CC=gcc
CFLAGS=-Wall -lraylib -lm

default: main.c
	$(CC) main.c terrain.c -o ./terrain $(CFLAGS) && ./terrain
