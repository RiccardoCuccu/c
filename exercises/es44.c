#include<stdio.h>
#include<ctype.h>

int main(int argc, char *argv[]){
	char test;  
	printf("Input a character: ");		// Hexadecimal Digits are a-f, A-F or 0-9
	scanf("%c", &test);
	if(isxdigit(test))
		printf("The entered character is a Hexadecimal Digit.\n");
	else
		printf("The entered character is not a Hexadecimal Digit.\n");
	return 0;
}