//
// Created by ricca on 20/12/2024.
//

#ifndef ALLOCAZIONE_DINAMICA_E_LISTE_H
#define ALLOCAZIONE_DINAMICA_E_LISTE_H

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//Esercizio 1:
int leggi_ex1();

int *somme_cumulative_ex1(int N);

void stampa_ex1(int *v, int N);

//Esercizio 2:

void scambia_ex2(int *val1, int *val2);

//Esercizio 3:

typedef struct {
    int val1, val2;
    float val3;
    char string[20];
} struttura;

struttura*  assegna_struttura();

void stampa_struttura(struttura *data);

//Esercizio 4
void ex4();
int check_elemento_ex4(int value, int *vettore, int len);