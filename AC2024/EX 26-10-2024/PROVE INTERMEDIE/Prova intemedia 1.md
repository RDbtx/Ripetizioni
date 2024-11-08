# Simulazione Prima Prova Intermedia del Modulo di Elementi di Informatica

**Compito del 15 Luglio 1997**

---

### Istruzioni Generali
MOTIVARE IN MANIERA CHIARA LE SOLUZIONI PROPOSTE A CIASCUNO DEGLI ESERCIZI SVOLTI  
SCRIVERE LE RISPOSTE NEI RIQUADRI ASSEGNATI – INDENTARE IL CODICE C

---

## Livello 0
**Nota**: il massimo punteggio ottenibile risolvendo gli esercizi di questo livello è 23.

### Esercizio 0.1 (4 punti)
Scrivere la tabella di verità dell’espressione booleana \( Z = A + \overline{A}B \) e dedurre se essa equivale a qualche operatore noto.

#### Tabella di Verità

| A | B | \( Z = A + \overline{A}B \) |
|---|---|----------------------------|
| 0 | 0 | 0                          |
| 0 | 1 | 1                          |
| 1 | 0 | 1                          |
| 1 | 1 | 1                          |

#### Conclusione
L'espressione \( Z = A + \overline{A}B \) equivale all'operatore OR logico
---

### Esercizio 0.2 (3 punti)
Spiegare in modo chiaro e sintetico l’architettura di von Neumann.

---

### Esercizio 0.3 (16 punti)
Scrivere un programma C che, ricevendo da tastiera due coppie di numeri reali, rappresentanti la coordinata y e x di due punti sul piano cartesiano, calcoli il coefficiente angolare (\( m \)) e l’ordinata all’origine (\( q \)) della retta passante per i punti dati, secondo l’equazione:

\[
y = mx + q
\]

Stampi infine a video l’espressione:  
"L’equazione della retta è: y = `<m>` * x + `<q>`"  
dove `<m>` e `<q>` sono i valori calcolati.

#### Codice in C

```c
#define len 2
float x[len];
float y[len];

do {
    for (int i = 0; i < len; i = i + 1) {
        printf("inserire l'ascissa X del punto %d:\n", i + 1);
        scanf("%f", &x[i]);
        printf("inserire l'ordinata Y del punto %d:\n", i + 1);
        scanf("%f", &y[i]);
    }
} while (x[0] == y[0] && x[1] == y[1]);

float distanza;
float quota;
float coefficiente_angolare;
float traslazione;

// controllo le posizioni dei dati inseriti
if (x[0] > x[1]) {
    distanza = x[0] - x[1];
} else
    distanza = x[1] - x[0];

if (y[0] > y[1]) {
    quota = y[0] - y[1];
} else
    quota = y[1] - y[0];

// calcolo m e q
coefficiente_angolare = (quota / distanza);
traslazione = y[0] / (coefficiente_angolare * x[0]);

printf("FUNZIONE: Y = %.2fX + %.2f\n", coefficiente_angolare, traslazione);
printf("COEFF ANGOLARE: %.5f\n", coefficiente_angolare);
printf("TRASLAZIONE RETTA: %.5f\n", traslazione);
```

---

## Livello 1
**Attenzione**: gli esercizi di questo livello saranno corretti solo se la somma dei punteggi ottenuti negli esercizi precedenti sarà maggiore o uguale a 18.  
**Nota**: il massimo punteggio ottenibile risolvendo gli esercizi di questo livello è 28.

### Esercizio 1.1 (4 punti)
Convertire il valore -17 nella corrispondente stringa binaria in complemento a 2, utilizzando 6 bit. Spiegare i passi della conversione.

#### Soluzione

1. **Valore assoluto binario a 6 bit di -17**:  
   - \( -17 \) in valore assoluto è \( 17 \).  
   - La rappresentazione binaria di \( 17 \) su 6 bit è: `010001`.

2. **Complemento a 1**:  
   - Invertendo tutti i bit di `010001` si ottiene: `101110`.

3. **Complemento a 2**:  
   - Aggiungendo 1 al complemento a 1:  
     \[
     101110 + 1 = 101111
     \]

