#include <stdlib.h>
#include <stdio.h>
#include "foo.h"
#include "tab.c"

int main(int argc, char**argv) {
	TYPE n = foo();
	printf("%d\n", n);
	int size = 10;
	int tab[size];
	saisir_tab(tab, size);
	afficher_tab(tab, size);
	return EXIT_SUCCESS;
}
