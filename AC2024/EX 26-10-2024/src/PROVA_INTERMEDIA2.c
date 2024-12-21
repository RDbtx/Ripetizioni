#include "PROVA_INTERMEDIA2.h"

/*
Lvl 0 Ex2:
Scrivere una funzione C estraiProssimo che, ricevendo in ingresso un vettore v di
tipo tpubblicazione, la sua dimensione n, restituisca il massimo valore degli slot
anno_pubblicazione.
*/
int estrai_prossimo(tpubblicazione *data, int len) {
    int i = 0;
    int max = data[i].anno_pubblicazione;
    for (i = 0; i < len; i++) {
        if (data[i].anno_pubblicazione > max) {
            max = data[i].anno_pubblicazione;
        }
    }
    return max;
}

/*
Lvl 0 Ex3:
Scrivere una funzione C leggiPubblicazioni che riceve una stringa nome_file,
ed un vettore pubb di variabili di tipo tpubblicazione, di dimensione massima N
(definito tramite #define). Il file, una volta aperto, contiene nella prima riga il
numero di righe da leggere successivamente. A partire dalla seconda riga, ci sono
due valori interi: il primo è l’anno di pubblicazione, il secondo il numero di citazioni
ottenute dalla pubblicazione stessa. La funzione deve restituire il valore letto nella
prima riga e scrivere nel vettore pubb le coppie di valori ad ogni riga memorizzate
rispettivamente negli slot anno_pubblicazione e numero_citazioni. Notare che
la seconda colonna reca valori ordinati in ordine decrescente.
Esempio di file:
3
1999 20087
1998 16920
2010 11042
*/
int leggiPubblicazioni(const char *nome_file, tpubblicazione *pubb) {
    FILE *fp = fopen(nome_file, "r");
    if (fp == NULL) {
        printf("Errore apertura file\n");
        exit(1);
    }
    int numero_righe;
    if (fscanf(fp, "%d", &numero_righe) != 1) {
        printf("Errore lettura numero di righe\n");
        fclose(fp);
        exit(1);
    }

    for (int index = 0; index < numero_righe; index++) {
        fscanf(fp, "%d %d", &pubb[index].anno_pubblicazione, &pubb[index].numero_citazioni);
    }
    fclose(fp);
    return numero_righe;
}


/*
Lvl 0 Ex4:
Scrivere la funzione main() di un programma C che, a partire dal file
“ricercatore.txt”, contenente i dati formattati come nell’esercizio 0.3, stampi a
video il numero di citazioni di ciascuna delle pubblicazioni pubblicate nell’anno più
prossimo a quello in corso, oltre all’anno stesso. Si utilizzino il tipo dell’esercizio 0.1 e
le funzioni implementate negli esercizi 0.2 e 0.3.
Esempio: nel file dell’esercizio 0.3, l’anno più prossimo è il 2010. Il programma dovrà
quindi stampare il valore 11042.
Nota 1: se non si è svolto uno dei due esercizi 0.2 e/o 0.3, si possono considerare
quelle funzioni già implementate.
Nota 2: se lo si ritiene, si è liberi di modularizzare la struttura della main. Questa scelta,
comporta un punteggio massimo pari a 10 punti. Non è richiesto implementare ogni
modulo aggiuntivo ma solo descriverne il prototipo/interfaccia
*/
int trovaAnnoPiuProssimo(tpubblicazione *pubb, int len, int anno_corrente) {
    int min_diff = abs(pubb[0].anno_pubblicazione - anno_corrente);
    int anno_piu_prossimo = pubb[0].anno_pubblicazione;

    for (int i = 1; i < len; i++) {
        int diff = abs(pubb[i].anno_pubblicazione - anno_corrente);
        if (diff < min_diff || (diff == min_diff && pubb[i].anno_pubblicazione > anno_piu_prossimo)) {
            min_diff = diff;
            anno_piu_prossimo = pubb[i].anno_pubblicazione;
        }
    }

    return anno_piu_prossimo;
}


void lvl0_ex4(void) {
#define MAXLEN 50
    tpubblicazione pubb[MAXLEN];
    int len = leggiPubblicazioni("src/voti.txt", pubb);

    int anno;
    printf("Inserire l'anno:\n");
    scanf("%d", &anno);

    int anno_piu_prossimo = trovaAnnoPiuProssimo(pubb, len, anno);
    printf("Numero di citazioni per l'anno %d:\n", anno_piu_prossimo);
    for (int i = 0; i < len; i++) {
        if (pubb[i].anno_pubblicazione == anno_piu_prossimo) {
            printf("%d \n", pubb[i].numero_citazioni);
        }
    }
}

