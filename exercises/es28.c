#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	char str[100];
	int x;
	if(system(NULL))
	{
		printf("Command processor available!\n");
	}
	else
	{
		printf("Command processor not available!\n");
		exit(1);
	}
	printf("Write the command to execute: ");
	scanf("%[^\n]", str);				// read input until the user press the enter key
	x = system(str);
	printf ("Returned value is: %d.\n",x);
	return 0;
}