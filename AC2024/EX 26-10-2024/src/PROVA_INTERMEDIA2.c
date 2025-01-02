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
int leggiPubblicazioni(tpubblicazione *pubb, char *nome_file) {

    FILE *fp = fopen(nome_file, "r");
    if (fp == NULL) {
        printf("Errore apertura file\n");
        exit(1);
    }
    int numero_elementi;
    if (fscanf(fp, "%d", &numero_elementi) != 1) {
        printf("Errore lettura file\n");
        fclose(fp);
        exit(1);
    };

    for (int i = 0; i < numero_elementi; i++) {
       if(fscanf(fp, "%d %d", &pubb[i].anno_pubblicazione, &pubb[i].numero_citazioni) != 2){
           printf("Errore lettura file\n");
           fclose(fp);
           exit(1);
       };
    }

    fclose(fp);
    return numero_elementi;
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

// controlla se la lista è vuota
int ISEMPTY(ListaRicercatori *lst) {
    return lst == NULL ? 1 : 0;
}

// ritorna il nome del ricercatore corrente
char *HEAD(ListaRicercatori *lst) {
    if (ISEMPTY(lst)) {
        printf("La lista è vuota\n");
        exit(1);
    }
    return lst->nome;
}

// prende il prossimo elemento della lista
ListaRicercatori *TAIL(ListaRicercatori *lst) {
    if (ISEMPTY(lst)) {
        printf("La lista è vuota\n");
        exit(1);
    }
    return lst->next;
}

// aggiunge un nuovo ricercatore
ListaRicercatori *CONS(char *nome, int num_pubblicazioni, tpubblicazione *pubblicazioni, ListaRicercatori *lst) {
    if (num_pubblicazioni > 50) {
        printf("Numero massimo di pubblicazioni superato (50)\n");
        exit(1);
    }

    ListaRicercatori *newNode = (ListaRicercatori *) malloc(sizeof(ListaRicercatori));
    if (newNode == NULL) {
        printf("Allocazione memoria fallita\n");
        exit(1);
    }
    newNode->nome = strdup(nome);
    if (newNode->nome == NULL) {
        printf("Allocazione memoria per il nome fallita\n");
        free(newNode);
        exit(1);
    }
    newNode->num_pubblicazioni = num_pubblicazioni;


    for (int i = 0; i < num_pubblicazioni; i++) {
        newNode->pubblicazioni[i] = pubblicazioni[i];
    }

    newNode->next = lst;
    return newNode;
}

// restituisce il numero di citazioni avvenute nell anno più vicino a quello dato
int getCitazioni(tpubblicazione *pubblicazione, int n_pubblicazioni, int anno_corrente) {
    int min_diff = abs(pubblicazione[0].anno_pubblicazione - anno_corrente);
    int citazioni = pubblicazione[0].numero_citazioni;

    for (int i = 1; i < n_pubblicazioni; i++) {
        int differenza = abs(pubblicazione[i].anno_pubblicazione - anno_corrente);
        if (differenza < min_diff) {
            min_diff = differenza;
            citazioni = pubblicazione[i].numero_citazioni;
        }
    }
    return citazioni;
}

// stampa il ricercatore e il numero di citazioni avvenute nell anno più vicino a quello corrente
void stampaRicercatori(ListaRicercatori *lst, int anno_corrente) {
    if (ISEMPTY(lst)) {
        printf("Lista vuota\n");
        return;
    }
    while (!ISEMPTY(lst)) {
        printf("Nome: %s\n", HEAD(lst));
        if (lst->num_pubblicazioni > 0) {
            int citazioni = getCitazioni(lst->pubblicazioni, lst->num_pubblicazioni, anno_corrente);
            printf("Citazioni piu vicine all'anno %d: %d citazioni [ avvenute nel %d ]\n", anno_corrente, citazioni,lst->pubblicazioni->anno_pubblicazione);
        } else {
            printf("Nessuna pubblicazione.\n");
        }
        lst = TAIL(lst);
    }
}

// libera la memoria allocata
void dealloca(ListaRicercatori *lst) {
    while (!ISEMPTY(lst)) {
        ListaRicercatori *temp = lst;
        lst = TAIL(lst);
        free(temp);
    }
}

//stampa la lista completa
void stampaLista(ListaRicercatori *lst) {
    if (ISEMPTY(lst)) {
        printf("La lista è vuota\n");
        exit(1);
    }
    printf("\nLista dei ricercatori:\n");
    while (!ISEMPTY(lst)) {
        printf("\nNome: %s\nNum Pubblicazioni: %d\n", lst->nome, lst->num_pubblicazioni);
        for (int i = 0; i < lst->num_pubblicazioni; i++) {
            printf("Pubblicazione %d: Citazioni: %d, Anno: %d\n",
                   i + 1, lst->pubblicazioni[i].numero_citazioni,
                   lst->pubblicazioni[i].anno_pubblicazione);
        }
        lst = TAIL(lst);
    }
}


void lvl2_ex2(void) {
    ListaRicercatori *ricercatori = NULL;


    tpubblicazione pub1[] = {{50, 2023}, {30, 2022}};
    tpubblicazione pub2[] = {{20, 2021}, {15, 2020}, {10, 2019}};


    ricercatori = CONS("Riccardo Deidda", 2, pub1, ricercatori);
    ricercatori = CONS("Matteo Word", 3, pub2, ricercatori);


    stampaRicercatori(ricercatori, 2024);
    stampaLista(ricercatori);


    dealloca(ricercatori);

}
