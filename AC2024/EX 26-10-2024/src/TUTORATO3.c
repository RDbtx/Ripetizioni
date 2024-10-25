#include "TUTORATO3.h"

/*
Esercizio 1
Scrivere un programma che chieda all’utente di inserire un numero intero.
Il programma deve determinare se il numero è divisibile per 5 e,
in caso affermativo, stampare un messaggio appropriato.
*/

void ex1_tutorato3() {
    int value;
    printf("inserire un numero intero:\n");
    scanf("%d", &value);

    if (value % 5 == 0) {
        printf("\nil numero e' divisibile per 5");
    } else printf("\nil numero non e' divisibile per 5");
}

/*
Esercizio 2:
Scrivere un programma che chieda all’utente di inserire un numero intero.
Il programma deve determinare sia se il numero è pari o dispari,
sia se è positivo o negativo e quindi stampare i risultati.
*/

void ex2_tutorato3() {
    int value;
    printf("inserire un numero intero:\n");
    scanf("%d", &value);

    printf("il numero e' %s ed e' %s",
           (value % 2 == 0) ? "pari" : "dispari",
           (value > 0) ? "positivo" : "negativo");
}

/*
Esercizio 3:
Scrivere un programma che chieda all’utente di inserire una serie
di numeri interi positivi. Il programma dovrebbe calcolare e stampare la somma
dei numeri inseriti finché l’utente decide di smettere di inserire numeri.
*/

void ex3_tutorato3() {
#define maxlen 50
    int array[maxlen];
    int i = 0, sum = 0, temp;

    do {
        printf("inserire il -%d numero intero positivo:\n", i + 1);
        temp = scanf("%d", &array[i]);

        if (temp == 1 && array[i] > 0) {
            // Check for valid input and positivity
            sum = sum + array[i];
            i = i + 1;
        } else {
            printf("Input non valido. Inserisci un numero intero positivo.\n");
            // Clear invalid input from buffer
            while (getchar() != '\n');
        }
    } while (temp == 1 && i < maxlen); // Stop on invalid input or when array is full

    printf("\nla somma totale e': %d\n", sum);
}

/*
Esercizio 4:
Ripetere lo stesso esercizio precedente, ma col calcolo della media
invece che della somma.
*/

void ex4_tutorato3() {
#define maxlen 50
    int array[maxlen];
    int i = 0, sum = 0, temp;

    do {
        printf("inserire il -%d numero intero positivo:\n", i + 1);
        temp = scanf("%d", &array[i]);

        if (temp == 1 && array[i] > 0) {
            // Check for valid input and positivity
            sum = sum + array[i];
            i = i + 1;
        } else {
            printf("Input non valido. Inserisci un numero intero positivo.\n");
            // Clear invalid input from buffer
            while (getchar() != '\n');
        }
    } while (temp == 1 && i < maxlen); // Stop on invalid input or when array is full
    float media = sum / i;
    printf("\nla media totale e': %.2f\n", media);
}

/*
Esercizio 5:
Ripetere lo stesso esercizio, ma visualizzando dopo ogni inserimento
l’attuale valore massimo e minimo (in riferimento all’intera serienumerica).
Si accettano anche interi negativi.
*/

void ex5_tutorato5() {
#define maxlen 50
    int array[maxlen];
    int i = 0, sum = 0, temp;
    int max, min; // Variables for tracking maximum and minimum values

    do {
        printf("inserire il -%d numero intero positivo:\n", i + 1);
        temp = scanf("%d", &array[i]);

        if (temp == 1 && array[i] > 0) {
            // Valid input and positive integer check
            if (i == 0) {
                // Set initial max and min from the first valid input
                max = min = array[i];
            } else {
                // Update max and min if needed
                if (array[i] > max) max = array[i];
                if (array[i] < min) min = array[i];
            }
            sum += array[i];
            i++;
        } else {
            printf("Input non valido. Inserisci un numero intero positivo.\n");
            // Clear invalid input from buffer
            while (getchar() != '\n');
        }
    } while (temp == 1 && i < maxlen); // Stop on invalid input or when array is full

    printf("\nLa somma totale e': %d\n", sum);
    if (i > 0) {
        // Only print max and min if there were valid inputs
        printf("Il numero massimo inserito e': %d\n", max);
        printf("Il numero minimo inserito e': %d\n", min);
    }
}

/*
Esercizio 6:
Scrivere un programma che calcoli il numero di cifre di un numero
intero inserito dall’utente, senza convertire il numero in una stringa
*/

void ex6_tutorato3() {
    int number;
    printf("inserire un numero intero:\n");
    scanf("%d", &number);
    float temp = number;
    int i = 0;
    while (temp >= 1) {
        temp = temp / 10;
        i = i + 1;
    }
    printf("il numero -%d ha %d cifre\n", number, i);
}


/*
Esercizio 7:
Scrivere un programma che chieda all’utente di inserire una stringa e ne calcoli la lunghezza.
Si confronti il risultato con quello ottenuto mediante
l’utilizzo dell’opportuna funzione presente in string.h.
*/

