CFLAGS = -g -Wall -Werror -O0
CC = gcc
LDFLAGS = -L. -lm -lcmocka
EXEC = memory_alloc

all:
	$(CC) memory_alloc.c -o $(EXEC) $(CFLAGS) $(LDFLAGS)

clean:
	rm memory_alloc
