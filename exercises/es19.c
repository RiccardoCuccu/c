#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50

int main(int argc, char *argv[]) {
	int i;
	char character;
	FILE *frand;
	frand = fopen("rand.dat", "w");
	if (frand == NULL) {
		printf("Error in creating rand.dat\n");
		return 1;
	}
	/* Intializes pseudo-random number generator with the current calendar time */
	srand(time(NULL));		
	fprintf(frand, "%d\n", N);
	for(i=0; i<N; i++) {
		/* rand() % (max_number + 1 - minimum_number) + minimum_number */
		fprintf(frand, "%0.4f\n", (rand() % (501 + 500) - 500)/1.e3 );
	}
	fclose(frand);
	frand = fopen ("rand.dat", "r");  
	character = fgetc(frand);
	while (character!=EOF)
		{
			printf ("%c", character);
			character = fgetc(frand);
		}
	fclose(frand);
	return 0;
}