#include "TUTORATO1.h"

/*
Esericizio 1:
Scrivere un programma che, data una variabile di tipo char
(carattere), ne stampi il relativo codice ASCII.
*/

void ex1_tutorato1() {
    char variable;

    printf("Inserisci una variabile (un carattere alfabetico):\n");
    scanf("%c", &variable);
    printf("Il valore ASCII della variabile '%c' e' %d\n", variable, variable);
}


/*
Esercizio 2:
Scrivere un programma che, dati in ingresso due valori di
tipo int, faccia rispettivamente lAND, lOR e lo XOR bit a bit. Loutput
devessere del tipo:
Bitwise AND: 4
Bitwise OR: 31
Bitwise XOR: 27
*/
void ex2_tutorato1() {
    int a, b;

    // Input dei due numeri interi
    printf("Inserisci il primo numero intero: ");
    scanf("%d", &a);

    printf("Inserisci il secondo numero intero: ");
    scanf("%d", &b);

    // Operazioni bit a bit
    int andResult = a & b; // AND bit a bit
    int orResult = a | b; // OR bit a bit
    int xorResult = a ^ b; // XOR bit a bit

    // Stampa dei risultati
    printf("Bitwise AND: %d\n", andResult);
    printf("Bitwise OR: %d\n", orResult);
    printf("Bitwise XOR: %d\n", xorResult);
}


/*
Esercizio 3:
Scrivere un programma che e etti la conversione tra gradi
Celsius e gradi Fahrenheit (entrambi float). Loutput devessere del tipo:
Celsius: 3.40 Fahrenheit: 38.12
Ricordate che TF = 1.8*TC +3
*/

void ex3_tutorato1() {
    float temp;
    float celsius, fahrenheit;

    int selector;

    do {
        printf("seleziona il formato:\n-1 CELSIUS\n-2 FARENHEIT\n");
        scanf("%d", &selector);
    } while (selector != 1 && selector != 2);

    printf("TEMP: ");
    scanf("%f", &temp);

    switch (selector) {
        case 1: fahrenheit = (1.8 * temp + 32);
            celsius = temp;
            break;
        case 2: fahrenheit = temp;
            celsius = (temp - 32) / 1.8;
            break;
    }

    printf("Celsius: %f\n", celsius);
    printf("farenheit: %f\n", fahrenheit);
}

/*
Esercizio 3:
Scrivere un programma che, dati 3 valori interi in ingresso e
 3 pesi, ne calcoli la media aritmetica e ponderata. Il programma deve poi
 stampare a video un output del tipo:
 La media aritmetica dei valori e pari a 101.00,
 mentre quella ponderata e pari a 54.89
*/


void ex4_tutorato1() {
    int voti_esami[3];
    int valore_esami[3];
    float media_ponderata;
    float prodotti = 0;
    float divisore = 0;

    for (int i = 0; i < 3; i++) {
        printf("inserire voto esame %d:\n", i + 1);
        scanf("%d", &voti_esami[i]);
        printf("inserire peso esame %d:\n", i + 1);
        scanf("%d", &valore_esami[i]);

        prodotti = prodotti + (valore_esami[i] * voti_esami[i]);
        divisore = divisore + valore_esami[i];
    };

    printf("prodotti: %.2f\n", prodotti);
    printf("divisore: %.2f\n", divisore);
    media_ponderata = (prodotti / divisore);
    printf("media ponderata = %.3f", media_ponderata);
}

/*
Esercizio 5:
Scrivere un programma che, dato in ingresso un valore di
tipo float, rappresentante il raggio di cerchio, ne stampi a video larea e la
circonferenza. A tal proposito, considerando una sfera con il medesimo raggio, stampare a
video anche la super cie e il volume di tale sfera.
*/

void ex5_tutorato1() {
#define PI 3.14159
    float raggio;

    // Input del raggio
    printf("Inserisci il raggio del cerchio/sfera: \n ");
    scanf("%f", &raggio);

    // Calcolo dell'area e della circonferenza del cerchio
    float area_cerchio = PI * pow(raggio, 2);
    float circonferenza = 2 * PI * raggio;

    // Calcolo della superficie e del volume della sfera
    float superficie_sfera = 4 * PI * pow(raggio, 2);
    float volume_sfera = (4 / 3) * PI * pow(raggio, 3);

    // Stampa dei risultati
    printf("\nArea del cerchio: %.2f\n", area_cerchio);
    printf("Circonferenza del cerchio: %.2f\n", circonferenza);
    printf("Superficie della sfera: %.2f\n", superficie_sfera);
    printf("Volume della sfera: %.2f\n", volume_sfera);
}
