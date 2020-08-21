#include <stdio.h>
#define LENGTH 5
#define MAX 10

int main (int argc, char *argv[]) {
	int A[5], i;
	printf("Input the %d members of the array:\n", LENGTH);
	for (i=0; i<LENGTH; i++){
		scanf("%d", &A[i]);
	}
	for (i=0; i<LENGTH; i++){
		if (A[i] < MAX) {
			printf("A[%d] = %d\n", i, A[i]);
		}
	}
	return 0;
}