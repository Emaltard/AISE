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

double facto(double n){
	if(n<2) {
		return 1;
	}
	else{
		return facto(n-1)* n;
	}
}

double expon(double x, int n){
	double res = 0;
	for(int i=0; i<=n; i++) {
		res += power(x,i)/facto(i);
	}
	return res;
}

int main(int argc, char** argv){
	double x;
	printf("Donnez x:");
	scanf("%lf", &x);
	printf("expo(%lf, 15) = %lf\n", x, expon(x,20));
	return EXIT_SUCCESS;
}
