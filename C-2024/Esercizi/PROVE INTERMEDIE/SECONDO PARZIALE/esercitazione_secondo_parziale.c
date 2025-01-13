#include <signal.h>
#include <stdio.h>

#include "esercitazione_secondo_parziale.h"
//UTILITY
void vector_printer(const int *vector, int vlenght) {
    for (int i = 0; i < vlenght; i++) {
        printf("%d ", vector[i]);
    }
}


//ESERCIZIO 1:
void string_encoder(const char *s_in, char *s_out) {
    int i = 0;
    while (s_in[i] != '\0') {
        // Encoding per i caratteri tra 'a' e 'z'
        if (s_in[i] >= 'a' && s_in[i] <= 'z') {
            if (s_in[i] == 'z') {
                s_out[i] = 'a'; // Wrap-around per 'z'
            } else {
                s_out[i] = s_in[i] + 1; // Converti alla lettera successiva
            }
        }
        // Encoding per i caratteri tra 'A' e 'Z'
        else if (s_in[i] >= 'A' && s_in[i] <= 'Z') {
            if (s_in[i] == 'Z') {
                s_out[i] = 'A';
            } else {
                s_out[i] = s_in[i] + 1;
            }
        }
        //per i caratteri non alfabetici
        else {
            s_out[i] = s_in[i];
        }

        i++;
    }
    s_out[i] = '\0';
}


//ESERCIZIO 2:
void vector_sum(const int *v1, const int *v2, const int len, int *v_out) {
    for (int i = 0; i < len; i++) {
        v_out[i] = v1[i] + v2[i];
    }
}


//ESERCIZIO 3:
int scalar_product(const int *v1, const int *v2, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum = sum + v1[i] * v2[i];
    }
    return sum;
}


//ESERCIZIO 4:
int vector_creator(int *vector, int len, int v_max, int v_min) {
    int i = 0;
    int input;
    do {
        printf("Inserisci l'elemento %d del vettore:", i + 1);
        scanf("%d", &input);
        if (input > v_min && input < v_max) {
            vector[i] = input;
            i = i + 1;
        }
    } while (input < v_max && input > v_min && i < len);

    return i;
}


//ESERCIZIO 5:
char most_frequent_vowel(const char *stringa_input) {
    int counter_vowels[5] = {0, 0, 0, 0, 0};
    int i = 0;
    while (*stringa_input != '\0') {
        switch (*stringa_input) {
            case 'a':
                counter_vowels[0] = counter_vowels[0] + 1;
                break;
            case 'e':
                counter_vowels[1] = counter_vowels[1] + 1;
                break;
            case 'i':
                counter_vowels[2] = counter_vowels[2] + 1;
                break;
            case 'o':
                counter_vowels[3] = counter_vowels[3] + 1;
                break;
            case 'u':
                counter_vowels[4] = counter_vowels[4] + 1;
                break;
        }
        stringa_input++;
    }

    int max = counter_vowels[0];
    int max_index = 0;
    for (int j = 0; j < 5; j++) {
        if (counter_vowels[j] > max) {
            max = counter_vowels[j];
            max_index = j;
        }
    }
    switch (max_index) {
        case 0:
            return 'A';
        case 1:
            return 'E';
        case 2:
            return 'I';
        case 3:
            return 'O';
        case 4:
            return 'U';
        default:
            return '\0';
    }
}


