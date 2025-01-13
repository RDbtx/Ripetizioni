#include "functions.h"

/*
ESERCIZIO 1:
Scrivi una funzione `int somma(int a, int b)` che restituisca la somma di due numeri interi.
*/
int sum(const int a, const int b) {
    return a + b;
}

/*
ESERCIZIO 2:
Scrivi una funzione `int quadrato(int n)` che restituisca il quadrato di un numero intero. Usa
questa funzione per calcolare il quadrato di un numero dato dall'utente.
*/
int quadrato(const int n) {
    return n * n;
}

/*
ESERCIZIO 3:
Scrivi una funzione `int isPari(int n)` che restituisca 1 se un numero è pari e 0 altrimenti.
*/
int isPari(const int n) {
    if (n % 2 == 0) {
        return 1;
    }
    return 0;
}

/*
ESERCIZIO 4:
Scrivi una funzione `int isDivisibile(int a, int b)` che restituisca 1 se il primo numero è
divisibile per il secondo e 0 altrimenti.
*/
int isDivisible(const int a, const int b) {
    if (a % b == 0) {
        return 1;
    }
    return 0;
}

/*
ESERCIZIO 5:
Scrivi una funzione `int minimo(int a, int b)` che restituisca il minore tra due numeri.
*/
int minimo(const int a, const int b) {
    if (a < b) {
        return a;
    }
    return b;
}

/*
ESERCIZIO 6:
Scrivi una funzione int fattoriale(int n) che calcoli il fattoriale di un numero intero positivo.
Chiamala dal main per stampare il risultato.
*/
int fattoriale(int n) {
    int factorial = 1;
    while (n > 1) {
        factorial = factorial * n;
        n = n - 1;
    }
    return factorial;
}

/*
ESERCIZIO 7:
Scrivi una funzione void invertiStringa(char str[], int len) che inverta una stringa. Usala per invertire
una stringa data dall'utente.
*/
void invertiStringa(char *str, const int len) {
    int j = 0;
    char temp[len];
    //salvo la stringa inversa in una variabile temporanea
    for (int i = len - 1; i >= 0; i--) {
        temp[j] = str[i];
        j = j + 1;
    }
    temp[j] = '\0';
    j = 0;
    //salvo la stringa invertita nella stringa originale
    while (temp[j] != '\0') {
        str[j] = temp[j];
        j = j + 1;
    }
}

/*
ESERCIZIO 8:
Scrivi una funzione int massimo(int arr[], int size) che trovi e restituisca il numero massimo in
un array di numeri interi.
*/
int massimo(const int *arr, const int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/*
ESERCIZIO 9:
Scrivi due funzioni una chiamata FizzBuzz() che prende in ingresso 3 valori e stampa a
schermo FIZZ se il primo valore è divisibile per il secondo, BUZZ se è divisibile per il terzo,
FIZZBUZZ se è divisibile per entrambi i valori.
Impelementa anche la funzione IsDivisible() che prende in ingresso due valori e restituisce
True se il primo valore è divisibile per il secondo e False in caso contrario.
La funzione IsDivisible() dovrà a sua volta essere chiamata all interno di FizzBuzz(). Testare il
Tutto su un array di interi, pre costruito, di 15 elementi.
*/

bool FBisDivisible(const int val, const int div) {
    if (val % div == 0) {
        return true;
    }
    return false;
}

void FizzBuzz(const int val, const int div1, const int div2) {
    if (FBisDivisible(val, div1) && FBisDivisible(val, div2)) {
        printf("%d = FizzBuzz\n", val);
    } else if (FBisDivisible(val, div1)) {
        printf("%d = Fizz\n", val);
    } else if (FBisDivisible(val, div2)) {
        printf("%d = Buzz\n", val);
    } else {
        printf("%d = Not Fizz nor Buzz\n", val);
    }
}
