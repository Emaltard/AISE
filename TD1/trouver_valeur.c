#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
	int nbr;
	int tentatives_restantes = 10;

	srand(getpid());
	int valeur_a_trouver = rand() % 100;

	do {
		printf("Tentatives restantes: %d\n", tentatives_restantes);
		printf("Donnez un nombre entre 0 et 99: \n");
		scanf("%d", &nbr);
		if(valeur_a_trouver == nbr) {
			tentatives_restantes = 0;
			printf("Vous avez trouvé la bonne valeur!\n");
		}else if(valeur_a_trouver > nbr) {
			printf("Le nombre à trouver est plus grand!\n");
		}else{
			printf("Le nombre à trouver est plus petit!\n");
		}
		tentatives_restantes--;
	} while(tentatives_restantes > 0);
	return EXIT_SUCCESS;
}
