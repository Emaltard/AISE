CFLAGS=-Wall -Werror

all: tab.o
	gcc -shared -o libtab.so tab.o

tab.o: tab.c tab.h
	gcc -c tab.c $(CFLAGS) -fPIC

clean:
	rm *.o libtab.so
