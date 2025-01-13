#ifndef STRUCTURES_H
#define STRUCTURES_H

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definizione della struct Persona
struct Persona {
    char nome[50];
    int età;
    float altezza;
};

//Esercizio 1:
void selectionSort(struct Persona arr[], int n);
//Esercizio 2:
void stampaPersone(struct Persona arr[], int n);