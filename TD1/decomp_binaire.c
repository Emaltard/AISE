#include <stdio.h>
#include <stdlib.h>

int power(int x, int n){
	double res = x;
	if(n<1) {
		return 1;
	}
	for(int i=1; i<n; i++) {
		res = res*x;
	}
	return res;
}

void int_to_bits(int n){
	for(int i=sizeof(int)*8 -1; i>=0; i--) {
		if((n&(power(2,i)))>0) {
			printf("1");
		}else{
			printf("0");
		}
	}
	printf("\n");
}

int main(int argc, char** argv){
	int n;
	printf("Donnez n à decomposer en binaire:");
	scanf("%d", &n);
	int_to_bits(n);
	return EXIT_SUCCESS;
}
