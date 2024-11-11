#include "RIPASSO_PARZIALE1.h"

void ex1() {
    int len;
    printf("Inserisci il numero limite:\n");
    scanf("%d", &len);

    int sum = 0;
    for (int i = 1; i <= len; i = i + 1) {
        sum = sum + i;
    }
    printf("la somma di tutti i numeri fino a %d e' = %d\n", len, sum);
}


void ex2() {
    int len;
    printf("Inserisci il numero limite:\n");
    scanf("%d", &len);

    for (int i = 1; i <= len; i = i + 1) {
        if (i % 2 == 0) {
            printf("%d ", i);
        };
    }
}

void ex3() {
    int len;
    printf("Inserisci il numero da valutare:\n");
    scanf("%d", &len);

    bool primo = true;
    for (int i = 2; i < len; i = i + 1) {
        if (len % i == 0) {
            primo = false;
        };
    }

    if (primo == true) {
        printf("%d = PRIMO", len);
    } else printf("%d = NON PRIMO", len);
}

void ex4() {
    int len;
    printf("Inserisci il numero da valutare:\n");
    scanf("%d", &len);

    for (int i = 1; i <= 10; i = i + 1) {
        printf("%d * %d = %d\n", len, i, len * i);
    }
}

void ex5() {
    int len;
    int sum = 0;
    printf("Inserisci il valore limite:\n");
    scanf("%d", &len);


    for (int i = 1; i <= len; i = i + 1) {
        if( i % 2 == 0) {
            sum = sum + i;
        }
    }
    printf("la somma di tutti i numeri pari fino a %d e' = %d", len, sum);
}

void ex6() {
#define arraylen 20
    int len;
    int array[arraylen];

    printf("Inserire la lunghezza dell array:\n");
    scanf("%d", &len);

    for (int i = 0; i < len; i = i + 1) {
        printf("inserire il valore %d:\n", i + 1);
        scanf("%d", &array[i]);
    }

    int max = array[0];
    for (int i = 0; i < len; i = i + 1) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    printf("Il valore massimo dell array e' = %d", max);
}


void ex8() {
    int len;
    int sum = 0;

    printf("Inserisci il valore limite:\n");
    scanf("%d", &len);

    for (int i = 1; i <= len; i = i + 1) {
        if( i % 3 == 0 || i % 5 == 0) {
            sum = sum + i;
        }
    }
    printf("la somma di tutti i numeri multipli di 3 e 5 fino a %d e' = %d", len, sum);
}


void ex9() {
#define numlen 20
    int numero[numlen];
    int len;

    printf("Inserisci il numero di cifre del numero che vuoi inserire:\n");
    scanf("%d", &len);

    for(int i = len - 1; i >= 0; i--) {
        printf("inserire la %d cifra:\n", i + 1);
        scanf("%d", &numero[i]);
    }

    for(int i = 0; i < len; i++) {
        printf("%d",numero[i]);
    }
}

void ex10() {
#define arraylen 20
    int len;
    int array[arraylen];

    printf("Inserire la lunghezza dell array:\n");
    scanf("%d", &len);

    float sum = 0;
    for (int i = 0; i < len; i = i + 1) {
        printf("inserire il valore %d:\n", i + 1);
        scanf("%d", &array[i]);
        sum = sum + array[i];
    }

    float media = sum / len;
    printf("la media dei numeri inseriti e' = %.3f", media);
}