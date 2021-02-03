#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int studentifc(char *filename, char *year) {

	int comma, i, sy, y;
	int counter = 0;								// inizializzazione numero studenti fuori corso
	char status;
	char line[256];
	FILE *f;

	f = fopen(filename, "r");							// apertura file in lettura
	if(f == NULL) return -1;

	y = atoi(year);									// controllo sul limite di anni
	if(y < 1 || y > 5) return -1;

	while(!feof(f)) {

		fgets(line, sizeof(line), f);						// estrazione di una riga
		comma = 0;								// reset del contatore delle virgole

		for(i = 0; i < sizeof(line); i++) {					// analisi carattere per carattere
			if(comma == 2) {						// accesso dopo la seconda virgola		
				if(line[i] == ' ') continue;				// se il carattere è uno spazio vuoto va al ciclo for successivo
				else {
					sy = atoi(&line[i]);				// salvataggio dell'anno dello studente
					status = line[i+2];				// salvataggio dello status dello studente ('R' o 'F')
					break;						// esce dal ciclo for
				}
			}
			if(line[i] == ',') comma++;					// ricerca delle virgole
		}

		if(sy == y && status == 'F') counter ++;				// contollo sull'anno e sullo status dello studente

	}

	return counter;
}


int main(int argc, char *argv[]) {

	if(argc != 3) {									// controllo del numero di parametri passati alla funzione
		printf("ERRORE: numero di parametri errato!\n");
		printf("Esempio di utilizzo: ./ex03.out ./work/exambooking.txt 2\n");
		exit(-1);
	}

	int n;

	n = studentifc(argv[1], argv[2]);						// calcolo degli studenti fuori corso

	if(n == -1) printf("Il nome del file inserito e/o il valore dell'anno di corso non è valido!\n");
	else printf("Il numero di studenti fuori corso per l'anno %s è pari a %d.\n", argv[2], n);
	
	return 0;
}