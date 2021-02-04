#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {

	int n, m;
	int N, M;
	int R, G, B, BN;
	FILE *fin, *fout;

	if(argc != 3) {							// controllo del numero di parametri passati alla funzione
		printf("ERRORE: numero di parametri errato!\n");
		printf("Esempio di utilizzo: ./ex06.out ./work/bitmapin.txt ./work/bitmapout.txt\n");
		return -1;
	}

	fin = fopen(argv[1], "r");					// apertura file in lettura
	if(fin == NULL) {
		perror("ERRORE: apertura del file di input non riuscita");
		exit(errno);
	}

	fout = fopen(argv[2], "w");					// apertura file in scrittura
	if(fout == NULL) {
		perror("ERRORE: apertura del file di output non riuscita");
		exit(errno);
	}

	fscanf(fin, "%d %d", &N, &M);					// N righe e M colonne del file di input
	fprintf(fout, "%d %d\n", N+2, M+2);

	for(m = 0; m < M+2; m++) {
		fprintf(fout, "255 255 255\n");				// scrittura prima riga matrice (pixel bianchi)
	}

	for(n = 0; n < N; n++) {		
		fprintf(fout, "255 255 255\n");				// scrittura prima colonna matrice (pixel bianchi)
		for(m = 0; m < M; m++) {
			fscanf(fin, "%d %d %d", &R, &G, &B);		// estrazione del valore dei pixel
			BN = (R + G + B) / 3;				// conversione in b/n
			fprintf(fout, "%d %d %d\n", BN, BN, BN);	// scrittura pixel intermedi
		}
		fprintf(fout, "255 255 255\n");				// scrittura ultima colonna matrice (pixel bianchi)
	}

	for(m = 0; m < M+2; m++) {
		fprintf(fout, "255 255 255\n");				// scrittura ultima riga matrice (pixel bianchi)
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
