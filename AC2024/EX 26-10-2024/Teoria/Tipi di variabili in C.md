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