/*
Lvl 1 Ex2:
Scrivere una funzione cerca_citazioni che, dato un vettore di variabili di tipo
tpubblicazione, la sua dimensione n, ed un valore intero n_cit, restituisca la
posizione eventuale della variabile il cui slot numero_citazioni sia pari a n_cit
ricevuto in ingresso, restituendo -1 nel caso il valore non sia presente.
*/

int cerca_citazioni(tpubblicazione *data, int len, int numero_citazioni) {
    for (int i = 0; i < len; i++) {
        if (data[i].numero_citazioni == numero_citazioni) {
            return i;
        }
    }
    return -1;
}

/*
Lvl 2 Ex2:
Scrivere una funzione che, ricevendo una lista l del tipo definito nell’esercizio
precedente, stampi a video, per ogni atomo della lista, il nome del ricercatore ed
il numero di citazioni di ciascuna pubblicazione relativa all’anno più prossimo a
quello in corso, utilizzando le funzioni delle parti precedenti che si riterranno utili.
Nota: le funzioni CONS, TAIL, ISEMPTY, HEAD sono già implementate ed utilizzabili.
*/

int getCitazioniAnnoPiuProssimo(tpubblicazione *pubblicazioni, int n_pubblicazioni, int anno_corrente) {
    int min_differenza = abs(pubblicazioni[0].anno_pubblicazione - anno_corrente);
    int citazioni = pubblicazioni[0].numero_citazioni;

    for (int i = 1; i < n_pubblicazioni; i++) {
        int differenza = abs(pubblicazioni[i].anno_pubblicazione - anno_corrente);
        if (differenza < min_differenza ||
            (differenza == min_differenza && pubblicazioni[i].anno_pubblicazione > pubblicazioni[0].anno_pubblicazione)) {
            min_differenza = differenza;
            citazioni = pubblicazioni[i].numero_citazioni;
            }
    }

    return citazioni;
}

void stampaRicercatori(ListaRicercatori *l, int anno_corrente) {
    while (l != NULL) {
        printf("Nome Ricercatore: %s\n", l->nome);
        if (l->n_pubblicazioni > 0) {
            int citazioni = getCitazioniAnnoPiuProssimo(l->pubblicazioni, l->n_pubblicazioni, anno_corrente);
            printf("Citazioni anno piu' prossimo: %d\n", citazioni);
        } else {
            printf("Nessuna pubblicazione registrata.\n");
        }
        l = l->next;
    }
}

// Funzioni per creare e gestire la lista
ListaRicercatori *creaRicercatore(const char *nome, int n_pubblicazioni, tpubblicazione *pubblicazioni) {
    ListaRicercatori *nuovo = (ListaRicercatori *)malloc(sizeof(ListaRicercatori));
    nuovo->nome = strdup(nome);
    nuovo->n_pubblicazioni = n_pubblicazioni;
    memcpy(nuovo->pubblicazioni, pubblicazioni, n_pubblicazioni * sizeof(tpubblicazione));
    nuovo->next = NULL;
    return nuovo;
}

ListaRicercatori *aggiungiRicercatore(ListaRicercatori *head, ListaRicercatori *nuovo) {
    nuovo->next = head;
    return nuovo;
}

void lvl2_ex2(void) {
    int anno_corrente;

    // Richiesta dell'anno corrente
    printf("Inserire l'anno corrente:\n");
    scanf("%d", &anno_corrente);

    // Creazione dei dati di esempio
    tpubblicazione pubb1[] = {{15, 2020}, {20, 2022}, {10, 2019}};
    tpubblicazione pubb2[] = {{5, 2018}, {30, 2023}, {25, 2021}};

    ListaRicercatori *ricercatori = NULL;
    ricercatori = aggiungiRicercatore(ricercatori, creaRicercatore("Ricercatore A", 3, pubb1));
    ricercatori = aggiungiRicercatore(ricercatori, creaRicercatore("Ricercatore B", 3, pubb2));

    // Stampa dei risultati
    stampaRicercatori(ricercatori, anno_corrente);

    // Liberazione della memoria
    while (ricercatori != NULL) {
        ListaRicercatori *tmp = ricercatori;
        ricercatori = ricercatori->next;
        free(tmp->nome);
        free(tmp);
    }
}