# ESERCIZIO 1
Scrivere la tabella di verità dell'espressione booleana Y=(A+notB)⋅(notA+B) e dedurre se essa equivale a qualche operatore noto.
| A | B | Y = (A + notB) · (notA + B) |
|---|---|-------------------------|
| 0 | 0 |           1             |
| 0 | 1 |           1             |
| 1 | 0 |           1             |
| 1 | 1 |           0             |


L'equazione rappresenta un NAND


# ESERCIZIO 2
Scrivere un programma in C che, ricevendo da tastiera due coppie di numeri reali, rappresentanti la coordinata y e x di due punti sul piano cartesiano, calcoli la distanza euclidea tra i due punti e stampi il risultato.
```c
float x1, x2, y1, y2;
    printf("inserire X e Y del primo numero:\n");
    scanf("%f%f", &x1, &y1);
    printf("inserire X e Y del secondo numero:\n");
    scanf("%f%f", &x2, &y2);

    if (x1 > x2) {
        float temp;
        temp = x2;
        x2 = x1;
        x1 = temp;
        temp = y2;
        y2 = y1;
        y1 = temp;
    }

    float distanza = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("Punto 1: ( %.2f , %.2f )\n", x1, y1);
    printf("Punto 2: ( %.2f , %.2f )\n", x2, y2);
    printf("DISTANZA = %.2f\n", distanza);

```
# ESERCIZIO 3
Convertire il valore -25 nella corrispondente stringa binaria in complemento a 2, utilizzando 8 bit. Spiegare i passi della conversione.

1. Calcolare il valore assoluto binario a 8 bit di 25: `00011001`
2. Invertire tutti i bit: `11100110`
3. Aggiungere 1: `11100111`
4. `25 == 11100111`


# ESERCIZIO 4
Scrivere un frammento di codice C che calcola e stampa l'area di un triangolo dato il valore di base e altezza inseriti dall'utente.
```c
float base, altezza;
    printf("inserire base:\n");
    scanf("%f", &base);
    printf("inserire altezza:\n");
    scanf("%f", &altezza);

    float area = (base * altezza) / 2;
    printf("AREA TRIANGOLO = %.2f\n", area);
```
# ESERCIZIO 5
Estendere il programma dell'esercizio 1.2 per consentire la determinazione iterativa di aree di diversi triangoli, fino a quando l'utente inserisce un valore negativo per la base o l'altezza.
```c
float base, altezza;
    do {
        printf("inserire base:\n");
        scanf("%f", &base);
        printf("inserire altezza:\n");
        scanf("%f", &altezza);

        float area = (base * altezza) / 2;
        printf("AREA TRIANGOLO = %.2f\n", area);
    } while (altezza > 0 && base > 0);
```
# ESERCIZIO 6
Integrare nel programma precedente una funzione che, dati in ingresso tre lati (salvati all interno di un vettore), verifichi se i valori inseriti possono formare un triangolo valido. Se non lo sono, il programma deve terminare e stampare un messaggio appropriato. In caso positivo, calcolare e stampare il perimetro del triangolo.
```c
#define len 3
    float lato[len];
    float perimetro;
    for (int i = 0; i < len; i++) {
        printf("inserire lato %d:\n", i + 1);
        scanf("%f", &lato[i]);
    }

    if (lato[0] + lato[1] <= lato[2] && lato[1] + lato[2] <= lato[0] || lato[2] + lato[0] <= lato[1]) {
        printf("ERRORE! I LATI INSERITI NON FORMANO UN TRIANGOLO VALIDO!");
        return 0;
    }

    perimetro = lato[0] + lato[1] + lato[2];
    printf("PERIMETRO = %.2f\n", perimetro);
```
