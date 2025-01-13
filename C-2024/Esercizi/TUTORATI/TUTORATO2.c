#include "TUTORATO2.h"
/*
Esercizio 1:
Scrivere un programma che dato un valore intero, ne faccia la
conversione in carattere. Il valore intero in questione deve essere
inserito dall’utente e deve essere compreso tra 0 e 255.
Il programma dovrà quindi stampare a video una stringa del tipo:

Il valore intero inserito (X) corrisponde al seguente
carattere ascii: Y

*/

void ex1_tutorato2() {
    int value;
    do {
        printf("inserire un valore compreso tra 0 e 255:\n");
        scanf("%d", &value);
    } while (value < 0 || value > 255);

    //il risultato "strano" non è un errore in quanto non tutti
    //i valori tra 0 e 255 corrispondono a un char
    printf("il carattere corrispondente è %c", value);
}

/*
Esercizio 2.
Scrivere un programma che, date due stringhe inserite dall’utente, dica se queste sono uguali.
A tal proposito si utilizzi la rispettiva funzione presente all’interno della libreria string.h.
Si stampi a video il valore da quest’ultima e lo si utilizzi per determinare o meno
l’uguaglianza delle stringhe immesse.
*/
void ex2_tutorato2() {
#define lenght 50
    char string1[50], string2[50];

    printf("inserire la prima stringa:\n");
    scanf("%s", string1);
    printf("inserire la seconda stringa:\n");
    scanf("%s", string2);

    int are_equal = strcmp(string1, string2);

    if (are_equal == 0) {
        printf("le stringhe sono identiche");
    } else
        printf("le stringhe sono diverse");

}

/*
Esercizio 3:
Scrivere un programma che data una stringa immessa dall’utente,
ne stampi l’effettiva lunghezza. Nota: Si badi bene a non confondere lunghezza
della stringa (richiesta dall’esercizio) con lunghezza del vettore contente
la stringa.
*/

void ex3_tutorato2() {
#define lenght 50
    char string1[50];

    printf("inserire la stringa:\n");
    scanf("%s", string1);
    printf("la lunghezza della stringa e %d", (strlen(string1)));
}

/*
Esercizio 4:
Scrivere un programma che dato un valore di tipo double immesso da tastiera, stampi
a video lo stesso numero rispettivamente in formato float, int e char.
Utilizzare per lo scopo gli operatori di casting visti a lezione.
L’output deve essere del tipo:
Il valore di X in formato float è: Y
Il valore di X in formato int è: Y
Il valore di X in formato char è: Y
*/


void ex4_tutorato2() {
    double value;

    printf("inserire il valore:\n");
    scanf("%lf", &value);

    printf("il valore di %lf in formato float e': %f\n", value, value);
    printf("il valore di %lf in formato float e': %d\n", value, value);
    printf("il valore di %lf in formato float e': %c\n", value, value);
}

/*
Esercizio 5:
Scrivere un programma che chieda all’utente di inserire, rsipettivamente un carattere e un intero.
Si converta successivamente il carattere in intero (utilizzando gli operatori di casting),
gli si sottragga il numero precedetemente inserito e si converta nuovamente il numero ottenuto in carattere.
Si stampi quindi il carattere ottenuto al fine della procedura.
*/
void ex5_tutorato2() {
    char carattere;
    int value;

    printf("inserire un carattere:\n");
    scanf("%c", &carattere);
    printf("inserire un intero:\n");
    scanf("%d", &value);

    carattere = (int){carattere} - value;
    printf("il valore di carattere e': %c", carattere);
}

/*
Esercizio 6:
Scrivere un programma che chieda all’utente di inserire tre numeri di tipo float
e li salvi all’interno di un vettore da 3 elementi. I numeri così inseriti rappresentano
i coefficienti di un’equazione di secondo grado (ovvero del tipo a · x2 + b · x + c).
Si utilizzino tali numeri per il calcolo del discriminante di tale equazione
(definito come ∆ = b2 − 4a · c) e lo si stampi a video.
*/

