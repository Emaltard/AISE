CFLAGS=-Wall -Werror
LDFLAGS=-ltab

all: foo.o main.o libtab.so
	gcc -o main main.o foo.o -L../libtab $(LDFLAGS)

foo.o: foo.c foo.h
	gcc -c foo.c $(CFLAGS)

main.o: main.c foo.h
	gcc -c main.c $(CFLAGS) -I../libtab

libtab.so:
	make -C ../libtab

clean:
	rm main *.o
