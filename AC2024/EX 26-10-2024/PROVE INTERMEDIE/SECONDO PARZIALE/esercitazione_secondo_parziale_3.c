#include "esercitazione_secondo_parziale_3.h"

/*
Esercizio 2:
Scrivere una funzione estraiAnnoMinimo che,
dato un vettore v di tipo tpubblicazione, la sua
dimensione n, restituisca il minimo valore degli slot anno_pubblicazione.
*/

int estraiAnnoMinimo(tpubblicazione *pubblicazioni, int n) {
    int anno_minimo = pubblicazioni[0].anno_pubblicazione;
    for (int i = 1; i < n; i++) {
        if (pubblicazioni[i].anno_pubblicazione < anno_minimo) {
            anno_minimo = pubblicazioni[i].anno_pubblicazione;
        }
    }
    return anno_minimo;
}

/*
Esercizio 3:
Scrivere una funzione leggiPubblicazioniDaFile che riceve una stringa nome_file
ed un vettore pubb di variabili di tipo tpubblicazione, di dimensione massima N
(definito tramite #define). Il file contiene:

-Nella prima riga: il numero totale di pubblicazioni.
-Dalla seconda riga in poi: tre valori per ciascuna pubblicazione (anno_pubblicazione, numero_citazioni, titolo).

La funzione deve:
Restituire il valore letto nella prima riga.
Popolare il vettore pubb con i dati letti dal file.

ESEMPIO FILE:
3
1999 20087 "Analisi"
1998 16920 "Fondamenti"
2010 11042 "ML&AI"

*/

int leggiPubblicazioniDaFile(char *nome_file, tpubblicazione *pubb) {
    FILE *f = fopen(nome_file, "r");
    if (f == NULL) {
        printf("Errore apertura file\n");
        exit(1);
    }

    int N_pubb;
    if (fscanf(f, "%d", &N_pubb) != 1) {
        printf("Errore lettura numero di pubblicazioni\n");
        fclose(f);
        exit(1);
    }

    for (int i = 0; i < N_pubb; i++) {
        if (fscanf(f, "%d %d %s", &pubb[i].anno_pubblicazione, &pubb[i].numero_citazioni, pubb[i].nome_pubb) != 3) {
            printf("Errore lettura dati pubblicazione\n");
            fclose(f);
            exit(1);
        }
    }

    fclose(f);
    return N_pubb;
}

/*
Esercizio 4:
Scrivere una funzione che stampi:
L'anno con il numero di citazioni maggiore e il titolo della pubblicazione con più citazioni.
La funzione deve avere in ingresso la struttura tpubblicazioni e il numero di elementi.
*/


void StampaCitTitPerMaxPubb(tpubblicazione *pubb, int N_pubb) {
    int max_citXanno = 0;
    int anno_maxcit = 0;
    int max_citpubb = pubb[0].numero_citazioni;
    char nome_pubb[50];
    strncpy(nome_pubb, pubb[0].nome_pubb, sizeof(nome_pubb));

    for (int i = 0; i < N_pubb; i++) {
        if (pubb[i].anno_pubblicazione == anno_maxcit) {
            max_citXanno += pubb[i].numero_citazioni;
        } else if (pubb[i].numero_citazioni > max_citXanno) {
            max_citXanno = pubb[i].numero_citazioni;
            anno_maxcit = pubb[i].anno_pubblicazione;
        }

        if (pubb[i].numero_citazioni > max_citpubb) {
            max_citpubb = pubb[i].numero_citazioni;
            strncpy(nome_pubb, pubb[i].nome_pubb, sizeof(nome_pubb));
        }
    }
    printf("L'anno con piu' citazioni e' stato il [%d] con [%d] citazioni\n", anno_maxcit, max_citXanno);
    printf("[%s] e' la pubblicazione con piu' citazioni [%d]\n", nome_pubb, max_citpubb);
}

/*
Esercizio 5:
Scrivere una funzione trovaPubblicazione che:
Riceve un vettore di tipo tpubblicazione, la sua dimensione n, ed una stringa titolo da cercare.
Restituisce l’indice della pubblicazione con il titolo corrispondente, oppure -1 se non viene trovato
e stampa la pubblicazione trovata.
*/

int trovapubblicazione(tpubblicazione *pubb, int n, char *titolo) {
    for (int i = 0; i < n; i++) {
        if (strcmp(pubb[i].nome_pubb, titolo) == 0) {
            printf("Pubblicazione:\n");
            printf("Nome: %s\n", pubb[i].nome_pubb);
            printf("Anno Pubblicazione: %d\n", pubb[i].anno_pubblicazione);
            printf("Numero citazioni: %d\n", pubb[i].numero_citazioni);
            return i;
        }
    }
    printf("Errore! Pubblicazione non trovata");
    return -1;
}

/*
Esercizio 6:
scrivere una funzione sovrascriviFile che sovrascrive il file con la lista tpubblicazione modificata
*/

