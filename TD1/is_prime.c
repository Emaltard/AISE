#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int nbr;
	printf("Donnez un nombre dont vous souhaitez tester la primalité: ");
	scanf("%d", &nbr);
	for(int i=2; i<nbr; i++) {
		if(nbr%i==0) {
			printf("%d n'est pas premier!\n", nbr);
			return EXIT_SUCCESS;
		}
	}
	printf("%d est premier!\n", nbr);
	return EXIT_SUCCESS;
}
