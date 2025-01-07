#include "esercitazione_secondo_parziale_2.h"


/*
Esercizio 2:
Scrivere una funzione StampaStudenteche permetta ricevendo un array di strutture
di tipo studente e la sua lunghezza; possa stampare a video ogni elemento
dell array e tutti i suoi sottoelementi;
*/

void StampaStudente(studente *data, int len) {
    if (len == 0) {
        printf("Nessuno studente e' presente nell'elenco/n");
        return;
    }

    printf("Lista Studenti:\n");
    for (int i = 0; i < len; i++) {
        printf("\n[%s]\n", data[i].cognome);
        printf("Matricola: %d\n", data[i].matricola);
        printf("Media voti: %.2f", data[i].media_voti);
    }
};

/*
Esercizio 3:
Scrivere una funzione leggiStudente che aggiunga un nuovo studente a un array di strutture studente, ricevendo l'array,
la lunghezza attuale (n) e la lunghezza massima (max_len). La funzione deve chiedere
i dati del nuovo studente e aggiungerli all'array se c'è spazio disponibile.
Se l'array è pieno, deve segnalare l'errore senza modificare nulla.
La funzione restituisce la nuova lunghezza dell'array aggiornata.
*/

int leggiStudente(studente *studenti, int n, int max_len) {
    if (n >= max_len) {
        printf("Errore: array pieno\n");
        return n;
    }

    printf("Inserisci i dati del nuovo studente:\n");
    printf("Matricola: ");
    scanf("%d", &studenti[n].matricola);
    printf("Cognome: ");
    scanf("%s", studenti[n].cognome);
    printf("Media voti: ");
    scanf("%f", &studenti[n].media_voti);

    return n + 1;
}

/*
Esercizio 4:
Scrivere una funzione trovaStudenteMediaMassima che:
Riceve un array di tipo studente e la sua dimensione.
Restituisce l’indice dello studente con la media voti più alta.
*/

int trovaStudenteMediaMassima(studente *studenti, int n) {
    if (n == 0) {
        printf("Nessuno studente e' presente");
        return -1;
    }

    int indice_max = 0;
    for (int i = 1; i < n; i++) {
        if (studenti[i].media_voti > studenti[indice_max].media_voti) {
            indice_max = i;
        }
    }
    return indice_max;
}

/*
Esercizio 5:
Scrivere una funzione salvaStudentiSuFile che riceva come parametri
un array di strutture di tipo studente, la lunghezza dell'array (n),
e il nome di un file (stringa). La funzione deve salvare i dati di
tutti gli studenti presenti nell'array in un file di testo:

Il file è strutturato in questo modo:
n <- numero elemeti totali del file
<matricola> <cognome> <media>
<matricola> <cognome> <media>
*/

void salvaStudentiSuFile(studente *studenti, int n, const char *nome_file) {
    FILE *fp = fopen(nome_file, "w");
    if (fp == NULL) {
        printf("Errore: impossibile aprire il file\n");
        return;
    }
    fprintf(fp, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %.2f\n", studenti[i].matricola,
                studenti[i].cognome, studenti[i].media_voti);
    }
    fclose(fp);
}

/*
Esercizio 7:
Scrivere una funzione leggiEventiDaFile che legge un file di testo
contenente eventi, dove ogni riga rappresenta un evento nel seguente formato:

<nome_evento> <giorno> <mese> <anno> <luogo> <numero_partecipanti>
<nome_evento> <giorno> <mese> <anno> <luogo> <numero_partecipanti>

il file restituisce il numero di eventi letti in totale e salva ogni evento
nell array eventi di tipo evento
*/

int leggiEventiDaFile(const char *nome_file, evento *eventi, int max_len) {
    FILE *fp = fopen(nome_file, "r");
    if (fp == NULL) {
        printf("Errore: impossibile aprire il file %s\n", nome_file);
        exit(1);
    }

    int count = 0;
    while (count < max_len && fscanf(fp, "%s %d %d %d %s %d",
                                     eventi[count].nome_evento,
                                     &eventi[count].data[0],
                                     &eventi[count].data[1],
                                     &eventi[count].data[2],
                                     eventi[count].luogo,
                                     &eventi[count].num_partecipanti) == 6) {
        count++;
    }

    if (count > max_len) {
        printf("Errore: impossibile leggere tutti gli elementi\n");
    }

    fclose(fp);
    return count;
}

/*
Esercizio 8:
Scrivere una funzione trovaEventoPerNome che:
Riceve un array di tipo evento, la sua dimensione, e una stringa nome_evento.
Il valroe trovato dev essere restituito a fine funzione e utilizzato per stampare
a schermo i dati relativi all evento trovato. Se l'evento non è stato trovato
verrà stampato un avviso a schermo e verrà restituito -1
*/

int trovaEventoPerNome(evento *eventi, int n, char *nome_evento) {
    int index_evento = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(eventi[i].nome_evento, nome_evento) == 0) {
            index_evento = i;
            break;
        }
    }

    if (index_evento == -1) {
        printf("Evento non trovato!\n");
        return index_evento;
    }
    printf("\nEvento:\n");
    printf("Nome: %s\n", nome_evento);
    printf("Luogo: %s\n", eventi[index_evento].luogo);
    printf("Data: [%d/%d/%d]",
           eventi[index_evento].data[0],
           eventi[index_evento].data[1],
           eventi[index_evento].data[2]);
    printf("Partecipanti: %d\n", eventi[index_evento].num_partecipanti);
    return index_evento;
}

/*
Esercizio 11:
Scrivere una funzione stampaFilm che riceve un array di strutture di tipo film
e la sua dimensione (n). La funzione deve stampare i dettagli di ciascun film nel
formato:

Titolo: <titolo>
Regista: <regista>
Anno di uscita: <anno_uscita>
Durata: <durata_minuti> minuti
*/

void stampaFilm(film *films, int n) {
    for (int i = 0; i < n; i++) {
        printf("Titolo: %s\n", films[i].titolo);
        printf("Regista: %s\n", films[i].regista);
        printf("Anno di uscita: %d\n", films[i].anno_uscita);
        printf("Durata: %d minuti\n\n", films[i].durata_minuti);
    }
}

/*
Esercizio 12:
Scrivere una funzione stampaVeicolo che riceve un puntatore a struttura di tipo veicolo
e la sua dimensione (n). La funzione deve stampare i dettagli della struttura nel
formato:

Dettagli del veicolo:
Targa: 12345
Marca: Toyota
Modello: Corolla
Anno di immatricolazione: 2015
Chilometraggio: 50000.00 km
*/

void stampaVeicolo(const veicolo *v) {
    printf("Targa: %d\n", v->targa);
    printf("Marca: %s\n", v->marca);
    printf("Modello: %s\n", v->modello);
    printf("Anno di immatricolazione: %d\n", v->anno_immatricolazione);
    printf("Chilometraggio: %.2f km\n", v->chilometraggio);
}