int sovrascriviFile(const char *nome_file, tpubblicazione *pubb, int N_pubb) {
    FILE *file = fopen(nome_file, "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    fprintf(file, "%d\n", N_pubb);
    for (int i = 0; i < N_pubb; i++) {
        fprintf(file, "%d %d %s\n",
                pubb[i].anno_pubblicazione,
                pubb[i].numero_citazioni,
                pubb[i].nome_pubb);
    }

    fclose(file);
    printf("Pubblicazione aggiunta con successo al file [%s]\n", nome_file);
    return 0;
}

/*
Esercizio 7:
Scrivere una funzione calcolaMediaCitazioni che riceve un vettore di tipo tpubblicazione
e la sua dimensione n. La funzione restituisce la media aritmetica del numero di citazioni
di tutte le pubblicazioni.
*/

float calcolaMediaCitazioni(tpubblicazione *pubb, int n) {
    int somma_citazioni = 0;

    for (int i = 0; i < n; i++) {
        somma_citazioni += pubb[i].numero_citazioni;
    }

    if (n == 0) {
        return 0;
    }

    return (float) somma_citazioni / n;
}

/*
Esercizio 8:
Scrivere una funzione ordinaPerCitazioni che ordina un vettore di tipo tpubblicazione
in ordine decrescente rispetto al numero di citazioni.
*/

void ordinaPerCitazioni(tpubblicazione *pubb, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pubb[j].numero_citazioni < pubb[j + 1].numero_citazioni) {
                tpubblicazione temp = pubb[j];
                pubb[j] = pubb[j + 1];
                pubb[j + 1] = temp;
            }
        }
    }
}

/*
Esercizio 9:
Crea una funzione che stampi la struttura tpubblicazioni.
attenzione alla casistica in cui la struttura fosse vuota.
*/

void stampaPubblicazioni(tpubblicazione *pubb, int n_pubb) {
    if (n_pubb == 0) {
        printf("Nessuna pubblicazione da stampare.\n");
        return;
    }

    printf("Elenco delle pubblicazioni:\n");
    for (int i = 0; i < n_pubb; i++) {
        printf("%d %d %s\n",
               pubb[i].anno_pubblicazione,
               pubb[i].numero_citazioni,
               pubb[i].nome_pubb);
    }
}

/*
Esercizio 10:
Crea una funzione creaPubblicazione che aggiunge all' array di strutture tpubblicazione
un nuovo elemento.
*/

int aggiungiPubblicazione(tpubblicazione *pubb, int n_pubb, const int maxlen) {
    if (n_pubb >= maxlen) {
        printf("Errore, memoria terminata! Impossibile inserire nuove pubblicazioni.");
        exit(2);
    }

    printf("Nome pubblicazione:\n");
    scanf("%s", pubb[n_pubb].nome_pubb);
    printf("Anno Pubblicazione:\n");
    scanf("%d", &pubb[n_pubb].anno_pubblicazione);
    printf("Citazioni pubblicazione:\n");
    scanf("%d", &pubb[n_pubb].numero_citazioni);

    n_pubb = n_pubb + 1;
    return n_pubb;
}

/*
Esercizio 11:
Crea una funzione modifica pubblicazione che prendendo in ingresso il vettore tpubblicazione
e l'indice della pubblicazione da modificare (ottenuto da trovapubblicazione()) permetta di modificarne
i contenuti.
*/

void modificaPubblicazione(tpubblicazione *pubb, int index) {
    if (index == -1) {
        printf("Errore, pubblicazione inesistente!\n");
        exit(2);
    }

    printf("Nuovo nome pubblicazione:\n");
    scanf("%s", pubb[index].nome_pubb);
    printf("Nuovo anno di pubblicazione:\n");
    scanf("%d", &pubb[index].anno_pubblicazione);
    printf("Nuovo numero di citazioni:\n");
    scanf("%d", &pubb[index].numero_citazioni);

    printf("Pubblicazione modificata con successo.\n");
}

/*
Esercizio 12:
Crea una funzione che allochi e deallochi dinamicamente la memoria per il vettore tpubblicazioni.
*/

tpubblicazione *allocaPubblicazioni(const int maxlen) {
    tpubblicazione *pubblicazioni = malloc(maxlen * sizeof(tpubblicazione));
    if (pubblicazioni == NULL) {
        printf("Errore nell'allocazione dinamica della memoria.\n");
        exit(1);
    }
    printf("Allocazione completata per %d pubblicazioni.\n", maxlen);
    return pubblicazioni;
}

void deallocaPubblicazioni(tpubblicazione *pubblicazioni) {
    if (pubblicazioni != NULL) {
        free(pubblicazioni);
        printf("Memoria deallocata correttamente.\n");
    } else {
        printf("Nessuna memoria da deallocare.\n");
    }
}

/*
Esercizio 12:
Implementare nel main le funzioni precedentemente scritte per la gestione del database di pubblicazioni.
L'allocazione della memoria per quanto riguarda il vettore tpubblicazione  dove verranno salvate le pubblicazioni dev'
essere dinamica.
*/
