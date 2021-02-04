#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

float percentage(char *filename) {

	int i, e1, e2, flag, total;
	int eq = 0;							// equal
	int ne = 0;							// not equal
	float p;
	char num[32] = "";
	char line[256];
	FILE *f;

	f = fopen(filename, "r");					// apertura file in lettura
	if(f == NULL) {
		perror("ERROR during FOPEN execution");
		exit(errno);
	}

	while(!feof(f)) {						// finchè il file non è finito
		fscanf(f, "%s", line);					// estrazione di una nuova uguaglianza
		flag = 0;
		e1 = 0;
		e2 = 0;
		for(i = 0; i < sizeof(line); i++) {			// analisi degli elementi della singola uguaglianza
			if(line[i] == ';') {				// se il carattere i-esimo è ';' l'uguaglianza è terminata ed è necessario sommare con e2 ed uscire dal ciclo for
				e2 += atoi(num);
				memset(num, 0, sizeof(num));
				break;
			} else if(line[i] == '+' && flag == 0) {	// se il carattere i-esimo è '+' e si è nella prima metà dell'uguaglianza è necessario sommare con e1
				e1 += atoi(num);
				memset(num, 0, sizeof(num));
			} else if(line[i] == '+' && flag == 1) {	// se il carattere i-esimo è '+' e si è nella seconda metà dell'uguaglianza è necessario sommare con e2
				e2 += atoi(num);
				memset(num, 0, sizeof(num));
			} else if(line[i] == '=') {			// se il carattere i-esimo è '=' la prima metà dell'uguaglianza è terminata ed è necessario sommare con e1
				e1 += atoi(num);
				memset(num, 0, sizeof(num));
				flag = 1;
			} else {					// in tutti gli altri casi il nuovo numero sotto forma di carattere va concatenato in un apposito vettore
				strncat(num, &line[i], 1);
			}
		}

		if(e1 == e2) eq++;					// comparazione
		else ne++;
	}

	total = eq + ne;						// numero totale di uguaglianze
	p = (float) eq / total;						// percentuale di uguaglianze corrette

	return p;

}

int main(int argc, char *argv[]) {

	float perc;
	char filename[] = "./work/sums.txt";

	perc = percentage(filename) * 100;

	printf("La percentuale di uguaglianze corrette è del %.f%%!\n", perc);

	return 0;
}