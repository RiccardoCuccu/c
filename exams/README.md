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
