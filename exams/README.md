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
Si scriva un programma C, opportunamente organizzato in funzioni, che legga da tastiera il nome del file e stampi il valore della somma dei numeri ivi contenuti. Nell’esempio il programma deve stampare `1588`.<br/>
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
