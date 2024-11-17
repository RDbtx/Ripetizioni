#include "vettori.h"


/*
ESERCIZIO 1:
Dichiarare un array di 5 elementi interi, inizializzare i valori
(es: {1, 2, 3, 4,5}) e stamparli uno per uno utilizzando un ciclo for.
*/
void ex1_vettori() {
    int vettore[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", vettore[i]);
    }
}


/*
ESERCIZIO 2:
Creare un array di 5 elementi e permettere all'utente di inserire i valori.
Stampare i valori inseriti.
*/

void ex2_vettori() {
#define lenght 5
    int vettore[lenght];

    for (int i = 0; i < lenght; i++) {
        printf("inserisci il %d elemento", i + 1);
        scanf("%d", &vettore[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", vettore[i]);
    }
}


/*
ESERCIZIO 3:
Creare un array di 5 numeri interi e calcolare la somma di tutti gli elementi.
Stampare il risultato.
*/
void ex3_vettori() {
#define lenght 5
    int vettore[lenght];

    int sum = 0;
    for (int i = 0; i < lenght; i++) {
        printf("inserisci il %d elemento\n", i + 1);
        scanf("%d", &vettore[i]);
        sum = sum + vettore[i];
    }
    printf("La somma di tutti gli elementi del vettore e' = %d\n", sum);
}

/*
ESERCIZIO 4:
Creare un array di 10 elementi e cercare un numero specifico inserito
dall'utente. Stampare un messaggio se l'elemento è presente o meno.
*/
void ex4_vettori() {
    int vettore[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int search;
    bool found = false;

    for (int i = 0; i < 5; i++) {
        if (search == vettore[i]) {
            printf("%d e' presente nel vettore in posizione %d\n", search, i);
            found = true;
        }
    }
    if (found == false) {
        printf("L'elemento non e' stato trovato\n");
    }
}


/*
ESERCIZIO 5:
Creare un array di n numeri interi (l'utente specifica n e poi inserisce i valori).
Calcolare e stampare la media dei valori.
*/
void ex5_vettori() {
#define lenght 50
    float vettore[lenght];
    int len;
    float sum = 0;
    float media;

    printf("inserisci la lunghezza desiderata del vettore");
    scanf("%d", &len);

    for (int i = 0; i < len; i++) {
        printf("inserisci il %d elemento\n", i + 1);
        scanf("%f", &vettore[i]);
        sum = sum + vettore[i];
    }

    media = sum / len;

    printf("La media di tutti gli elementi del vettore e' = %f\n", media);
}

/*
ESERCIZIO 6:
Creare un array di 8 elementi e trovare il valore massimo e il valore minimo tra di
essi.
*/
void ex6_vettori() {
#define lenght 8
    int vettore[lenght];

    for (int i = 0; i < lenght; i++) {
        printf("inserisci il %d elemento\n", i + 1);
        scanf("%d", &vettore[i]);
    }
    int max = vettore[0];
    int min = vettore[0];

    for (int i = 0; i < lenght; i++) {
        if (vettore[i] > max) {
            max = vettore[i];
        }
        if (vettore[i] < min) {
            min = vettore[i];
        }
    }
    printf("MAX = %d\n", max);
    printf("MIN = %d\n", min);
}


/*
ESERCIZIO 7:
Creare un array di 6 elementi e stampare l'array al contrario rispetto all'ordine
originale.
*/
void ex7_vettori() {
#define lenght 6
    int vettore[lenght];

    for (int i = 0; i < lenght; i++) {
        printf("inserisci il %d elemento\n", i + 1);
        scanf("%d", &vettore[i]);
    }

    for (int i = lenght - 1; i >= 0; i--) {
        printf("%d ", vettore[i]);
    }
}


/*
ESERCIZIO 8:
Creare un array di 10 numeri interi e contare quanti sono pari e quanti sono
dispari.
*/
void ex8_vettori() {
#define lenght 10
    int vettore[lenght];
    int counter_even = 0;
    int counter_odd = 0;

    for (int i = 0; i < lenght; i++) {
        printf("inserisci il %d elemento\n", i + 1);
        scanf("%d", &vettore[i]);
    }

    for (int i = 0; i < lenght; i++) {
        if (vettore[i] % 2 == 0) {
            counter_even++;
        } else {
            counter_odd++;
        }
    }
}


/*
ESERCIZIO 9:
Creare un array di 5 elementi e copiarne i valori in un secondo array. Stampare il
secondo array per verificare il risultato.
*/
void ex9_vettori() {
#define lenght 5
    int vettore[lenght];
    int vettore_copia[lenght];

    for (int i = 0; i < lenght; i++) {
        printf("inserisci il %d elemento\n", i + 1);
        scanf("%d", &vettore[i]);
    }

    for (int i = 0; i < lenght; i++) {
        vettore_copia[i] = vettore[i];
    }
    for (int i = 0; i < lenght; i++) {
        printf("%d ", vettore_copia[i]);
    }
}


/*
ESERCIZIO 10:
Creare due array di 5 elementi ciascuno. Creare un terzo array che contenga la
somma degli elementi corrispondenti dei due array.
*/
void ex10_vettori() {
#define lenght 5
    int vettore1[lenght];
    int vettore2[lenght];
    int vettore_somma[lenght];

    for (int i = 0; i < lenght; i++) {
        printf("inserisci il %d elemento del primo vettore\n", i + 1);
        scanf("%d", &vettore1[i]);
    }
    for (int i = 0; i < lenght; i++) {
        printf("inserisci il %d elemento del secondo vettore\n", i + 1);
        scanf("%d", &vettore2[i]);
    }

    for (int i = 0; i < lenght; i++) {
        vettore_somma[i] = vettore1[i] + vettore2[i];
    }

    for (int i = 0; i < lenght; i++) {
        printf("%d", vettore_somma[i]);
    }
}

/*
ESERCIZIO 11:
Creare un array di 6 elementi e ruotare tutti gli elementi di una posizione verso
sinistra (il primo diventa l'ultimo).
*/
void ex11_vettori() {
#define lenght 6
    int vettore[lenght];

    for (int i = 0; i < lenght; i++) {
        printf("inserisci il %d elemento\n", i + 1);
        scanf("%d", &vettore[i]);
    }

    int temp = vettore[0];
    for (int i = 0; i < lenght - 1; i++) {
        vettore[i] = vettore[i] + 1;
    }
    vettore[lenght - 1] = temp;

    for (int i = 0; i < lenght; i++) {
        printf("%d ", vettore[i]);
    }
}

/*
ESERCIZIO 12:
Creare un array di 10 numeri e contare quante volte un numero specificato
dall'utente appare nell'array.
*/
void ex12_vettori() {
#define lenght 10
    int vettore[lenght];
    int counter = 0;

    for (int i = 0; i < lenght; i++) {
        printf("inserisci il %d elemento\n", i + 1);
        scanf("%d", &vettore[i]);
    }

    int search;
    printf("Inserisci il valore da cercar:\n");
    scanf("%d", &search);

    for (int i = 0; i < lenght; i++) {
        if (vettore[i] == search) {
            counter++;
        }
    }

    printf("L'elemento %d appare %d volte nell array", search, counter);
}
