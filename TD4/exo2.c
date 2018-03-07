#include <stdio.h>
#include <stdlib.h>

void init(int* tab, int size){
	for(int i=0; i<size; i++) {
		*tab++ = 0;
	}
}

void squares(int tab[], int size){
	for(int i=0; i<size; i++) {
		tab[i] *= tab[i];
	}
}

void display(int tab[], int size){
	for(int i=0; i<size; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");
}

int main(int argc, char** argv){
	int tab1[4] = {1,2,3,4};
	init(tab1, 4);
	display(tab1, 4);

	int* tab2 = malloc(4*sizeof(int));
	init(tab2, 4);
	display(tab2,4);

	printf("tab1 = %p\n", tab1);
	printf("&tab1 = %p\n", &tab1);
	printf("tab2 = %p\n", tab2);
	printf("&tab2 = %p\n", &tab2);

	printf("sizeof(tab1) = %zu\n", sizeof(tab1));
	printf("sizeof(&tab1) = %zu\n", sizeof(&tab1));
	printf("sizeof(*&tab1) = %zu\n", sizeof(*&tab1));
	printf("sizeof(tab2) = %zu\n", sizeof(tab2));
	printf("sizeof(&tab2) = %zu\n", sizeof(&tab2));
	printf("sizeof(*&tab2) = %zu\n", sizeof(*&tab2));

	free(tab2);

	return 0;
}
