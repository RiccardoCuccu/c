#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void rcomments(char input_file[]) {

	char ch, last_ch = '\n';
	char output_file[40];
	FILE *fin, *fout;

	strcpy(output_file, input_file);				// copia il nome del file di input in output_file
	output_file[strlen(output_file)-2] = 'o';			// cambia in 'o' la 'i' di .tic

	fin = fopen(input_file, "r");					// apertura file in lettura
	if(fin == NULL) {
		perror("ERRORE: apertura del file di input non riuscita");
		exit(errno);
	}

	fout = fopen(output_file, "w");					// apertura file in scrittura
	if(fout == NULL) {
		perror("ERRORE: apertura del file di output non riuscita");
		exit(errno);
	}

	while((ch = getc(fin)) != EOF) {				// cicla su tutti i caratteri del file
		if (ch == '#') {					// se il carattere è '#' cicla a vuoto sino a '\n' o EOF
			while((ch = getc(fin)) != '\n' && ch != EOF);
			if(last_ch != '\n') fprintf(fout, "\n");	// se il carattere precedente al '#' non era uno '\n' tornare a capo
		} else {						// altrimenti copia il carattere sul file di output
			putc(ch, fout);
		}
		last_ch = ch;
	}

	fclose(fin);
	fclose(fout);
}

int main(int argc, char *argv[]){

	char *ext_pointer;
	char ext[3];

	if(argc != 2) {							// controllo del numero di parametri passati alla funzione
		printf("ERRORE: numero di parametri errato!\n");
		printf("Esempio di utilizzo: ./ex09.out ./work/assembly.tic\n");
		return -1;
	}

	ext_pointer = strrchr(argv[1], '.');				// estrazione puntatore all'ultimo punto nel nome del file passato alla funzione
	sprintf(ext, "%s", ext_pointer + 1);				// salvataggio estensione file

	if (strcmp(ext,"tic")) {					// controllo dell'estensione del file passato alla funzione
		printf("Extension absent or incorrect, pass a file with .tic format.\n");
		return -1;
	}

	rcomments(argv[1]);

	return 0;
}