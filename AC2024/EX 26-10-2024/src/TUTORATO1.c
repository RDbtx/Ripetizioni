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

    //stampo la variabile in %c (per vedere il suo carattere) e in %d (per vedere il suo codice ASCII)
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

    //uso il ciclo do while per controllare che i valori in ingresso siano o 1 o 2
    do {
        //seleziono il formato della temperatura in ingresso, celsius o farenheit
        printf("seleziona il formato:\n-1 CELSIUS\n-2 FARENHEIT\n");
        scanf("%d", &selector);
    } while (selector != 1 && selector != 2);

    //inserisco la temperatura
    printf("TEMP: ");
    scanf("%f", &temp);

    //uso lo switch per capire quale conversione fare in base al valore del selettore
    switch (selector) {

        //se la temperatura in ingresso è in celsius calcolo il corrispondente in fahrenheit
        case 1: fahrenheit = (1.8 * temp + 32);
            celsius = temp;
            break;
        //se la temperatura in ingresso è in fahrenheit calcolo il corrispondente in celsius
        case 2: fahrenheit = temp;
            celsius = (temp - 32) / 1.8;
            break;
    }

    //stampo le temperature calcolate a schermo
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


    //uso il ciclo for per salvare nei due array i voti degli esami e i loro pesi
    for (int i = 0; i < 3; i++) {
        printf("inserire voto esame %d:\n", i + 1);
        scanf("%d", &voti_esami[i]);
        printf("inserire peso esame %d:\n", i + 1);
        scanf("%d", &valore_esami[i]);

        //calcolo parzialmente gli elementi della formula della media
        prodotti = prodotti + (valore_esami[i] * voti_esami[i]);
        divisore = divisore + valore_esami[i];
    };

    //calcolo la media ponderata e la stampo a schermo
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

    float raggio;
    //definisco PI scrivendo const davanti poichè il suo valore non deve variare durante l'esecuzione del programma
    const float PI = 3.14159;

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



void ex_scambio_variabili() {
    int a = 15;
    int b = 20;

    //creao il valore temp per non perdere i valori di a e b durante lo scambio
    int temp;

    //salvo a in temp: temp = 15
    temp = a;
    //sovrascrivo a con il valore di b: a = 20
    a = b;
    //spvrascrivo b con il valore di a che è stato salvato in temp: b = 15
    b = temp;

    printf("a = %d  b = %d", a, b);

}