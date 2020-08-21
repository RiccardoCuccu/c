#include <stdio.h>

int main (int argc, char *argv[]) {
	int x;
	printf("Input value: ");
	scanf("%d", &x);
	printf("The left shifted data is %d\n", x<<2);
	return 0;
}