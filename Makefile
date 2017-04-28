CC=gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic

all:
	$(CC) $(CFLAGS) -o demo demo.c getExp.c getZip.c getPrice.c
