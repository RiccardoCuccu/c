#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	char str[100];
	unsigned long ul;
	printf("Input an unsigned number: ");
	fgets(str, 100, stdin);
	ul = strtoul(str, NULL, 0);
	printf("Output: %lu\n", ul);
	return 0;
}