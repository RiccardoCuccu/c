#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_MATCHES 5

struct Partita {
	char moneta;
	int ris_dado1;
	int ris_dado2;
};

int sfide(struct Partita *matches_array, int matches) {							// calcolo del vincitore

	int i;
	int player1 = 0;
	int player2 = 0;

	for(i = 0; i < matches; i++) {
		if(matches_array[i].moneta == 't') {							// se testa (t) vince il dado più alto
			if (matches_array[i].ris_dado1 > matches_array[i].ris_dado2) player1++;
			else if (matches_array[i].ris_dado1 < matches_array[i].ris_dado2) player2++;
		} else {										// se croce (c) vince il dado più basso
			if (matches_array[i].ris_dado1 > matches_array[i].ris_dado2) player2++;
			else if (matches_array[i].ris_dado1 < matches_array[i].ris_dado2) player1++;
		}
	}

	if(player1 > player2) return 1;
	else if(player1 < player2) return -1;
	else return 0;

}

int main(int argc, char *argv[]) {

	int i, matches, winner;
	
	srand(getpid());						// utilizzo del PID del processo come seed per ottenere un vero numero casuale
	matches = rand() % MAX_MATCHES + 1;				// numero casuale di partite

	struct Partita matches_array[matches];				// definizione dell'array di partite

	for(i = 0; i < matches; i++) {					// inizializzazione dell'array di partite con valori casuali
		if(rand() % 2 == 0) matches_array[i].moneta = 't';
		else matches_array[i].moneta = 'c';
		matches_array[i].ris_dado1 = 1 + rand() % 6;
		matches_array[i].ris_dado2 = 1 + rand() % 6;

		printf("Partita %d: %d-%d-%c\n", i+1, matches_array[i].ris_dado1, matches_array[i].ris_dado2, matches_array[i].moneta);
	}

	winner = sfide(matches_array, matches);				// calcolo del vincitore della partita tramite la funzione sfide()

	if(winner == 1) printf("Ha vinto il Giocatore 1!\n");
	else if(winner == -1) printf("Ha vinto il Giocatore 2!\n");
	else printf("Parità!\n");

	return 0;
}
