#include<stdio.h>

int main(int argc, char *argv[]) {
	char str[50];
	printf("Input the string: ");
	fgets(str, sizeof(str), stdin);
	printf("The string you entered is: %s", str);
	return 0;
}