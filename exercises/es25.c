#include<stdio.h>

int main(int argc, char *argv[]) {
	int size, i, j;
	printf("Input the size of the square: ");
	scanf("%d", &size);
	if(size < 1 || size > 100) {
		printf("Size should be in the range 1 to 100.\n");
		return 1;
	}
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			if(i==0 || i==size-1 || j==0 || j==size-1) printf("#");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}