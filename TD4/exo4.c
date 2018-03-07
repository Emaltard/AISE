#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_length(const char* string){
	int i;
	for(i=0; string[i]!='\0'; i++) {

	}
	return i;
}

void string_cpy(char* dest, const char* src, size_t n){
	for(int i=0; i<n && src[i]!='\0'; i++) {
		dest[i] = src[i];
	}
}

void string_concatenate(char* dest, const char* src, size_t n) {
	int len = string_length(dest);
	string_cpy(&dest[len], src, n);
}


int main(int argc, char** argv){
	char src[50], dest[50];

	strcpy(src, "à tous !");
	strcpy(dest,  "Bonjour");

	string_concatenate(dest, src, 15);

	printf("Final destination string : |%s|\n", dest);

	return(0);
}
