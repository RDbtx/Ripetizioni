#ifndef ESERCITAZIONE_SECONDO_PARZIALE_2_H
#define ESERCITAZIONE_SECONDO_PARZIALE_2_H

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Esercizio 1:
Definire una struttura dati tpubblicazione caratterizzata da
un intero numero_citazioni e un intero anno_pubblicazione.
*/

typedef struct pubblicazione {
    int numero_citazioni;
    int anno_pubblicazione;
    char nome_pubb[50];
} tpubblicazione;

//Esercizio 2:
int estraiAnnoMinimo(int *anno_pubblicazione, int n);

//Esercizio 3:
int leggiPubblicazioniDaFile(char *nome_file, tpubblicazione *pubb);

//Esercizio 4:
void StampaCitTitPerMaxPubb(tpubblicazione *pubb, int N_pubb);

//Esercizio 5:
int trovapubblicazione(tpubblicazione *pubb, int n, char *titolo);

//Esercizio 6:
int AggiungiPubblicazione(const char *nome_file, tpubblicazione nuova_pubb);

//Esercizio 7:
float calcolaMediaCitazioni(tpubblicazione *pubb, int n);

//Esercizio 8:
void ordinaPerCitazioni(tpubblicazione *pubb, int n);