Quindi, la rappresentazione in complemento a 2 di \( -17 \) su 6 bit è `101111`.
---

### Esercizio 1.2 (6 punti)
Scrivere il frammento di codice da aggiungere all’esercizio 0.3 che calcola l’intervallo di valori di \( x \) per i quali la parabola \( y = ax^2 + bx + c \) risulta negativa. Si considerino i valori \( a \), \( b \), \( c \) letti da tastiera.  
**Nota**: sia \( a \neq 0 \) e \( \Delta > 0 \).  
**Suggerimento**: per la radice quadrata si usi la funzione `sqrt()` di `math.h`.

#### Codice

```c
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, delta, x1, x2;

    printf("Inserisci i coefficienti a, b, c della parabola (con a diverso da 0): ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        printf("Il valore di 'a' deve essere diverso da 0.\n");
        return 1;
    }

    delta = b * b - 4 * a * c;

    if (delta <= 0) {
        printf("Non ci sono intervalli per cui la parabola è negativa (Delta <= 0).\n");
    } else {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);

        if (a > 0) {
            printf("La parabola è negativa per x appartenente all'intervallo: (%.2f, %.2f)\n", x1, x2);
        } else {
            printf("La parabola è negativa per x non appartenente all'intervallo: (%.2f, %.2f)\n", x1, x2);
        }
    }

    return 0;
}
```
---

## Livello 2
**Attenzione**: gli esercizi di questo livello saranno corretti solo se la somma dei punteggi ottenuti negli esercizi precedenti sarà maggiore o uguale a 25.

### Esercizio 2
Completare il programma dell’esercizio 1.2, facendo sì che venga chiesta iterativamente una tripla di coefficienti reali \( a, b, c \), e si studi il segno della relativa parabola come nell’esercizio 1.2, uscendo dal programma quando il coefficiente \( a \) risulta pari a zero oppure \( \Delta \) risulta negativo o nullo.
Aggiungere al programma precedente il frammento di codice che calcola l’ampiezza minima di tutti gli intervalli interni calcolati nei quali il segno della parabola risulta strettamente positivo. Per esempio, dato un intervallo interno \( I = (x_1, x_2) \), per cui si ha \( y = ax^2 + bx + c > 0 \), l’ampiezza è data da \( \sqrt{(x_1 - x_2)^2} \).

```c
#define len 3
#define zerilen 2
float coefficenti[len];
char coefficenti_name[] = {'A', 'B', 'C'};

for (int i = 0; i < len; i++) {
    printf("inserire il coefficente %c:\n", coefficenti_name[i]);
    scanf("%f", &coefficenti[i]);
}
printf("\n%.2f\n%.2f\n", coefficenti[0], coefficenti[1]);

if (coefficenti[0] == 0) {
    printf("ERROR = A < 0");
    return 1;
}

// y = ax^2 + bx + c
// calcolo gli zeri
float delta = sqrt(pow(coefficenti[1], 2) - 4 * coefficenti[0] * coefficenti[2]);
if (delta < 0 || delta == 0) {
    printf("ERROR = DELTA NOT VALID");
    return 1;
}
float zeri[zerilen];

zeri[0] = (-coefficenti[1] + delta) / (2 * coefficenti[0]);
zeri[1] = (-coefficenti[1] - delta) / (2 * coefficenti[0]);
printf("\n%.2f\n%.2f\n", zeri[0], zeri[1]);

// metto in ordine gli zeri
if (zeri[0] > zeri[1]) {
    float temp = zeri[1];
    zeri[1] = zeri[0];
    zeri[0] = temp;
}

// controllo l'andamento della funzione tramite il valore A
if (coefficenti[0] < 0) {
    printf("la funzione e' negativa per [X < %.2f & X > %.2f]\n", zeri[0], zeri[1]);
    // calcolo l'intervallo interno
    float intervallo;
    intervallo = sqrt((zeri[1] - zeri[0]));
    printf("l'intervallo positivo e' ampio [%.4f]\n", intervallo);
} else {
    printf("la funzione e' negativa per [%.2f < X < %.2f]", zeri[0], zeri[1]);
}
```
---
