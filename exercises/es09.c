#include <stdio.h>

int main(int argc, char *argv[]) {
	int i;
	printf("Even numbers between 1 to 50 (inclusive): ");
	for (i=2; i<=50; i+=2) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}