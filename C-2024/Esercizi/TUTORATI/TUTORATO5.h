#ifndef TUTORATO5_H
#define TUTORATO5_H

#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 50

typedef struct {
    int N;
    int v1[DIM];
    int v2[DIM];
    int v3[DIM];
} vettori;

typedef struct {
    int N;
    int v1[DIM];
    int v2[DIM];
    int prodottoscalare;
} prodottoscalare;


void ex1_tutorato5(const int *vettore, int lenght, char *filename);

int ex2_tutorato5(int *vettore, int max_v, int min_v, int MAXLEN);

void ex3_tutorato5(const char *filename);

vettori ex4_tutorato5(vettori data);

prodottoscalare ex5_tutorato5(prodottoscalare data);