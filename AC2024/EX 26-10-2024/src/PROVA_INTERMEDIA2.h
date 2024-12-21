#ifndef PROVA_INTERMEDIA2_H
#define PROVA_INTERMEDIA2_H

#endif //PROVA_INTERMEDIA2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/*
Lvl 0 Ex1:
Definire una struttura dati tpubblicazione caratterizzata da un intero
numero_citazioni e un intero anno_pubblicazione.
*/

typedef struct {
    int numero_citazioni;
    int anno_pubblicazione;
} tpubblicazione;

//Lvl 0 Ex2:
int estrai_prossimo(tpubblicazione *data, int len);

//Lvl 0 Ex3:
int leggiPubblicazioni(const char *nome_file, tpubblicazione *pubb);

//Lvl 0 Ex4:
void lvl0_ex4(void);

//Lvl 1 Ex2:
int cerca_citazioni(tpubblicazione *data, int len, int numero_citazioni);

/*
Lvl 2 Ex1:
Si definisca il tipo strutturato tricercatore composto da una stringa nome, da un
intero n_pubb, e da un vettore di massimo N variabili di tipo tpubblicazione.
Si definisca un tipo lista concatenata listaRicercatori di variabili di tipo
tricercatore definito nell’esercizio 0.2.
*/

typedef struct tricercatore {
    char *nome;
    int n_pubblicazioni;
    tpubblicazione pubblicazioni[50];
    struct tricercatore *next;
} ListaRicercatori;

//Lvl 2 Ex 2:
void lvl2_ex2(void);
