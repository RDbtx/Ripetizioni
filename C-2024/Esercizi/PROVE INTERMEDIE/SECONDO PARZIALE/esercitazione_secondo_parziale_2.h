#ifndef ESERCITAZIONE_SECONDO_PARZIALE_2_H
#define ESERCITAZIONE_SECONDO_PARZIALE_2_H

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Esercizio 1:
Creare una struttura studente per rappresentare un singolo
studente con i seguenti campi:

-matricola (intero)
-nome (stringa)
-cognome (stringa)
-media_voti (float)
*/


typedef struct {
    int matricola;
    char cognome[50];
    float media_voti;
} studente;

//Esercizio 2:
void StampaStudente(studente *data, int len);

//Esercizio 3:
int leggiStudente(studente *studenti, int n, int max_len);

//Esercizio 4:
int trovaStudenteMediaMassima(studente *studenti, int n);

//Esercizio 5:
void salvaStudentiSuFile(studente *studenti, int n, const char *nome_file);

/*
Esercizio 6:
Creare una struttura evento per rappresentare un evento con i seguenti campi:

-nome_evento (stringa)
-data (vettore di 3 elementi interi [gionro][mese][anno])
-luogo (stringa)
-numero_partecipanti (intero)
*/

typedef struct {
    char nome_evento[50];
    int data[3];
    char luogo[50];
    int num_partecipanti;
} evento;

//Esercizio 7:
int leggiEventiDaFile(const char *nome_file, evento *eventi, int max_len);

//Esercizio 8:
int trovaEventoPerNome(evento *eventi, int n, char *nome_evento);

/*
Esercizio 9:
Creare una struttura film per rappresentare un film con i seguenti campi:

-titolo (stringa)
-regista (stringa)
-anno_uscita (intero)
-durata_minuti (intero)
*/

typedef struct {
    char titolo[50];
    char regista[50];
    int anno_uscita;
    int durata_minuti;
} film;

/*
Esercizio 10:
Creare una struttura veicolo per rappresentare un veicolo con i seguenti campi:

-targa (stringa)
-marca (stringa)
-modello (stringa)
-anno_immatricolazione (intero)
-chilometraggio (float)
*/

typedef struct {
    int targa;
    char marca[50];
    char modello[50];
    int anno_immatricolazione;
    float chilometraggio;
} veicolo;

//Esercizio 11:
void stampaFilm(film *films, int n);

//Esercizio 12:
void stampaVeicolo(const veicolo *v);
