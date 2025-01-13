#include "for_and_strings.h"


//CICLI FOR


/*
Esercizio 1:
Scrivere un programma C che che implementi il metodo delle sottrazioni successive per
scrivere quoziente e resto  della divisione di due numeri interi non negativi X e Y
*/
void ex1_for() {
    int numero, divisore;
    int quoziente = 0;
    int resto;

    printf("Inserisci un numero:\n");
    scanf("%d", &numero);
    printf("Inserisci il divisore:\n");
    scanf("%d", &divisore);


    // Metodo delle sottrazioni successive
    resto = numero;

    if (divisore != 0) {
        while (resto >= divisore) {
            resto = resto - divisore;
            quoziente = quoziente + 1;
        }

        // Stampa dei risultati
        printf("Risultato: %d\n", quoziente);
        printf("Resto: %d\n", resto);
    } else printf("Errore, stai dividendo un numero per 0\n");
}


/*
Esercizio 2:
Scrivere un programma C che inseriti due interi non negativi X e Y, rispettivamente
base ed esponente, ne calcoli la potenza senza usare la funzione pow
*/
void ex2_for() {
    int base, esponente;
    int risultato = 1;

    // Inserimento dei numeri da parte dell'utente
    printf("Inserisci la base:\n");
    scanf("%d", &base);
    printf("Inserisci l'esponente:\n");
    scanf("%d", &esponente);


    for (int i = 0; i < esponente; i++) {
        risultato = risultato * base;
    }

    // Stampa del risultato
    printf("%d^%d = %d\n", base, esponente, risultato);
}


// STRINGHE


/*
Esercizio 1:
Scrivere un programma C che data una stringa di caratteri minuscoli, la trasformi in una di soli caratteri maiuscoli
*/
void ex1_strings() {
#define STRINGLEN 30
    char str[STRINGLEN];

    //inserirsco la stringa
    printf("Inserisci una stringa di caratteri minuscoli:\n");
    scanf("%s", str);

    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] - 32;
    }

    printf("la stringa maiuscola e': %s", str);
}


/*
Esercizio 2:
Scrivere un programma C che data una stringa che esprima un numero da "zero" a "cinque", stampi
a schermo il valore dell' intero corrispondente
*/
void ex2_strings() {
#define STRINGLEN 10
    char numero[STRINGLEN];

    printf("inserisci un numero da zero a cinque:\n");
    scanf("%s", numero);


    if (strcmp(numero, "uno") == 0) {
        printf("1");
    } else if (strcmp(numero, "due") == 0) {
        printf("2");
    } else if (strcmp(numero, "tre") == 0) {
        printf("3");
    } else if (strcmp(numero, "quattro") == 0) {
        printf("4");
    } else if (strcmp(numero, "cinque") == 0) {
        printf("5");
    } else printf("il numero inserito non e' valido");
}


/*
Esercizio 3:
Scrivere un programma C che legga un insieme di stringhe di "zero" e "uno" e scriva in un vettore
di interi il numero binario corrispondente. La lettura si interrompe all' utilizzo della parola fine
*/
void ex3_strings() {
#define LEN 50

    int bin_vector[LEN];
    int temp;
    char string[LEN];
    int counter = 0;

    //uso il ciclo do wile per caricare i numeri
    do {
        printf("Inserisci un numero da 'zero' a 'uno' (o 'fine' per terminare):\n");
        scanf("%s", string);

        if (strcmp(string, "uno") == 0) {
            bin_vector[counter] = 1;
            counter++;
        } else if (strcmp(string, "zero") == 0) {
            bin_vector[counter] = 0;
            counter++;
        }
        // Chiudo il ciclo quando si supera la memoria allocata o appare la parola fine
    } while (strcmp(string, "fine") != 0 && counter < LEN);

    //stampo a schermo il vettore
    printf("Il numero inserito e0: ");
    for (temp = 0; temp < counter; temp++) {
        printf("%d", bin_vector[temp]);
    }
}


/*
Esercizio 4:
Scrivere un programma C che data una stringa conti il numero di vocali e lo stampi a video per ciascuna vocale
*/
void ex4_strings() {
#define LEN 50
    char string[LEN];
    int count_a = 0;
    int count_e = 0;
    int count_i = 0;
    int count_o = 0;
    int count_u = 0;
    int i;
    printf("inserire una stringa:\n");
    scanf("%s", string);

    while (string[i] != '\0') {
        if (string[i] == 'a' || string[i] == 'A') {
            count_a++;
        } else if (string[i] == 'e' || string[i] == 'E') {
            count_e++;
        } else if (string[i] == 'i' || string[i] == 'I') {
            count_i++;
        } else if (string[i] == 'o' || string[i] == 'O') {
            count_o++;
        } else if (string[i] == 'u' || string[i] == 'U') {
            count_u++;
        }
        i = i + 1;
    }

    printf("a presenti nella stringa: %d\n", count_a);
    printf("e presenti nella stringa: %d\n", count_e);
    printf("i presenti nella stringa: %d\n", count_i);
    printf("o presenti nella stringa: %d\n", count_o);
    printf("u presenti nella stringa: %d\n", count_u);
}


