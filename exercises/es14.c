#include <stdio.h>

int main(int argc, char *argv[]) {
	int x, y;
	printf("Input value for x & y: ");
	scanf("%d %d", &x, &y);
	printf("Before swapping the value of x & y: %d %d\n", x, y);
	x=x^y;		// XOR
	y=x^y;		// XOR
	x=x^y;		// XOR
	printf("After swapping the value of x & y: %d %d\n", x, y);
	return 0;
}