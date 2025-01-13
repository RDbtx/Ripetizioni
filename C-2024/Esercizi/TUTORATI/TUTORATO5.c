#include "TUTORATO5.h"

/*
Esercizio 1:
Scrivere una funzione in C che, ricevendo un vettore v di n interi
e il nome di un file, scriva su questo file l'indice
corrispondente al valore massimo presente nel vettore
*/
void ex1_tutorato5(const int *vettore, int lenght, char *filename) {
    int max = vettore[0];
    int max_i = 0;
    for (int i = 1; i < lenght; i++) {
        if (vettore[i] > max) {
            max = vettore[i];
            max_i = i;
        }
    }
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File non trovato");
    }
    fprintf(fp, "%d\n", max_i);
    fclose(fp);
}

/*
Esercizio 2:
Scrivere una funzione che, ricevendo in ingresso un vettore di massimo
N elementi interi, e due interi max_v e min_v, inserisca nel vettore elementi compresi tra min_v e max_v,
letti da un file il cui nome viene richiesto all’utente dalla funzione stessa,
fermando la lettura quando si inserisce un valore al di fuori di tale intervallo.
La funzione scrive su un file output.txt il numero di elementi complessivamente inseriti nel vettore.
*/

int ex2_tutorato5(int *vettore, int max_v, int min_v, int MAXLEN) {
    char file[256];
    printf("selezionare il nome del file:\n");
    scanf("%255s", file);
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        printf("File non trovato");
        return 0;
    }
    int value, controllo_lettura, indice = 0;
    while (indice < MAXLEN) {
        controllo_lettura = fscanf(fp, "%d", &value);
        if (controllo_lettura != 1) {
            break;
        }
        if (value >= min_v && value <= max_v) {
            vettore[indice] = value;
            indice++;
        }
    }
    fclose(fp);
    return indice;
}
/*
Esercizio 3:
Scrivere una funzione che, ricevendo in ingresso il nome di due file, legga la stringa di caratteri
alfabetici contenuta nel primo file e scriva sul secondo file una stringa sostituendo a ogni lettera
della stringa letta dal primo file quella che la segue nell'ordinamento alfabetico, considerando l'alfabeto
come circolare (quindi il carattere che segue 'z' è 'a', e quello che segue 'Z' è 'A').
Durante la codifica, si lascino invariati tutti i caratteri non alfabetici.
Esempio: se il primo file contiene la stringa "CODICESEGRETO", il secondo file conterrà "DPEJDFTFHSFUP"
*/
void ex3_tutorato5(const char *finput const char *foutput) {
#define MAXLEN 50
    char temp[MAXLEN];
    FILE *fp = fopen(finput, "r");
    if (fp == NULL) {
        printf("Errore file non trovato!");
    }
    int controllo_lettura, indice = 0;
    char value;
    while (indice < MAXLEN) {
        controllo_lettura = fscanf(fp, "%c", &value);
        if (controllo_lettura != 1) {
            break;
        }
        temp[indice] = value;
        indice++;
    }
    temp[indice] = '\0';
    fclose(fp);

    for (int i = 0; i < indice; i++) {
        if (temp[i] == 'z') {
            temp[i] = 'a';
        } else if (temp[i] == 'Z') {
            temp[i] = 'A';
        } else {
            temp[i] = temp[i] + 1;
        }
    }

    FILE *foutput = fopen(foutput, "w");
    if (foutput == NULL) {
        printf("Errore file non trovato!");
        return;
    }
    fprintf(foutput, "%s\n", temp);
}

/*
Esercizio 4:
Definire un tipo di dati strutturato Vettori, caratterizzato da un intero N, due vettori v1 e v2 di
dimensione fissa N e da un vettore v3, contenente la somma degli elementi corrispondenti di v1
e v2.
Scrivere una funzione che, ricevendo in ingresso una variabile di tipo Vettori, aggiorni lo slot v3
con la somma degli elementi corrispondenti di v1 e v2 e restituisca la struttura aggiornata.
Esempio: se v1 = {1, 5, 11, 3, 2} e v2 = {4, 3, 10, 1, 12} ==> v3 = {5, 8, 21, 4, 14}
*/
vettori ex4_tutorato5(vettori data) {
    for (int i = 0; i < data.N; i++) {
        data.v3[i] = data.v1[i] + data.v2[i];
    }
    return data;
}

/*
Definire un tipo di dati strutturato ProdottoScalare, caratterizzato da un intero N, due vettori v1 e
v2 di dimensione fissa N e da un intero prodotto_scalare, contenente il prodotto scalare tra i due
vettori.
Scrivere una funzione che, ricevendo in ingresso una variabile di tipo ProdottoScalare, aggiorni lo
slot prodotto_scalare con il prodotto scalare tra i due vettori v1 e v2
*/
prodottoscalare ex5_tutorato5(prodottoscalare data) {
    data.prodottoscalare = 0;
    for (int i = 0; i < data.N; i++) {
        data.prodottoscalare = data.prodottoscalare + (data.v1[i] * data.v2[i]);
    }
    return data;
}
