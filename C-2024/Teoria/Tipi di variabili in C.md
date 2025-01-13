# Tipi di Variabili in C

In C, esistono diversi tipi di variabili, ciascuno progettato per gestire vari tipi di dati. Vediamo i tipi di variabili principali:

## 1. Tipi di Dati Primitivi

### a. Interi
Gli interi sono utilizzati per memorizzare numeri interi, positivi o negativi.

- **`int`**: il tipo intero standard, generalmente occupa 4 byte (32 bit).
- **`short int`**: occupa meno spazio (tipicamente 2 byte) e ha un intervallo ridotto.
- **`long int`**: occupa più spazio di `int` (tipicamente 4 o 8 byte), con un intervallo maggiore.
- **`long long int`**: occupa ancora più spazio (8 byte o più), consentendo numeri molto grandi.

**Varianti con segno**:
- **`signed`**: permette di rappresentare numeri positivi e negativi.
- **`unsigned`**: permette solo numeri positivi e aumenta l'intervallo massimo.

### b. Virgola Mobile (Float)
I numeri in virgola mobile memorizzano valori con parte decimale.

- **`float`**: rappresenta numeri con virgola mobile a precisione singola (4 byte), con una precisione tipica di 6-7 cifre decimali.
- **`double`**:: rappresenta numeri con virgola mobile a precisione doppia (8 byte), con una precisione tipica di 15 cifre decimali.
- **`long double`**:: occupa più spazio di double (in genere 10, 12, o 16 byte), offrendo ancora più precisione.

### c. Caratteri
I caratteri vengono memorizzati usando il tipo char, che rappresenta singoli caratteri ASCII.

- **`float`**: occupa 1 byte (8 bit), con un intervallo tipicamente da -128 a 127 (signed) o da 0 a 255 (unsigned).
- **`signed char e unsigned char`**: varianti del tipo char per rappresentare rispettivamente caratteri con segno o senza segno.


## 2. Principali Specificatori di Formato in C.

- **`%d`**: Rappresenta un intero decimale con segno (int).
- **`%i`**: Simile a %d, può essere usato anche per interi con segno.
- **`%u`**: Rappresenta un intero decimale senza segno (unsigned int).
- **`%o`**: Rappresenta un numero in ottale (base 8).
- **`%x o %X`**: Rappresenta un numero esadecimale (base 16), con lettere minuscole (%x) o maiuscole (%X) per cifre da 10 a 15.
- **`%f`**: Stampa un numero in virgola mobile a precisione singola (float) o doppia (double).
- **`%e o %E`**: Stampa un numero in notazione scientifica (esponente), con lettere e o E.
- **`%g o %G`**: Seleziona automaticamente tra notazione normale e scientifica, scegliendo quella più compatta.
- **`%c`**: Stampa un singolo carattere (char).
- **`%s`**: Stampa una stringa di caratteri (char array o char *).
- **`%p`**: Stampa un indirizzo di memoria. Viene usato per puntatori.
- **`%ld, %lld`**: Per interi long o long long.
- **`%hd`**: Per interi short.
- **`%Lf`**: Per long double.
