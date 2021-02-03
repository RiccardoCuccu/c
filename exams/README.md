# C exams
The texts of the exams contained here were taken from the [lecture notes](http://www.diegm.uniud.it/schaerf/Fondamenti/dispensa.pdf) of the Foundations of Computer Science of the course of Mechanical Engineering (A.A. 2013-14) of the University of Udine and are for this reason in Italian.<br/>

## [Exam 01](https://github.com/RiccardoCuccu/c/blob/master/exams/ex01.c)
Un file contiene una sequenza (di lunghezza ignota) di numeri interi positivi, uno per riga. I numeri sono scritti in lettere cifra per cifra, e sono terminati dalla parola `stop`. Come esempio si consideri il seguente file:
```
otto cinque nove stop
due due stop
sette zero sette stop
```
Il file contiene i numeri `859`, `22` e `707`.<br/>
Si scriva un programma C, opportunamente organizzato in funzioni, che legga da tastiera il nome del file e stampi il valore della somma dei numeri ivi contenuti. Nell'esempio il programma deve stampare `1588`.<br/>
Si assuma che i numeri siano di dimensione tale da essere rappresentabili tramite il tipo `int`.

## [Exam 02](https://github.com/RiccardoCuccu/c/blob/master/exams/ex02.c)
Si consideri il seguente gioco a due giocatori. In una partita vengono lanciati un dado per ogni giocatore ed una sola moneta. Se il lancio della moneta è testa, la partita è vinta dal giocatore che ha ottenuto il punteggio più alto nel lancio del proprio dado. Se invece esce croce, la partita è vinta dal giocatore che ha ottenuto il punteggio più basso. Se i dadi hanno lo stesso valore la partita è un pareggio.<br/>
Si consideri la seguente definizione di tipo
```
struct Partita {
  char moneta;
  int ris_dado1;
  int ris_dado2;
};
```
che rappresenta il risultato dei lanci associati ad una partita. I campi `ris_dado1` e `ris_dado2` hanno un valore compreso tra 1 e 6, e il campo `moneta` ha valore `t` (testa) oppure `c` (croce).<br/>
Si scriva una funzione C che dati come parametri un vettore di partite e la sua lunghezza restituisca:
- `1` se il giocatore 1 ha vinto più partite del giocatore 2;
- `-1` se il giocatore 2 ha vinto più partite del giocatore 1;
- `0` in caso di pari numero di vittorie.

Si scriva infine la funzione `main` necessaria per verificare la correttezza della funzione precedente.

## [Exam 03](https://github.com/RiccardoCuccu/c/blob/master/exams/ex03.c)
Un file contiene una sequenza (di lunghezza ignota) di studenti iscritti per una prova d'esame. Ogni riga del file contiene la matricola, il nome, il cognome e l'anno di corso di uno studente, più un eventuale commento. Come esempio si consideri il seguente file.
```
29333 Mario,      Rossi,    2 RG
34211 Irene,      De Neri,  3 FC
23432 Pier Maria, Bianchi,  3 RG ciao mamma
35211 Giuseppe,   Verdi,    4 FC odio questo esame!
22222 Chiara,     Blu,      2 RG
```
Si noti che il nome e il cognome possono contenere spazi bianchi e sono seguiti da una virgola. Si noti inoltre che l'anno di corso è composto da un numero, uno spazio bianco e i due caratteri `FC` o `RG`, a seconda che lo studente sia fuori corso o regolare, rispettivamente. Si assuma infine che il numero di spazi bianchi dopo la virgola sia arbitrario.<br/>
Si scriva una funzione C che prenda come parametri il nome del file e un anno di corso (un intero tra 1 e 5), e restituisca il numero di studenti iscritti fuori corso per quell'anno.<br/>
Nel caso che il file non esista, oppure l'anno di corso non sia compreso tra 1 e 5 la funzione deve restituire il valore `-1`.

Si scriva infine la funzione `main` necessaria per verificare la correttezza della funzione precedente, questa deve ricevere il nome del file e l'anno di corso sulla linea di comando.

## [Exam 04](https://github.com/RiccardoCuccu/c/blob/master/exams/ex04.c)
Si considerino le seguenti definizioni di tipo che rappresentano rispettivamente un numero complesso ed un segmento nel piano complesso (identificato dai suoi estremi).
```
struct Complesso {
  float re;         /* parte reale */   
  float im;         /* parte immaginaria */
};
```
```
struct Segmento {
  struct Complesso p1;
  struct Complesso p2;
};
```
Diciamo che un segmento *appartiene* ad un quadrante (tra 1 e 4) se entrambi i suoi estremi sono contenuti nello stesso quadrante. Se gli estremi sono in quadranti diversi, un segmento non appartiene ad alcun quadrante. Si assuma che i punti non possano giacere sugli assi del piano.<br/>
Si scriva una funzione C che prenda come parametri un vettore di segmenti e la sua dimensione e restituisca un valore tra 1 e 4 che corrisponde al quadrante del piano complesso a cui appartiene il maggior numero di segmenti.

## [Exam 05](https://github.com/RiccardoCuccu/c/blob/master/exams/ex05.c)
Un file contiene una sequenza (di lunghezza ignota) di uguaglianze tra somme di interi positivi, una per riga, ciascuna terminata da un punto e virgola, e senza spazio bianchi. Come esempio, si consideri il seguente file:
```
2+3+12=9+8;
2+3+4=9;
22=3+4+5+10;
3+5+1=4+44;
```
Si noti che le uguaglianze possono essere sia corrette (le prime tre) che sbagliate (l'ultima).<br/>
Si scriva una funzione C che prenda come parametro il nome del file e restituisca la frazione di uguaglianze corrette del file. Nell'esempio la funzione deve restituire 0.75.
