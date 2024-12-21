#ifndef TUTORATO6_H
#define TUTORATO6_H

#endif //TUTORATO6_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct {
    char cognome[30];
    int voto;
} studente;

typedef struct voto {
    char *preferenza;
    struct voto *next;
} listaVoti;

void tutorato6_ex1();

void tutorato6_ex2();

void tutorato6_ex3();

void tutorato6_ex4();