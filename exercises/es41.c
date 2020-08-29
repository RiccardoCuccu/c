#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {
	int i, j;
	char str[100];
	printf("Input the string: ");
	fgets(str, sizeof(str), stdin);
	i=strlen(str);
	printf("The reverse string is: ");
	for (j=1; j<i; j++)				// j=1 to remove the NULL
		printf("%c   ", str[i-j-1]);		// -1 to remove the new line
	printf("\n");
	return 0;
}