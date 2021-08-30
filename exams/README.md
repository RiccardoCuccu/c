# C exams
The texts of the exams contained here were taken from the [lecture notes](http://www.diegm.uniud.it/schaerf/Fondamenti/dispensa.pdf) of the Foundations of Computer Science of the course of Mechanical Engineering (A.A. 2013-14) of the University of Udine and are for this reason in Italian.<br/>

## [Exam 01 - 19/03/2001](https://github.com/RiccardoCuccu/c/blob/master/exams/ex01.c)
Un file contiene una sequenza (di lunghezza ignota) di numeri interi positivi, uno per riga. I numeri sono scritti in lettere cifra per cifra, e sono terminati dalla parola `stop`. Come esempio si consideri il seguente file:
```
otto cinque nove stop
due due stop
sette zero sette stop
```
Il file contiene i numeri `859`, `22` e `707`.<br/>
Si scriva un programma C, opportunamente organizzato in funzioni, che legga da tastiera il nome del file e stampi il valore della somma dei numeri ivi contenuti. Nell'esempio il programma deve stampare `1588`.<br/>
Si assuma che i numeri siano di dimensione tale da essere rappresentabili tramite il tipo `int`.

## [Exam 02 - 19/03/2001](https://github.com/RiccardoCuccu/c/blob/master/exams/ex02.c)
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

## [Exam 03 - 02/04/2001](https://github.com/RiccardoCuccu/c/blob/master/exams/ex03.c)
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

## [Exam 04 - 02/04/2001](https://github.com/RiccardoCuccu/c/blob/master/exams/ex04.c)
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

## [Exam 05 - 09/07/2001](https://github.com/RiccardoCuccu/c/blob/master/exams/ex05.c)
Un file contiene una sequenza (di lunghezza ignota) di uguaglianze tra somme di interi positivi, una per riga, ciascuna terminata da un punto e virgola, e senza spazio bianchi. Come esempio, si consideri il seguente file:
```
2+3+12=9+8;
2+3+4=9;
22=3+4+5+10;
3+5+1=4+44;
```
Si noti che le uguaglianze possono essere sia corrette (le prime tre) che sbagliate (l'ultima).<br/>
Si scriva una funzione C che prenda come parametro il nome del file e restituisca la frazione di uguaglianze corrette del file. Nell'esempio la funzione deve restituire 0.75.

## [Exam 06 - 09/07/2001](https://github.com/RiccardoCuccu/c/blob/master/exams/ex06.c)
Le immagini *bitmap* sono rappresentate mediante una matrice di punti (pixel) ciascuno dei quali è descritto da una tripletta di colori RGB, che contiene i valori di intensità, da 0 a 255, dei tre colori fondamentali rosso, verde e blu. Si considerino dei file bitmap organizzati come segue: la prima riga contiene, nell'ordine, i due numeri interi *N* e *M* che rappresentano il numero di righe e il numero di colonne della matrice di pixel; poi il file contiene le triplette che rappresentano i pixel (un pixel per riga) a partire dalla prima riga, prima colonna (pixel in alto a sinistra nell'immagine), e procedendo con tutte le colonne della riga. Ogni pixel è rappresentato dai tre numeri nella sequenza: rosso, verde, blu.<br/>
Ad esempio, il file seguente rappresenta un'immagine 3 × 4 (4 righe e 3 colonne) con un punto in alto a sinistra bianco (i tre colori sono al massimo dell'intensità) e il resto della prima riga nero (tutti zeri); poi una riga grigia, e due righe con punti rossi (255, 0, 0), verdi (0, 255, 0), blu (0, 0, 255), azzurri (0, 255, 255), gialli (255, 255, 0) e magenta (255, 0, 255).
```
4 3
255 255 255
0 0 0
0 0 0
127 127 127
127 127 127
127 127 127
255 0 0 0
255 0 0
255 255
0 0 255
255 255 0
255 0 255
```
Si scriva un programma che trasformi un'immagine bitmap a colori in un'altra in bianco e nero, cioè in cui i tre colori di ogni tripletta hanno uguale intensità, pari alla media delle intensità dei colori del pixel originale. Inoltre, il programma deve aggiungere alla figura un contorno costituito da una linea bianca (spessa un pixel).<br/>
Il file seguente è il risultato del programma applicato al file precedente.
```
6 5
255 255 255
255 255 255
255 255 255
255 255 255
255 255 255
255 255 255
255 255 255
0 0 0
0 0 0
255 255 255
255 255 255
127 127 127
127 127 127
127 127 127
255 255 255
255 255 255
85 85 85
85 85 85
170 170 170
255 255 255
255 255 255
85 85 85
170 170 170
170 170 170
255 255 255
255 255 255
255 255 255
255 255 255
255 255 255
255 255 255
```
I nomi dei file bitmap di ingresso e di uscita devono essere passati come parametri sulla linea di comando. Si supponga che le immagini abbiano dimensioni massime 600 × 480 (colonne × righe).

