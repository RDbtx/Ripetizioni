#include "TUTORATO4.h"

#include <stdbool.h>

void ex1_tutorato4() {
    float val1, val2;

    printf("inserire il primo valore:\n");
    scanf("%f", &val1);
    printf("inserire il secondo valore:\n");
    scanf("%f", &val2);

    if (val1 > val2) {
        printf("%.2f %2.f\n", val1, val2);
    } else {
        printf("%.2f %2.f\n", val2, val1);
    }
}

void ex2_tutorato4() {
#define len 10
    float array[len];
    for (int i = 0; i < len; i++) {
        printf("inserire il %d valore:\n", i + 1);
        scanf("%f", &array[i]);
    };

    float max = array[0];
    float min = array[0];
    float sum = 0;
    float media;
    for (int i = 0; i < len; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }

        sum = sum + array[i];
    }
    media = sum / len;
    printf("\nVALORE MASSIMO INSERITO: %.2f", max);
    printf("\nVALORE MINIMO INSERITO: %.2f", min);
    printf("\nMEDIA DEI VALORI INSERITI: %.2f\n", media);
}


void ex3_tutorato4() {
#define len 50
    int lenght;
    int array[len];
    bool odd;

    do {
        printf("inserire la grandezza del vettore desiderata:\n");
        scanf("%d", &lenght);
    } while (lenght <= 0 || lenght > len);

    for (int i = 0; i < lenght; i++) {
        array[i] = i + 1;
        odd = true;
        if (array[i] % 2 == 0) {
            odd = !odd;
        }
        printf("\n%d %s\n", array[i], odd ? "dispari" : "pari");
    }
}

void ex4_tutorato4() {
    int val;
    printf("inserire valore:\n");
    scanf("%d", &val);
    bool primo = true;

    for (int i = 2; i < val; i++) {
        if (val % i == 0) {
            primo = false;
            break;
        }
    }
    printf("\n%d = %s", val, primo ? "PRIMO" : "NON PRIMO");
}
