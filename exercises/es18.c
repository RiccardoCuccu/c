#include <stdio.h>
#include <math.h>

int main (int argc, char *argv[]) {
	float x, value;
	printf("Input value of x: ");
	scanf("%f", &x);
	if (x!=0) {
		value = sin(1/x);
		printf("Value of sin(1/x) is %0.4f\n", value);
	}
	else
	{
		printf("Value of x should not be zero.\n");
	}
	return 0;
}