## [Exam 07 - 23/07/2001](https://github.com/RiccardoCuccu/c/blob/master/exams/ex07.c)
Lo schema di un cruciverba è memorizzato in un file nel seguente formato: la prima riga contiene due numeri interi che indicano, rispettivamente, il numero di righe e il numero di colonne del cruciverba; le righe successive riportano le righe del cruciverba, con uno spazio in corrispondenza delle caselle nere. Come esempio si consideri il file seguente.
```
8 6
SUGLI
ODIATI
TIRI N
TRI CD
IE POI
L MELA
EDISON
CAINO 
```
Come è noto, è necessaria una definizione per ogni parola, verticale o orizzontale, lunga almeno due lettere. Si scriva un programma C che riceva come argomento sulla linea di comando il nome del file contenente il cruciverba e scriva nel file `parole.txt` l'elenco delle parole di cui serve una definizione, suddivise in orizzontali e verticali (separate da una linea vuota). Non si richiede che l'ordine in cui compaiono le parole nel file sia lo stesso con cui vengono numerate le definizioni dei normali cruciverba.<br/>
Si assuma che la dimensione massima di un cruciverba sia 50 × 50. Nell'esempio, il file `parole.txt` sarà il seguente.
```
SUGLI
ODIATI
TIRI
TRI
CD
IE
POI
MELA
EDISON
CAINO

SOTTILE
UDIRE
DC
GIRI
MIA
LAI
PESI
IT
COLON
INDIANO
```
Il programma deve essere realizzato in modo modulare, scomponendolo nelle seguenti funzioni:
- la funzione `main` con passaggio dell'argomento sulla linea di comando;
- una funzione di lettura del cruciverba dal file;
- una funzione di ricerca delle parole e scrittura sul file.

## Exam 08 - 06/09/2001
Un robot è in grado di muoversi nel piano nelle quattro direzioni nord, sud, est ed ovest (denotate rispettivamente dai caratteri `N`, `S`, `E` ed `O`). In particolare, il robot accetta comandi che consistono in una direzione e un intero positivo, che rappresenta la distanza (in metri) da percorrere in quella direzione.<br/>
I comandi sono immagazzinati in un file, in cui ogni riga contiene un comando, e vengono eseguiti dal robot in sequenza.<br/>
Si riportano, come esempio, tre file di comandi:
```
N 10           | N 10           | N 10           |
E 5            | E 5            | E 5            |
S 4            | S 4            | S 4            |
S 9            | S 6            | S 6            |
O 3            | O 3            | O 5            |
---------------+----------------+----------------+
ESEMPIO 1      | ESEMPIO 2      | ESEMPIO 3      |
```

### [Exam 08.1](https://github.com/RiccardoCuccu/c/blob/master/exams/ex08.1.c)
Dopo avere eseguito i comandi contenuti nel file di input, il robot si è spostato, rispetto alla posizione iniziale, in due (cfr. esempio 1), una (cfr. esempio 2) o nessuna (cfr. esempio 3) delle quattro direzioni `N`, `S`, `E` ed `O`.<br/>
Scrivere un funzione C che, ricevuto come parametro il nome del file di input, stampi su schermo in quali direzioni e di quanti metri si è spostato il robot. Ad esempio, facendo riferimento ai file sopra riportati, si devono effettuare le stampe:
```
3 METRI VERSO S | 2 METRI VERSO E |               |
2 METRI VERSO E |                 |               |
----------------+-----------------+---------------+
ESEMPIO 1       | ESEMPIO 2       | ESEMPIO 3     |
```

### [Exam 08.2](https://github.com/RiccardoCuccu/c/blob/master/exams/ex08.2.c)
Si vuole determinare la sequenza di comandi, della stessa lunghezza di quella di input, da dare al robot per tornare al punto di partenza ripercorrendo a ritroso esattamente la
stessa strada.<br/>
Si scriva una funzione C che prenda come parametro il nome del file di input ed il nome di un file di output e scriva sul file di output la sequenza determinata. Si assuma che la lunghezza massima della sequenza di comandi sia pari a 100.<br/>
Ad esempio, facendo riferimento ai file sopra riportati, le sequenze di comandi che fanno ritornare il robot al punto di partenza sono le seguenti:
```
E 3            | E 3            | E 5            |
N 9            | N 6            | N 6            |
N 4            | N 4            | N 4            |
O 5            | O 5            | O 5            |
S 10           | S 10           | S 10           |
---------------+----------------+----------------+
ESEMPIO 1      | ESEMPIO 2      | ESEMPIO 3      |
```

## [Exam 09 - 20/09/2001](https://github.com/RiccardoCuccu/c/blob/master/exams/ex09.c)
Un dato linguaggio di programmazione prevede l'inserimento di commenti nel codice sorgente mediante il carattere `#` che deve precedere il testo del commento. Il commento termina alla fine della riga. Come esempio si consideri il seguente file.
```
# questo è un commento
start:	xor r0 r0	# questo è un altro commento
	mv r1 r2	# ecc.
# inizia il ciclo
loop:	ldbr r3 r2	# copia in R3 l'i-esimo carattere della stringa
	jmpz end	# se vale zero ('\0') la stringa è finita
	inc r0		# incrementa il contatore
	inc r2		# incrementa il puntatore
	jmp loop	# ripete
end:	ret
# (commento) fine del programma
```