void ex6_tutorato2() {
#define lenght 3
    char string[lenght] = {'a', 'b', 'c'};
    float values[lenght];

    for (int i = 0; i < 3; i++) {
        printf("inserire il coefficiente %c:\n", string[i], i + 1);
        scanf("%f", &values[i]);
    }

    float discriminante = pow(values[1], 2) - 4 * (values[0] * values[2]);
    printf("il valore del discriminante e': %f", discriminante);
}

/*
Esercizio 7:
Scrivere un programma che effettui la conversione binario - decimale di un numero a
4 bit in rappresentazione senza segno. Per la realizzazione del programma
si utilizzino due vettori: uno per il salvataggio del numero in formato binario
(ogni cella del vettore conterrà un valore intero pari ad 1 o 0) e uno per il
salvataggio dei pesi. I valori del primo vettore sono inseriti in input
dall’utente, mentre si lascia libertà sul secondo. In ultima istanza il programma
deve stampare a video il risultato della conversione.
 */

void ex7_tutorato2() {
#define length 4
    int bitstring[length + 1];
    int bit_weight[] = {3, 2, 1, 0};
    for (int i = 0; i < length; i++) {
        printf("inserire il bit %d:", i + 1);
        scanf(" %d", &bitstring[i]);
    }

    int decimale = 0;
    for (int i = 0; i < length; i++) {
        if(bitstring[i] == 1) {
          decimale = decimale + pow(2,bit_weight[i]);
    }}

    printf("\nconversione in decimale di '%d%d%d%d': %d",bitstring[0], bitstring[1], bitstring[2], bitstring[3], decimale);
}
/*
Esercizio 8:
Si ripeta l’esercizio precedente, ma si utilizzi una rappresentazione in complemento a 2 per il numero binari
*/


void ex8_tutorato2() {
#define length 4
    int bitstring[length + 1];
    int bit_weight[] = {3, 2, 1, 0};
    for (int i = 0; i < length; i++) {
        printf("inserire il bit %d: ", i + 1);
        scanf(" %d", &bitstring[i]);
    }

    //sottraggo 1

    int decimale = 0;
    if (bitstring[0] == 1) {
        // Se il numero è negativo, calcola il complemento a 2
        for (int i = 0; i < length; i++) {
            if(bitstring[i] == 0) {
                decimale = decimale + pow(2,bit_weight[i]);
            }}
        decimale = -(decimale + 1);
    } else {
        // Se è positivo, calcola normalmente
        for (int i = 0; i < length; i++) {
            if(bitstring[i] == 1) {
                decimale = decimale + pow(2,bit_weight[i]);
            }}
    }


    printf("\nconversione in decimale di '%d%d%d%d': %d",bitstring[0], bitstring[1], bitstring[2], bitstring[3], decimale);
}


/*
Esercizio 9:
Si scriva un programma che date le lunghezze dei cateti di un
triangolo rettangolo ne calcoli:
• Il valore dell’ipotenusa
• Il perimetro
• L’area
I valori dei cateti devono essere inseriti da terminale e i risultati di tutte le
operazioni devono essere stampati a vide
*/

void ex9_tutorato2() {
    float base, altezza, ipotenusa, perimetro, area;

    printf("inserire la base:\n");
    scanf("%f", &base);
    printf("inserire l'altezza:\n");
    scanf("%f", &altezza);

    area = (base * altezza)/2;
    ipotenusa = sqrt((pow(base, 2) + pow(altezza, 2)));
    perimetro = base + altezza + ipotenusa;

    printf("\nl' ipotenusa del triangolo e': %.2f", ipotenusa);
    printf("\nil' perimetro del triangolo e': %.2f", perimetro);
    printf("\nl'area del triangolo e': %.2f", area);

}
