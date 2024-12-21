#include "allocazione_dinamica_e_liste.h"

/*
ESERCIZIO 1:
Scrivere una funzione somme_cumulative C che, ricevendo in ingresso
una variabile intera N, restituisca un vettore di N+1 elementi che contenga
nella posizione i le somme cumulative da 0 a i. Scrivere un programma C che,
ricevendo da tastiera un intero N, stampi a video le somme cumulative
contenute in un vettore definito come sopra.
Per risolvere il problema si scrivano inoltre le seguenti funzioni:
• Una funzione leggi che legga da tastiera un intero N e lo restituisca
• Una funzione stampa che ricevendo in ingresso un vettore di interi lo stampi su file
«output.txt»
*/

int leggi_ex1() {
    int N;
    printf("inserire limite somma cumulativa:\n");
    scanf("%d", &N);
    return N;
}

void stampa_ex1(int *v, int N) {
    for (int i = 0; i <= N; i++) {
        printf("%d ", v[i]);
    }
}

int *somme_cumulative_ex1(int N) {
    int *v;
    v = (int *) malloc(sizeof(int) * N);
    v[0] = 0;
    for (int i = 1; i <= N; i++) {
        v[i] = i + v[i - 1];
    }
    return v;
}

/*
ESERCIZIO 2:
Scrivere una funzione che, ricevendo due valori interi, assegnati alle
variabili a e b, scambi i contenuti delle due variabili
*/

void scambia_ex2(int *val1, int *val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

/*
ESERCIZIO 3:
Definire un tipo strutturato composto da due interi, un
float e una stringa di 20 caratteri e chiamarlo strut:
• Scrivere una funzione assegnaStrut() che
restituisca il puntatore a variabile strut allocata ed
assegnata con valori di ciascuno slot immessi da
tastiera
• Scrivere un programma che stampi su video gli slot di
una variabile di tipo strut
*/

struttura *assegna_struttura_ex3() {
    struttura *data;
    data = (struttura *) malloc(sizeof(struttura));
    printf("inserire il valore 1:\n");
    scanf("%d", &data->val1);
    printf("inserire il valore 2:\n");
    scanf("%d", &data->val2);
    printf("inserire il valore 3:\n");
    scanf("%f", &data->val3);
    printf("inserire la stringa\n");
    scanf("%s", &data->string);

    return data;
}

void stampa_struttura_ex3(struttura *data) {
    printf("val1 = %d\n", data->val1);
    printf("val2 = %d\n", data->val2);
    printf("val3 = %f\n", data->val3);
    printf("string = %s\n", data->string);
}


/*
ESERCIZIO 4:
Scrivere un programma C che, leggendo da file ‘dati.txt’ una
sequenza di interi, li memorizzi in un vettore v
• Se il valore letto è già stato inserito, il valore non deve essere
aggiunto al vettore
• La dimensione massima del vettore NON è nota e non deve essere
fissata a priori.
• Il vettore ottenuto sia salvato nel file ‘output.txt’
Esempio:
Dati nel file dati.txt: 12 25 1 4 25 2 2 1 12 30
Dati nel file output.txt: 12 25 1 4 2 30

*/

int check_elemento_ex4(int value, int *vettore, int len) {
    for (int i = 0; i < len; i++) {
        if (vettore[i] == value) {
            return 1;
        }
    }
    return 0;
}

void ex4() {
    FILE *fp = fopen("dati.txt", "r");
    if (fp == NULL) {
        printf("Errore file 'output.txt' non trovato!");
        return;
    }
    int *v;
    v = (int *) malloc(sizeof(int) * 50);
    if (v == NULL) {
        printf("Errore: allocazione della memoria fallita.\n");
        fclose(fp);
        return;
    }

    int value, controllo_lettura, indice = 0;
    while (indice < 50) {
        controllo_lettura = fscanf(fp, "%d", &value);
        if (controllo_lettura != 1) {
            break;
        }
        if (check_elemento_ex4(value, v, indice) != 1) {
            v[indice] = value;
            indice++;
        }
    }
    fclose(fp);
    FILE *fp2 = fopen("output.txt", "w");
    if (fp2 == NULL) {
        printf("Errore: file 'output.txt' non trovato!\n");
        free(v);
        return;
    }
    for (int i = 0; i < indice; i++) {
        fprintf(fp2, "%d\n", v[i]);
    }

    fclose(fp2);
    free(v);
}
