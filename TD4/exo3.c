#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int sum = 0;

	for(int i = 0; i<argc; i++) {
		printf("argv[%d] is at %p: %s\n", i, argv[i], argv[i]);
		sum += atoi(argv[i]);
	}

	printf("sum = %d\n", sum);

	return 0;
}
