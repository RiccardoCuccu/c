#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DIMN 50
#define DIMM 50
#define DIMW 50

struct Matrix {
	int N;
	int M;
	char mtx[DIMN][DIMM];
};

struct Matrix savecrossword(char *filename) {

	int n, m;
	FILE *f;
	struct Matrix matrix;

	f = fopen(filename, "r");						// apertura file in lettura
	if(f == NULL) {
		perror("ERRORE: apertura del file di input non riuscita");
		exit(errno);
	}

	fscanf(f, "%d %d\n", &matrix.N, &matrix.M);				// N righe e M colonne del file di input

	for(n = 0; n < matrix.N; n++) {						// riempimento matrice
		for(m = 0; m < matrix.M; m++) {
			matrix.mtx[n][m] = fgetc(f);
		}
		fgetc(f);							// scarta '\n'
	}
	
	fclose(f);

	return matrix;
}

int writewords(struct Matrix matrix) {

	int n, m;
	char W[DIMW]= "";
	FILE *f;

	f = fopen("./work/parole.txt", "w");					// apertura file in scrittura
	if(f == NULL) {
		perror("ERRORE: apertura del file di output non riuscita");
		exit(errno);
	}

	for(n = 0; n < matrix.N; n++) {						// ciclo esterno sulle righe
		for(m = 0; m < matrix.M; m++) {					// ciclo interno sulle colonne
			if(matrix.mtx[n][m] != ' ') {				// se il carattere è diverso da uno spazio vuoto concatenalo alla stringa W
				strncat(W, &matrix.mtx[n][m], 1);
			} else if(strlen(W) > 1) {				// altrimenti se il numero di caratteri nella stringa è superiore ad uno stampali
				fprintf(f, "%s\n", W);
				memset(W, 0, sizeof(W));
			} else {						// se il numero di caratteri nella lista è inferiore a due scartali
				memset(W, 0, sizeof(W));
			}
		}
		if(strlen(W) > 1) fprintf(f, "%s\n", W);			// se alla fine della riga il numero di caratteri nella stringa è superiore ad uno stampali
		memset(W, 0, sizeof(W));
	}

	fprintf(f, "\n");

	for(m = 0; m < matrix.M; m++) {						// ciclo esterno sulle colonne
		for(n = 0; n < matrix.N; n++) {					// ciclo interno sulle righe
			if(matrix.mtx[n][m] != ' ') {				// se il carattere è diverso da uno spazio vuoto concatenalo alla stringa W
				strncat(W, &matrix.mtx[n][m], 1);
			} else if(strlen(W) > 1) {				// altrimenti se il numero di caratteri nella stringa è superiore ad uno stampali
				fprintf(f, "%s\n", W);
				memset(W, 0, sizeof(W));
			} else {						// se il numero di caratteri nella lista è inferiore a due scartali
				memset(W, 0, sizeof(W));
			}
		}
		if(strlen(W) > 1) fprintf(f, "%s\n", W);			// se alla fine della riga il numero di caratteri nella stringa è superiore ad uno stampali
		memset(W, 0, sizeof(W));
	}

	fclose(f);

	return 0;
}


int main(int argc, char *argv[]) {

	struct Matrix matrix;

	if(argc != 2) {							// controllo del numero di parametri passati alla funzione
		printf("ERRORE: numero di parametri errato!\n");
		printf("Esempio di utilizzo: ./ex07.out ./work/crossWord.txt\n");
		return -1;
	}

	matrix = savecrossword(argv[1]);
	writewords(matrix);

	return 0;
}
