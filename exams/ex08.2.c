#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DIM 100

int main(int argc, char *argv[]) {

	int i = 0;
	int M[DIM];								// metri
	char C[DIM];								// coordinate
	FILE *f;

	if(argc != 3) {								// controllo del numero di parametri passati alla funzione
		printf("ERRORE: numero di parametri errato!\n");
		printf("Esempio di utilizzo: ./ex08.2.out ./work/directions1.txt ./work/revdirections1.txt\n");
		return -1;
	}

	f = fopen(argv[1], "r");						// apertura file in lettura
	if(f == NULL) {
		perror("ERRORE: apertura del file di input non riuscita");
		exit(errno);
	}

	while(!feof(f)) {							// inversione delle coordinate
		fscanf(f, "%c %d\n", &C[i], &M[i]);
		if(C[i] == 'N') C[i] = 'S';
		else if(C[i] == 'S') C[i] = 'N';
		else if(C[i] == 'E') C[i] = 'O';
		else if(C[i] == 'O') C[i] = 'E';
		i++;
	}

	fclose(f);

	f = fopen(argv[2], "w");						// apertura file in scrittura
	if(f == NULL) {
		perror("ERRORE: apertura del file di output non riuscita");
		exit(errno);
	}

	for(i = strlen(C)-1; i >= 0; i--) {					// scrittura in ordine inverso
		fprintf(f, "%c %d\n", C[i], M[i]);
	}

	fclose(f);

	return 0;
}