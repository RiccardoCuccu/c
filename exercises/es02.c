#include <stdio.h>

int main (int argc, char *argv[]) {
	char c[] = {'X', 'M', 'L'};
	printf("The reverse of %c%c%c is %c%c%c\n", c[0], c[1], c[2], c[2], c[1], c[0]);
	return 0;
}