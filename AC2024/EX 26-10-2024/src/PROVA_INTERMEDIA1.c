#include "PROVA_INTERMEDIA1.h"

void lvl0_ex3() {
#define len 2
    float x[len];
    float y[len];

    do {
        for (int i = 0; i < len; i = i + 1) {
            printf("inserire l'ascissa X del punto %d:\n", i + 1);
            scanf("%f", &x[i]);
            printf("inserire l'ordinata Y del punto %d:\n", i + 1);
            scanf("%f", &y[i]);
        }
    } while (x[0] == y[0] && x[1] == y[1]);

    float distanza;
    float quota;
    float coefficiente_angolare;
    float traslazione;

    // controllo le posizioni dei dati inseriti
    if (x[0] > x[1]) {
        distanza = x[0] - x[1];
    } else
        distanza = x[1] - x[0];

    if (y[0] > y[1]) {
        quota = y[0] - y[1];
    } else
        quota = y[1] - y[0];

    // calcolo m e q
    coefficiente_angolare = (quota / distanza);
    traslazione = y[0] / (coefficiente_angolare * x[0]);

    printf("FUNZIONE: Y = %.2fX + %.2f\n", coefficiente_angolare, traslazione);
    printf("COEFF ANGOLARE: %.5f\n", coefficiente_angolare);
    printf("TRASLAZIONE RETTA: %.5f\n", traslazione);
}

void lvl1_ex2() {
#define len 2

    float a, b, c;

    printf("inserire il coefficente A:\n");
    scanf("%f", &a);
    printf("inserire il coefficente B:\n");
    scanf("%f", &b);
    printf("inserire il coefficente C:\n");
    scanf("%f", &c);


    // y = ax^2+bx+c
    // calcolo gli zeri
    float delta = sqrt(pow(b, 2) - 4 * a * c);
    float zeri[len];


    zeri[0] = (-b + delta) / a;
    zeri[1] = (-b - delta) / a;
    printf("\n%.2f\n%.2f\n", zeri[0], zeri[1]);
    //metto in ordine gli zeri
    if (zeri[0] > zeri[1]) {
        float temp = zeri[1];
        zeri[1] = zeri[0];
        zeri[0] = temp;
    }
    //controllo l'andamento della funzione
    if (a < 0) {
        printf("la funzione e' negativa per [X < %.2f & X >%.2f]", zeri[0], zeri[1]);
    } else { printf("la funzione e' negativa per [%.2f< X <%.2f]", zeri[0], zeri[1]); }
}


char lvl2_ex() {
#define len 3
#define zerilen 2
    float coefficenti[len];
    char coefficenti_name[] = {'A', 'B', 'C'};

    for (int i = 0; i < len; i++) {
        printf("inserire il coefficente %c:\n", coefficenti_name[i]);
        scanf("%f", &coefficenti[i]);
    }
    printf("\n%.2f\n%.2f\n", coefficenti[0], coefficenti[1]);

    if (coefficenti[0] == 0) {
        return "ERROR = A < 0";
    }

    // y = ax^2+bx+c
    // calcolo gli zeri
    float delta = sqrt(pow(coefficenti[1], 2) - 4 * coefficenti[0] * coefficenti[2]);
    if (delta < 0 || delta == 0) {
        return "ERROR = DELTA NOT VALID";
    }
    float zeri[zerilen];


    zeri[0] = (-coefficenti[1] + delta) / (2 * coefficenti[0]);
    zeri[1] = (-coefficenti[1] - delta) / (2 * coefficenti[0]);
    printf("\n%.2f\n%.2f\n", zeri[0], zeri[1]);
    //metto in ordine gli zeri
    if (zeri[0] > zeri[1]) {
        float temp = zeri[1];
        zeri[1] = zeri[0];
        zeri[0] = temp;
    }
    //controllo l'andamento della funzione tramite il valore A
    if (coefficenti[0] < 0) {
        printf("la funzione e' negativa per [X < %.2f & X >%.2f]\n", zeri[0], zeri[1]);
        // calcolo l'intervallo interno
        float intervallo;
        intervallo = sqrt((zeri[1] - zeri[0]));
        printf("l'intervallo positivo e'ampio [%.4f]\n", intervallo);
    } else { printf("la funzione e' negativa per [%.2f< X <%.2f]", zeri[0], zeri[1]); }
}
