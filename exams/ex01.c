#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DIM 8

int converter(char *n) {							// conversione in numero

	char ret;

	if (!strcmp(n, "zero")) ret = '0';
	else if (!strcmp(n, "uno")) ret = '1';
	else if (!strcmp(n, "due")) ret = '2';
	else if (!strcmp(n, "tre")) ret = '3';
	else if (!strcmp(n, "quattro")) ret = '4';
	else if (!strcmp(n, "cinque")) ret = '5';
	else if (!strcmp(n, "sei")) ret = '6';
	else if (!strcmp(n, "sette")) ret = '7';
	else if (!strcmp(n, "otto")) ret = '8';
	else if (!strcmp(n, "nove")) ret = '9';
	else {
		printf("ERRORE: non è possibile decodificare il valore %s\n", n);
		exit(1);
	}

	return ret;
}


int main(int argc, char *argv[]){

	int sum = 0;
	char ch;
	char filename[256];
	char S[32];
	char n[DIM];
	FILE *f;

	printf("Inserire il nome del file da analizzare: ");
	scanf("%s", filename);
	//strcpy(filename, "./work/stringnum.txt");

	f = fopen(filename, "r");						// apertura file in lettura
	if(f == NULL) {
		perror("ERROR during FOPEN execution");
		exit(errno);
	}

	while(!feof(f)) {							// finchè il file non è finito
		fscanf(f, "%s", n);						// estrazione di una nuova parola
		if (!strcmp(n, "stop")) {					// se n contiene "stop"
			sum = sum + atoi(S);					// conversione in intero e somma con i valori precedenti
			memset(S, 0, sizeof(S));				// reset della variabil S
			continue;
		} else {
			ch = converter(n);					// decodifica il nuovo numero
			strncat(S, &ch, 1);					// concatena il nuovo numero
		}	
	}

	printf("Somma = %d\n", sum);						// stampa della somma
	fclose(f);

	return 0;
}