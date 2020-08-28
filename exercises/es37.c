#include<stdio.h>

int *larger_value(int *n1, int *n2);

int main(int argc, char *argv[]) {
	int m, n;
	int *pt1=&m, *pt2=&n, *result;
	printf("Input the first number: ");
	scanf("%d", pt1);
	printf("Input the second number: ");
	scanf("%d", pt2);
	result=larger_value(pt1, pt2);
	printf("The number %d is larger.\n", *result);
	return 0;
}

int *larger_value(int *n1, int *n2) {
	if (*n1 > *n2)
		return n1;
	else
		return n2;
}