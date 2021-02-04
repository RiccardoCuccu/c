#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int meters;
	int vert = 0;
	int oriz = 0;
	char coordinate;
	FILE *f;

	if(argc != 2) {								// controllo del numero di parametri passati alla funzione
		printf("ERRORE: numero di parametri errato!\n");
		printf("Esempio di utilizzo: ./ex08.1.out ./work/directions1.txt\n");
		return -1;
	}

	f = fopen(argv[1], "r");						// apertura file in lettura
	if(f == NULL) {
		perror("ERRORE: apertura del file di input non riuscita");
		exit(errno);
	}

	while(!feof(f)) {
		fscanf(f, "%c %d\n", &coordinate, &meters);
		if(coordinate == 'N') vert += meters;				// incrementa asse verticale
		else if(coordinate == 'S') vert -= meters;			// decrementa asse verticale
		else if(coordinate == 'E') oriz += meters;			// incrementa asse orizzontale
		else if(coordinate == 'O') oriz -= meters;			// decrementa asse orizzontale
	}

	fclose(f);

	if(vert != 0) {
		if(vert > 0) {
			coordinate = 'N';
		} else {
			coordinate = 'S';
			vert = abs(vert);
		}
		printf("%d METRI VERSO %c\n", vert, coordinate);
	}

	if(oriz != 0) {
		if(oriz > 0) {
			coordinate = 'E';
		} else {
			coordinate = 'O';
			oriz = abs(oriz);
		}
		printf("%d METRI VERSO %c\n", oriz, coordinate);
	}

	return 0;
}