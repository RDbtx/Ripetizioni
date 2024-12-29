#include "TUTORATO6.h"

/*
Esercizio 1:
Scrivere una funzione che passate due variabili, ne scambi i valori e
stampi a video il risultato. La stampa deve avvenire sia dentro che fuori
dalla funzione (dopo la chiamata della stessa).
*/

void tutorato6_ex1(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("variabili scambiate!\n");
}

/*
Esercizio 2:
Scrivere un programma che:
● Chieda all'utente di specificare la dimensione n di un vettore di interi.
● Allochi dinamicamente memoria per il vettore.
● Chieda all'utente di inserire n interi che devono essere salvati nel
vettore.
*/

void tutorato6_ex2() {
    int N;
    printf("inserire la dimensione del vettore:\n");
    scanf("%d", &N);

    int *vettore;
    vettore = (int *) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        printf("inserire l'elemento [%d] del vettore:\n", i + 1);
        scanf("%d", &vettore[i]);
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", vettore[i]);;
    }
    free(vettore);
}

/*
Esercizio 3:
Sviluppare un programma in grado di leggere da un file un insieme di coppie stringa-valore, dove
ogni coppia rappresenta il cognome di uno studente e il relativo voto ottenuto nell'esame.
Successivamente, memorizzare queste informazioni all'interno di una struttura denominata "studenti_edi".
Il file è formattato come segue:
● La prima riga rappresenta il numero di coppie cognome-voto presenti al suo interno
● Le righe successive sono formate dal cognome e dal voto dello studente separati da uno spazio
(una riga per studente).
Per quanto riguarda la struttura studenti_edi, essa è formata da un campo "cognome" di tipo
stringa e da un campo "voto" di tipo intero.
*/


void tutorato6_ex3() {
    FILE *fp;
    fp = fopen("src/voti.txt", "r");
    if (fp == NULL) {
        printf("Errore apertura file\n");
        return;
    }
    int numero_studenti;
    fscanf(fp, "%d", &numero_studenti);
    studente *studenti = (studente *) malloc(numero_studenti * sizeof(studente));
    for (int i = 0; i < numero_studenti; i++) {
        fscanf(fp, "%s %d", studenti[i].cognome, &studenti[i].voto);
    }
    fclose(fp);
    for (int i = 0; i < numero_studenti; i++) {
        printf("%s %d\n", studenti[i].cognome, studenti[i].voto);
    }
    free(studenti);
}

/*
Esercizio 4:
Supporre di avere la seguente lista concatenata:
1) Creare tutte le funzioni che servono per gestire correttamente la lista.
2) Definire una funzione che legge da file nomefile un elenco di stringhe e le memorizza in una
variabile di tipo listaVoti restituita in uscita. Le stringhe del file sono composte al MASSIMO da 2
caratteri, e assumono i seguenti valori: «AP», «RC», «MC» e «GO».
3) Definire una funzione che conta il numero di occorrenze delle stringhe presenti nella lista
concatenata di tipo listaVoti, e restituisce un vettore di interi di 5 componenti, così fatto: la
componente 0 contiene il numero complessivo di elementi, le 1-2 il numero di occorrenze “AP” e
“RC”, le 3-4 il numero di occorrenze di “MC” e “GO”.
4) Definire una funzione che riceve ingresso il vettore di occorrenze calcolato come al punto precedente
e stampi a video l’elenco delle stringhe, seguito dal valore di occorrenze espresso in percentuale.
*/

int ISEMPTY(listaVoti *lst) {
    return lst == NULL;
}

// Funzione HEAD
char *HEAD(listaVoti *lst) {
    if (ISEMPTY(lst)) {
        printf("La lista è vuota\n");
        exit(1);
    }
    return lst->preferenza;
}

// Funzione TAIL
listaVoti *TAIL(listaVoti *lst) {
    if (ISEMPTY(lst)) {
        printf("La lista è vuota\n");
        exit(1);
    }
    return lst->next;
}

// Funzione CONS
listaVoti *CONS(char *val, listaVoti *lst) {
    listaVoti *newNode = (listaVoti *)malloc(sizeof(listaVoti));
    if (newNode == NULL) {
        printf("Allocazione memoria fallita\n");
        exit(1);
    }
    newNode->preferenza = strdup(val);
    if (newNode->preferenza == NULL) {
        printf("Allocazione memoria per preferenza fallita\n");
        free(newNode);
        exit(1);
    }
    newNode->next = lst;
    return newNode;
}

// Funzione per stampare la lista
void stampaLista(listaVoti *lst) {
    if (ISEMPTY(lst)) {
        printf("La lista è vuota\n");
        return;
    }
    printf("Lista delle preferenze:\n");
    while (!ISEMPTY(lst)) {
        printf("%s ", HEAD(lst));
        lst = TAIL(lst);
    }
    printf("NULL\n");
}

// Funzione per deallocare la lista
void dealloca(listaVoti *lst) {
    while (!ISEMPTY(lst)) {
        listaVoti *temp = lst;
        lst = TAIL(lst);
        free(temp->preferenza);
        free(temp);
    }
}

// Funzione per leggere da file
listaVoti *Leggi_File(const char *nomefile, listaVoti *lst) {
    FILE *fp = fopen(nomefile, "r");
    if (fp == NULL) {
        printf("Errore apertura file %s\n", nomefile);
        return NULL;
    }

    char buffer[3]; // Stringa di massimo 2 caratteri più terminatore
    while (fscanf(fp, "%2s", buffer) == 1) {
        lst = CONS(buffer, lst);
    }

    fclose(fp);
    return lst;
}

// Funzione per contare le occorrenze
int *contaOccorrenze(listaVoti *lst, int *vettore) {
    while (!ISEMPTY(lst)) {
        vettore[0]++; // Incrementa il numero totale
        if (strcmp(HEAD(lst), "AP") == 0) vettore[1]++;
        else if (strcmp(HEAD(lst), "RC") == 0) vettore[2]++;
        else if (strcmp(HEAD(lst), "MC") == 0) vettore[3]++;
        else if (strcmp(HEAD(lst), "GO") == 0) vettore[4]++;
        lst = TAIL(lst);
    }
    return vettore;
}

// Funzione per stampare le percentuali
void stampaPercentuali(int *vettore) {
    if (vettore[0] == 0) {
        printf("Nessuna preferenza nella lista\n");
        return;
    }

    printf("\nTotale voti: %d\n", vettore[0]);
    printf("AP: %.2f%%\n", (vettore[1] / (float)vettore[0]) * 100);
    printf("RC: %.2f%%\n", (vettore[2] / (float)vettore[0]) * 100);
    printf("MC: %.2f%%\n", (vettore[3] / (float)vettore[0]) * 100);
    printf("GO: %.2f%%\n", (vettore[4] / (float)vettore[0]) * 100);
}

// Funzione principale
void tutorato6_ex4() {
    listaVoti *lst = NULL;

    // Leggi la lista da file
    lst = Leggi_File("src/voti.txt", lst);
    if (lst == NULL) {
        return;
    }

    // Conta le occorrenze
    int vettore[5] = {0};
    contaOccorrenze(lst, vettore);

    // Stampa la lista
    stampaLista(lst);

    // Stampa le percentuali
    stampaPercentuali(vettore);

    // Dealloca la lista
    dealloca(lst);
}
