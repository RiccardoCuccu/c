#include<stdio.h>

int main(int argc, char *argv[]) {
	int m, n;
	int *pt1=&m, *pt2=&n;
	printf("Input the first number: ");
	scanf("%d", pt1);
	printf("Input the second number: ");
	scanf("%d", pt2);
	printf("The multiplication of %d and %d is %d\n", *pt1, *pt2, (*pt1)*(*pt2));
	return 0;
}