#include <stdio.h>

int main (int argc, char *argv[]) {
	float i, S = 0;
	for (i=1; i<=50; i++){
		S = S + 1/i;
	}
	printf("Value of S: %.2f\n", S);
	return 0;
}