//ESERCIZIO 6:
int max_value_in_array(int *array, int len) {
    int max = array[0];
    for (int i = 0; i < len; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}


//ESERCIZIO 7:
int max_value_index_in_array(int *array, int len) {
    int max = array[0];
    int max_index = 0;
    for (int i = 0; i < len; i++) {
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
    }
    return max_index;
}


//ESERCIZIO 8:
int max_min_founder(const int *v1, const int *v2, int len) {
    int max = v1[0];
    int max_index = 0;
    int min = v2[0];
    int min_index = 0;
    for (int i = 0; i < len; i++) {
        if (v1[i] > max) {
            max = v1[i];
            max_index = i;
        }
        if (v2[i] < min) {
            min = v1[i];
            min_index = i;
        }
    }
    if (min_index == max_index) {
        return max_index;
    }

    return -1;
}

#define len 50

int project_main(void) {
    /*
    ESERCIZIO 1:
    Scrivere una funzione che, ricevendo in ingresso una stringa s_in di caratteri alfabetici,
    scriva in una seconda stringa s_out, sempre ricevuta come parametro, la stringa s_in ottenuta sostituendo
    a ogni lettera quella che la segue nell'ordinamento alfabetico, considerando l'alfabeto come circolare
    (quindi il carattere che segue 'z' è 'a', e quello che segue 'Z' è 'A').
    Durante la codifica, si ignorino tutti i caratteri non alfabetici.
    Esempio: se s_in è pari a "CODICESEGRETO", s_out è pari a "DPEJDFTFHSFUP".
     */


    char string[] = "11!!bhznBHZN!!11";
    char encoded_string[len];

    string_encoder(string, encoded_string);
    printf("\nESERCIZIO 1)\n");
    printf("STRINGA INPUT = %s\n", string);
    printf("STRINGA OUTPUT = %s\n", encoded_string);

    /*
    ESERCIZIO 2:
    Scrivere una funzione che, ricevendo in ingresso due vettori di interi v1 e v2,
    di pari dimensione n, memorizzi in un terzo vettore v3, sempre ricevuto come parametro,
    la somma degli elementi corrispondenti di v1 e v2.
    Esempio: se v1 = {1, 5, 11, 3, 2} e v2 = {4, 3, 10, 1, 12} ==> v3 = {5, 8, 21, 4, 14}.
    */
    int vettore1[] = {1, 2, 3, 4, 5};
    int vettore2[] = {9, 8, 7, 6, 5};
    int vettore3[len];
    int lenght = sizeof(vettore1) / sizeof(int);


    vector_sum(vettore1, vettore2, lenght, vettore3);
    printf("\nESERCIZIO 2)\n");
    printf("VETTORE INPUT 1 = ");
    vector_printer(vettore1, lenght);
    printf("\nVETTORE INPUT 2 = ");
    vector_printer(vettore2, lenght);
    printf("\nVETTORE OUTPUT = ");
    vector_printer(vettore3, lenght);

    /*
    ESERCIZIO 3:
    Scrivere una funzione che, ricevendo due vettori di reali v1 e v2,
    restituisca il prodotto scalare tra i due vettori.
    */

    printf("\n\nESERCIZIO 3)\n");
    printf("VETTORE INPUT 1 = ");
    vector_printer(vettore1, lenght);
    printf("\nVETTORE INPUT 2 = ");
    vector_printer(vettore2, lenght);
    printf("\nPRODOTTO SCALARE = %d\n", scalar_product(vettore1,vettore2,lenght));

    /*
    ESERCIZIO 4:
    Scrivere una funzione che, ricevendo in ingresso un vettore di massimo N elementi interi,
    e due interi max_v e min_v, inserisca nel vettore elementi, letti da tastiera, compresi tra min_v e max_v,
    fermando la lettura quando si inserisce un valore al di fuori di tale intervallo.
    La funzione restituisce il numero di elementi complessivamente inseriti.
     */

    printf("\nESERCIZIO 4)\n");
    int emptyvector[len];
    int vmax = 100;
    int vmin = 0;
    printf("VECTOR LENGHT = %d\n", vector_creator(emptyvector, len,vmax,vmin));

    /*
    ESERCIZIO 5:
    Scrivere una funzione che, ricevendo una stringa, restituisca la vocale più frequente all'interno della stringa.
    */

    char stringa[] ="Marcialis";
    printf("\nESERCIZIO 5)\n");
    printf("STRINGA INPUT = %s\n",stringa);
    printf("La vocale piu' presente e' la %c\n",most_frequent_vowel(string));

    /*
    ESERCIZIO 6:
    Scrivere una funzione che, ricevendo un vettore v di n interi,
    restituisca il valore massimo presente nel vettore.
    Esempio: se v = {1, 4, -1, 5, 1}, il valore da restituire è 5.
    */
    printf("\nESERCIZIO 6)");
    int vettore[] ={1, 4, -1, 5, 1};
    int lunghezza = sizeof(vettore) / sizeof(int);
    printf("\nVETTORE INPUT = ");
    vector_printer(vettore, lunghezza);
    printf("\nIL VALORE MASSIMO DEL VETTORE E' = %d\n",max_value_in_array(vettore, lunghezza));


    /*
    ESERCIZIO 7:
    Correggere la funzione precedente facendo restituire l'indice del massimo elemento presente nel vettore.
    Considerando l'esempio di prima, il valore da restituire è 3. Infatti v[3]=5.
    */
    printf("\nESERCIZIO 7)\n");
    printf("VETTORE INPUT = ");
    vector_printer(vettore, lunghezza);
    printf("\nL'INDICE DEL VALORE MASSIMO DEL VETTORE E' = %d\n",max_value_index_in_array(vettore,lunghezza));


    /*
    ESERCIZIO 8:
    Scrivere una funzione che, dati due vettori v1 e v2 di pari dimensione n, restituire, se esiste, l'indice del
    valore che risulta il massimo elemento di v1 ed il minimo elemento di v2.
    Restituisce -1 se l'indice non è stato trovato.
    Esempio: se v1 = {1, 4, -1, 5, 1} e v2 ={10, 41, 10, 5, 40}, il valore da restituire è 3
    in quanto v1[3]=v2[3]=5, massimo elemento di v1 e minimo di v2.
    */
    int array1[] ={1, 4, -1, 5, 1};
    int array2[] ={10, 41, 10, 5, 40};
    printf("\nESERCIZIO 8)\n");
    printf("VETTORE INPUT 1 = ");
    vector_printer(array1, lunghezza);
    printf("\nVETTORE INPUT 2 = ");
    vector_printer(array2, lunghezza);
    printf("\nINDICE MASSIMO E MINIMO VETTORI = %d\n", max_min_founder(vettore1,vettore2,lunghezza));




    return 0;


}