/*
Esercizio 5:
Scrivere un programma C che date due stringhe a e b, verifichi se a è uguale a b
*/
void ex5_strings() {
#define lenght 50

    // dichiaro le stringhe
    char stringa1[lenght];
    char stringa2[lenght];

    bool uguale = true;

    // inserisco le stringhe e le salvo in memoria
    printf("Inserisci stringa 1:\n");
    scanf("%s", stringa1);
    printf("Inserisz stringa 2:\n");
    scanf("%s", stringa2);


    for (int i = 0; stringa1[i] != '\0' || stringa2[i] != '\0'; i++) {
        if (stringa1[i] != stringa2[i]) {
            uguale = false;
        }
    }

    if (uguale) {
        printf("le stringhe sono uguali");
    } else printf("le stringhe sono diverse");
}


/*
Esercizio 6:
Scrivere un programma C che data una stringa che rappresenta una parola, ci dica se la stringa
è palindroma
*/
void ex6_strings() {
#define LEN 50
    char stringa[LEN];
    //uso questa variabile booleana per vedere se la stringa è palindroma o meno
    bool palindrome = true;

    printf("Inserisci stringa:\n");
    scanf("%s", stringa);

    //calcolo la lunghezza della stringa inserita
    int len = strlen(stringa);

    //controllo attraverso il ciclo for che la stringa sia palindroma e possa essere letta
    // sia da sinistra verso destra che da destra verso sinistra
    for (int i = 0; stringa[i] != '\0'; i++) {
        //stringa[len-1] è impostato a len-1 poiche len in posizione vettoriale corrisponderebbe a '\0'
        if (stringa[i] != stringa[len - 1]) {
            //se leggendo da destra a sinistra e viceversa trovo due lettere che non sono uguali ma
            //che dovrebbero occupare la stessa posizione specchiando la parola allora la stringa non è
            //palindroma, setto quindi la variabile booleana palindrome a false
            palindrome = false;
            break;
        }
        //itero len sottraendo 1 per leggere man mano la stringa da destra a sinistra
        len = len - 1;
    }

    //stampo a schermo il risultato del controllo
    if (palindrome) {
        printf("la stringa e' palindroma\n");
    } else printf("la stringa non e' palindroma\n");
}


/*
Esercizio 7:
Scrivere un programma C che data una stringa s e una stringa b, verifichi se la stringa s è sottostringa di b
*/
void ex7_strings() {
#define LEN 50
    char stringa[LEN];
    char substring[LEN];

    //creo la variabile booleana is_substring per vedere se substring è sottostringa di stringa
    bool is_substring = false;

    //carico stringa e sottostringa in memoria
    printf("Inserisci stringa:\n");
    scanf("%s", stringa);
    printf("Inserisci la sottostringa che vuoi trovare:\n");
    scanf("%s", substring);


    //calcolo le lunghezze di stringa e sottostringa perchè mi servono per il confronto
    int lenstring = strlen(stringa);
    int lensubstring = strlen(substring);

    //se la lunghezza dekka sottostringa è maggiore di quella della stringa automaticamente
    //la sottostringa inserita non può essere sottostringa
    if (lensubstring > lenstring) {
        is_substring = false;
    } else {
        // controllo che la sottostringa sia presente nella stringa
        //il ciclo esterno itera solo fino a lenstring - lensubstring per
        //evitare di cercare la sottostringa oltre il punto in cui potrebbe effettivamente rientrare.
        for (int i = 0; i <= lenstring - lensubstring; i++) {
            int j;
            //controllo quindi che la sottostringa esista nella stringa, se ciò non è verificato interrompo il ciclo
            for (j = 0; j < lensubstring; j++) {
                if (stringa[i + j] != substring[j]) {
                    break;
                }
            }
            //se il ciclo non è stato interrotto allora la sottostringa è presente nella stringa quindi
            //imposto is_substring a TRUE
            if (j == lensubstring) {
                is_substring = true;
                break;
            }
        }
    }

    //stampo a schermo il risultato
    if (is_substring) {
        printf("%s e' sottostringa di %s\n", substring, stringa);
    } else printf("%s e' sottostringa di %s\n", substring, stringa);
}
