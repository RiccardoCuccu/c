#include<stdio.h>

int main(int argc, char *argv[]) {
	int i = 0;
	char str[100];
	printf("Input the string: ");
	fgets(str, sizeof(str), stdin);
	while (str[i]!='\0')
		i++;
	printf("The length of the string is: %d\n", i-1);
	return 0;
}