Si scriva una funzione C che riceva come parametro il nome del file sorgente contenente i commenti, che ha estensione .tic, e scriva un file con il medesimo nome ma estensione .toc contenente soltanto tutte le istruzioni e non i commenti. Il file risultante dall'esempio sarà:
```
start:	xor r0 r0
	mv r1 r2
loop:	ldbr r3 r2
	jmpz end
	inc r0
	inc r2
	jmp loop
end:	ret
```

## [Exam 10 - 30/06/2003](https://github.com/RiccardoCuccu/c/blob/master/exams/ex10.c)
Un file contiene una sequenza di lunghezza ignota (massimo 20) di risultati di partite di calcio (uno per riga). I risultati sono scritti nel formato illustrato dal seguente file di esempio.
```
Genoa - Ascoli		1-2
Ancona - Bari		1-2
Cosenza - Catania	3-1
Siena - Livorno		2-0
Palermo - Napoli	2-1
Triestina - Ternana	4-3
Messina - Venezia	1-1
Lecce - Hellas_Verona	1-1
```

I nomi delle squadre non contengono spazi e sono separati da uno spazio, un trattino (-) ed un altro spazio; i nomi e i gol segnati sono separati da uno o più spazi; i gol segnati sono separati tra loro dal trattino (senza spazi).<br/>
Si scriva una funzione C che prenda come parametro il nome di un file nel formato suddetto e modifichi il file stesso aggiungendo alla fine di ciascuna riga il simbolo del totocalcio corrispondente al risultato (1 ha vinto la prima squadra, 2 ha vinto la seconda squadra, X pareggio, cioè le squadre hanno segnato lo stesso numero di gol).<br/>
Ad esempio, se il file è quello qui sopra la funzione deve modificarlo facendogli assumere il seguente contenuto.
```
Genoa - Ascoli 1-2 2
Ancona - Bari 1-2 2
Cosenza - Catania 3-1 1
Siena - Livorno 2-0 1
Palermo - Napoli 2-1 1
Triestina - Ternana 4-3 1
Messina - Venezia 1-1 X
Lecce - Hellas_Verona 1-1 X
```

**Suggerimento**: per poter scrivere sullo stesso file è consigliato copiare tutto il contenuto del file in una opportuna struttura dati in memoria centrale e successivamente ritrasferire i dati dalla memoria al file (a questo scopo è necessario aprire e chiudere il file due volta con modalità diverse).

## [Exam 11 - 30/06/2003](https://github.com/RiccardoCuccu/c/blob/master/exams/ex11.c)
Si consideri una matrice di caratteri 8 × 8 che contiene la posizione di una partita di scacchi. I pezzi bianchi sono rappresentati dalla loro iniziale minuscola: `r`, `d`, `a`, `c`, `t`, e `p` rispettivamente per re, donna, alfiere, cavallo, torre e pedone; i pezzi neri sono rappresentati dalla stessa iniziale maiuscola `R`, `D`, `A`, `C`, `T`, e `P`. Le caselle vuote sono rappresentate dallo spazio. Ad esempio la seguente matrice rappresenta la posizione iniziale.
```
t c a r d a c t
p p p p p p p p




P P P P P P P P
T C A R D A C T
```

Si vuole scrivere una funzione che valuti chi è in vantaggio nella posizione corrente dal punto di vista del materiale presente sulla scacchiera. A questo scopo si usi la seguente valutazione dei pezzi: pedone = 1, cavallo = 3, alfiere = 3, torre = 5, donna = 9, re = non ha valore.<br/>
Si scriva una funzione C (opportunamente modularizzata tramite funzioni ausiliarie) che prenda come parametro una matrice siffatta e restituisca:
- `1` se il bianco ha più materiale del nero;
- `2` se il nero ha più materiale del bianco;
- `0` se il materiale è pari;
- `-1` se la posizione sulla scacchiera non è legale.

Ad esempio, se viene passata la posizione iniziale, la funzione deve restituire `0`, perché il materiale è pari (39 ciascuno: 5+3+3+9+3+3+5+1+1+1+1+1+1+1+1).<br/>
Una posizione non è legale solo nei seguenti tre casi:
- un pedone si trova nella riga 0 oppure nella riga 7;
- uno dei due re non è presente sulla scacchiera;
- il numero di cavalli di un giocatore è maggiore di due.

**Suggerimento**: possono risultare utili le funzioni `islower(char)` e `isupper(char)` che restituiscono 1 se il parametro è un carattere alfabetico minuscolo o maiuscolo rispettivamente; e la funzione `tolower(char)` che restituisce il carattere alfabetico minuscolo corrispondente al parametro maiuscolo (e restituisce il parametro stesso negli altri casi).