void ex7_tutorato3() {
#define maxlen 50
    char string[maxlen];

    printf("inserire una stringa:\n");
    scanf("%s", string);

    int counter = 0;
    while (string[counter] != '\0') {
        counter = counter + 1;
    }
    printf("la stringa e' composta da '%d' caratteri", counter);
}

/*
Esercizio 8:
Scrivere un programma che calcoli il fattoriale di un numero
intero positivo N inserito dall’utente. Si verifichi che il numero inserito sia in
ogni caso positivo.
*/

void ex8_tutorato3() {
    int number, factorial;
    do {
        printf("inserire un numero intero:\n");
        scanf("%d", &number);
    } while (number < 0);

    while (number > 0) {
        factorial = factorial * number;
        number = number - 1;
    }
    printf("\nil fattoriale del numero e': %d ", factorial);
}

/*
Esercizio 9:
Scrivere un programma che dato un numero intero positivo, ne faccia la conversione in binario.
In tal senso, la rappresentazione binaria utilizzata è quella senza segno e il numero è rappresentato mediante 10 bit.
Si richiede, in aggiunta, di controllare se il numero inserito può essere rappresentato mediante 10 bit.
*/

void ex9_tutorato3() {
#define maxlen 10
    int array[maxlen];
    int value;
    printf("inserire un numero intero:\n");
    scanf("%d", &value);

    if (value < 1023) {
        for (int i = 9; i >= 0; i--) {
            array[i] = value % 2; // se value è divisibile per 2 -> 1 altrimenti -> 0
            value = value / 2;
        }
        printf("La rappresentazione binaria a 10 bit e': ");
        for (int i = 0; i < 10; i++) {
            printf("%d", array[i]);
        }
    } else printf("Il numero inserito è troppo grande per questa rappresentazione");
}

/*
Esercizio 10:
Scrivere un programma che conti il numero di indirizzi di posta
elettronica presenti in una stringa. Il programma chiede all’utente di inserire
gli indirizzi di posta elettronica separati da uno o più trattini. Il programma
dunque deve:
• Leggere la stringa
• Stampare la stringa
• Scrivere il numero di indirizzi di email presenti nella stringa
Guardare la seguente figura:
*/

void ex10_tutorato3() {
    char string[] = "riccardo@gmail.com-alessio@gmail.com-mattia@gmail.com";

    int counter = 0;
    for (int i = 0; i < strlen(string); i = i + 1) {
        if ('@' == string[i]) {
            counter = counter + 1;
        }
    }
    printf("in questa stringa sono presenti -%d indirizzi email", counter);
}

/*
Esercizio 11:
Scrivere un programma che implementi le funzionalità base di
una calcolatrice. Il programma in questione deve chiedere all’utente di inserire
due numeri e l’operazione che vuole eseguire su di essi (tra le seguenti +, -, * e/).
Stampare a video il risultato dell’operazione.
Nota: fare particolare attenzione nell’implementazione della division
*/

void ex11_tutorato3() {
    float val1, val2, divisione, moltiplicazione, somma, sottrazione;
    char operation;

    printf("inserire il 1o numero: ");
    scanf(" %f", &val1);

    printf("inserire il 2o numero: ");
    scanf(" %f", &val2);

    do {
        printf("\nche operazione vuoi eseguire tra: '-' '+' '*' '/' ? \n");
        scanf(" %c", &operation);
    } while (operation != '-' && operation != '+' && operation != '*' && operation != '/');

    switch (operation) {
        case '+':
            somma = val1 + val2;
            printf("\nrisultato: %.3f", somma);
            break;
        case '-': sottrazione = val1 - val2;
            printf("\nrisultato: %.3f", sottrazione);
            break;
        case '*': moltiplicazione = val1 * val2;
            printf("\nrisultato: %.3f", moltiplicazione);
            break;
        case '/': divisione = val1 / val2;
            printf("\nrisultato: %.3f", divisione);
            break;
    }
}

/*
Esercizio 12:
Scrivere un programma che implementi i seguenti passi:
1. Chiede all’utente di inserire due numeri interi.
2. Stampa se il primo intero è maggiore, minore, oppure uguale al secondo intero.
3. Chiede all’utente se vuole continuare
4. Legge la risposta dell’utente
5. Se l’utente vuole continuare vengono ripetuti i passi 1-4, altrimenti il
programma esce e scrive un messaggio di saluto.
*/

#include <stdio.h>

void ex12_tutorato3() {
    int program_status = 1;
    int status;

    do {
        int number1, number2;

        printf("Inserire il primo numero intero:");
        scanf("%d", &number1);
        printf("Inserire il secondo numero intero:");
        scanf("%d", &number2);

        // Determinazione del maggiore e del minore
        int maggiore = (number1 > number2) ? number1 : number2;
        int minore = (number1 < number2) ? number1 : number2;

        printf("\nMAGGIORE: '%d'\nMINORE: '%d'\n", maggiore, minore);

        do {
            printf("Vuoi continuare ?\nYES = 1\nNO = 0\n");
            scanf("%d", &status);
        } while (status != 1 && status != 0); // Continua a chiedere finché non si riceve una risposta valida

        if (status == 0) {
            program_status = 0; // Imposta lo stato per terminare il programma
            printf("Programma terminato\n");
        }

    } while (program_status == 1); // Continuare finché program_status è 1
}
