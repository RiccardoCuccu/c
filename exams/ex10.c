#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_PARTITE 20

struct Match {
	char Squadra1[20];
	char Squadra2[20];
	int GoalSquadra1;
	int GoalSquadra2;
};

void AddWinner(char filename[]) {

	int i = 0;
	int n = 0;

	char r;

	FILE *f;

	struct Match m[MAX_PARTITE];

	f = fopen(filename, "r");						// apertura file in lettura
	if(f == NULL) {
		perror("ERRORE: apertura del file di input non riuscita");
		exit(errno);
	}

	while(fscanf(f, "%s%*s%s%d%*c%d", m[i].Squadra1, m[i].Squadra2, &m[i].GoalSquadra1, &m[i].GoalSquadra2) != EOF) i++;
	n = i;

	fclose(f);

	f = fopen(filename, "w");						// apertura file in scrittura
	if(f == NULL) {
		perror("ERRORE: apertura del file di input non riuscita");
		exit(errno);
	}

	for(i = 0; i < n; i++) {
		if(m[i].GoalSquadra1 > m[i].GoalSquadra2) r = '1';
		else if(m[i].GoalSquadra1 < m[i].GoalSquadra2) r = '2';
		else r = 'X';

		fprintf(f,"%s - %s %d-%d %c\n", m[i].Squadra1, m[i].Squadra2, m[i].GoalSquadra1, m[i].GoalSquadra2, r);
	}

	fclose(f);
}

int main(int argc, char *argv[]) {

	if(argc != 2) {
		printf("ERRORE: numero di parametri errato!\n");
		printf("Esempio di utilizzo: ./ex10.out ./work/matches.txt\n");
		return(-1);
	}

	AddWinner(argv[1]);

	return 0;
}