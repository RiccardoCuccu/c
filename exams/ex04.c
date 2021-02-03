#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_VECTORS 5

struct Complesso {
	float re;			// parte reale
	float im;			// parte immaginaria
};

struct Segmento {
	struct Complesso p1;		// punto 1
	struct Complesso p2;		// punto 2
};

int segmenti(struct Segmento *L, int vectors) {

	int i;
	int q = 1;
	int max = 0;
	int D[4] = {0};

	for(i = 0; i < vectors; i++) {
		if (L[i].p1.re > 0 && L[i].p2.re > 0 && L[i].p1.im > 0 && L[i].p2.im > 0) D[0]++;		// x positivi e y positivi (I quadrante)
		else if(L[i].p1.re < 0 && L[i].p2.re < 0 && L[i].p1.im > 0 && L[i].p2.im > 0) D[1]++;		// x negativi e y positivi (II quadrante)
		else if(L[i].p1.re < 0 && L[i].p2.re < 0 && L[i].p1.im < 0 && L[i].p2.im < 0) D[2]++;		// x negativi e y negativi (III quadrante)
		else if(L[i].p1.re > 0 && L[i].p2.re > 0 && L[i].p1.im < 0 && L[i].p2.im < 0) D[3]++;		// x negativi e y negativi (IV quadrante)
	}

	for(i = 0; i < 4; i++) {										// in caso di pareggio viene considerato il quadrante con l'indice minore
		if (D[i] > max) {
			max = D[i];
			q = i+1;
		}
	}

	return q;

}

int main(int argc, char *argv[]) {

	int i, j, q, vectors;
	int N[] = {-5, -4, -3, -2, -1, 1, 2, 3, 4, 5};								// valori di x e y ammessi

	srand(getpid());											// utilizzo del PID del processo come seed per ottenere un vero numero casuale

	vectors = rand() % MAX_VECTORS + 1;									// numero casuale di vettori
	struct Segmento L[vectors];										// creazione dell'array di coordinate

	for(i = 0; i < vectors; i++) {										// inizializzazione dell'array di coordinate
		L[i].p1.re = N[rand() % 10];
		L[i].p1.im = N[rand() % 10];
		L[i].p2.re = N[rand() % 10];
		L[i].p2.im = N[rand() % 10];
		printf("Segmento %d\n", i+1); 
		printf("- Coordinate primo punto\t Re: %.f\t Im: %.f\n", L[i].p1.re, L[i].p1.im);		// z = x + iy
		printf("- Coordinate secondo punto\t Re: %.f\t Im: %.f\n", L[i].p2.re, L[i].p2.im); 		// z = x + iy
		for(j = 0; j < 80; j++) putchar('-');								// graphic divider
		printf("\n");
	}

	q = segmenti(L, vectors);										// calcolo del quadrante più popolato

	printf("Il quadrante che include il più alto numero di segmenti interi è il numero %d!\n", q);

	return 0;
}