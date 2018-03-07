#include <stdio.h>
#include <stdlib.h>

int facto(int n){
	if(n<2) {
		return 1;
	}
	else{
		return facto(n-1)* n;
	}
}

int main(int argc, char** argv){
	int n;
	printf("Donnez un nombre dont vous voulez calculer la factoriel: \n");
	scanf("%d", &n);
	printf("%d\n", facto(n));
	return EXIT_SUCCESS;
}
