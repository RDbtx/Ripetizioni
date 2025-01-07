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
