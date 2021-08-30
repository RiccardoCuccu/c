#include <stdio.h>
#include <ctype.h>

void LeggiScacchiera(char s[8][8]);
void StampaScacchiera(char s[8][8]);
int ValutaPosizione(char s[8][8]);
int PedoniFuoriPosto(char s[8][8]);
int CercaReCavalli(char s[8][8]);
int Punteggio(char s[8][8]);

int main(int argc, char *argv[]) {
	char s[8][8];
	LeggiScacchiera(s);
	StampaScacchiera(s);
	switch (ValutaPosizione(s)) {
		case -1:
			printf("Posizione non valida!\n");
			break;
		case 0:
			printf("Posizione di parità!\n");
			break;
		case 1:
			printf("Posizione di vantaggio bianco!\n");
			break;
		case 2:
			printf("Posizione di vantaggio nero!\n");
			break;
	}
	return 0;
}

void LeggiScacchiera(char s[8][8]) {
	FILE* fp;
	int i, j;
	fp = fopen("./work/scacchiera.txt","r");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) s[i][j] = getc(fp);
		getc(fp);
	}
}

void StampaScacchiera(char s[8][8]) {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) putchar(s[i][j]);
		putchar('\n');
	}
}

int ValutaPosizione(char s[8][8]) {
	if(PedoniFuoriPosto(s) == -1) return -1;
	if(CercaReCavalli(s) == -1) return -1;
	return(Punteggio(s));
}

int PedoniFuoriPosto(char s[8][8]) {
	int j;
	for(j = 0; j < 8; j++){
		if(tolower(s[0][j]) == 'p' || tolower(s[7][j]) == 'p') return -1;
	}
	return 0;
}

int CercaReCavalli(char s[8][8]) {
	int r1 = 0;
	int r2 = 0;
	int c1 = 0;
	int c2 = 0;
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if(s[i][j] == 'R') r1++;
			else if(s[i][j] == 'r') r2++;
			else if(s[i][j] == 'C') c1++;
			else if(s[i][j] == 'c') c2++;
		}
	}
	if (r1 != 1 || r2 != 1 || c1 > 2 || c2 > 2) return -1;
	return 0;
}

int Punteggio(char s[8][8]) {
	int i, j;
	int white = 0;
	int black = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			switch(s[i][j]){
				case 'D': black += 9; break;
				case 'A':
				case 'C': black += 3; break;
				case 'T': black += 5; break;
				case 'P': black += 1; break;
				case 'd': white += 9; break;
				case 'a':
				case 'c': white += 3; break;
				case 't': white += 5; break;
				case 'p': white += 1; break;
				default: break;
			}
		}
	}

	if(white > black) return 1;
	if(white < black) return 2;
	return 0;
}