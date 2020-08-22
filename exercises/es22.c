#include <stdio.h>

int main(int argc, char *argv[]) {
	int input, result;
	int abs(int value);
	printf("Input a value: ");
	scanf("%d", &input);
	result = abs(input);
	printf("Absolute value is %d\n", result);
	return 0;
}

int abs(int value) {
	if (value<0) value=value*-1;
	return value;
}