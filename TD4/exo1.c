#include <stdio.h>

void squares(int* a, int* b){
	*a = (*a)*(*a);
	*b = (*b)*(*b);
}

int main(int argc, int** argv){
	int a = 4;
	int b = 2;
	int* pa = &a;
	int* pb = &b;

	squares(&a,&b);

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);

	printf("pa = %d\n", *pa);
	printf("pb = %d\n", *pb);
	printf("&pa = %p\n", &pa);
	printf("&pb = %p\n", &pb);
}
