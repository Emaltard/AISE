#include <stdio.h>
#include <stdlib.h>

double power(double x, int n){
	double res = x;
	if(n<1) {
		return 1;
	}
	for(int i=1; i<n; i++) {
		res = res*x;
	}
	return res;
}

int main(int argc, char** argv){
	int n;
	double x;
	printf("Donnez x:");
	scanf("%lf", &x);
	printf("Donnez n:");
	scanf("%d", &n);
	printf("%lf\n", power(x,n));
	return EXIT_SUCCESS;
}
