#include <stdio.h>
#include <stdlib.h>

int var_globale = 1;
static int var_globale_static = 2;
extern int var_gloable_extern;

int main(int argc, char**argv) {

	int a = 0;
	static int b = 0;

	printf("a+b = %d\n", a+b);

	printf("var_globale = %d\n", var_globale);
	printf("var_globale_static = %d\n", var_globale_static);
	printf("var_gloable_extern = %d\n", var_gloable_extern);

	return EXIT_SUCCESS;
}
