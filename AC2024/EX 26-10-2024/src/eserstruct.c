#include <stdio.h>
#include <string.h>

// Definizione della struct Persona
struct Persona {
    char nome[50];
    int età;
    float altezza;
};

// Funzione per ordinare l'array di struct in base all'età usando Selection Sort
void selectionSort(struct Persona arr[], int n) {
    int i, j, minIndex;
    struct Persona temp;

    // Algoritmo Selection Sort
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].età < arr[minIndex].età) {
                minIndex = j;
            }
        }
        // Scambia l'elemento corrente con l'elemento trovato più piccolo
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Funzione per stampare l'array di struct
void stampaPersone(struct Persona arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Età: %d, Altezza: %.2f\n", arr[i].nome, arr[i].età, arr[i].altezza);
    }
}

int main() {
    int n;

    // Chiedi all'utente quanti dati inserire
    printf("Quante persone vuoi inserire? ");
    scanf("%d", &n);

    // Creazione dell'array di struct con il numero di persone richiesto
    struct Persona persone[n];

    // Inserimento dei dati
    for (int i = 0; i < n; i++) {
        printf("\nInserisci i dati della persona %d:\n", i + 1);

        // Inserisci il nome
        printf("Nome: ");
        scanf(" %49[^\n]", persone[i].nome);  // %49[^\n] per leggere stringhe con spazi

        // Inserisci l'età
        printf("Età: ");
        scanf("%d", &persone[i].età);

        // Inserisci l'altezza
        printf("Altezza: ");
        scanf("%f", &persone[i].altezza);
    }

    // Mostra i dati prima dell'ordinamento
    printf("\nDati prima dell'ordinamento:\n");
    stampaPersone(persone, n);

    // Ordinamento dell'array in base all'età
    selectionSort(persone, n);

    // Mostra i dati dopo l'ordinamento
    printf("\nDati dopo l'ordinamento (per età):\n");
    stampaPersone(persone, n);

    return 0;
}
