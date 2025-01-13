
# Riassunto di Teoria elementi di informatica

Questo documento fornisce un riassunto dei principali argomenti relativi alla logica digitale, inclusi la costruzione delle tabelle di verità,
le tecniche di semplificazione in algebra booleana, la conversione binaria/decimale e decimale/binaria, e la rappresentazione dei numeri in modulo e segno e in complemento a 2.

---

## 1. Costruzione delle Tabelle di Verità
Le tabelle di verità sono usate per descrivere tutte le possibili combinazioni di input e l'output corrispondente per un'espressione logica o una funzione booleana.

1. **Identifica le variabili**: determina tutte le variabili (es. A, B) nella funzione.
2. **Elenca le combinazioni di input**: per \( n \) variabili, ci sono \( 2^n \) combinazioni.
3. **Calcola l'output**: per ciascuna combinazione, calcola il risultato della funzione booleana.
   
**Esempio**:
| A | B |       A'    |      A*B       |               A+B               |
|---|---|-------------|----------------|---------------------------------|
| 0 | 0 | 1           | 0              | 0                               |
| 0 | 1 | 1           | 0              | 1                               |
| 1 | 0 | 0           | 0              | 1                               |
| 1 | 1 | 0           | 1              | 1                               |

---

## 2. Tecniche di Semplificazione in Algebra Booleana

L'algebra booleana può essere semplificata per ridurre la complessità delle espressioni logiche. Le tecniche principali includono:

## Proprietà
- **Identità**:
  - \( A + 0 = A \)
  - \( A * 1 = A \)
  
- **Annichilimento**:
  - \( A + 1 = 1 \)
  - \( A * 0 = 0 \)
  
- **Complementazione**:
  - \( A +  A' = 1 \)
  - \( A *  A' = 0 \)

- **Idempotenza**:
  - \( A + A = A \)
  - \( A * A = A \)

- **Doppia Negazione**:
  - \( (A')' = A \)

- **Distributiva**:
  - \( A * (B + C) = A * B + A * C \)

- **Assorbimento**:
  - \( A + (A * B) = A \)

- **Leggi di De Morgan**:
  - \(  (A + B)' =  A' * B' \)
  - \(  (A * B)' =  A' + B' \)

---

## 3. Conversione Binaria/Decimale e Decimale/Binaria

### Conversione da Decimale a Binario
1. **Metodo delle Divisioni successive**: dividi il numero decimale per 2, annota il resto, e ripeti fino a ottenere un quoziente di zero. 
2. **Leggi i resti al contrario** per ottenere il numero binario.

**Esempio**: Convertire 13 in binario:
   - 13 ÷ 2 = 6 (resto 1)
   - 6 ÷ 2 = 3 (resto 0)
   - 3 ÷ 2 = 1 (resto 1)
   - 1 ÷ 2 = 0 (resto 1)
   - Risultato: 1101 (binario)

### Conversione da Binario a Decimale
1. **Moltiplica ciascuna cifra binaria per 2 elevato alla posizione della cifra** (partendo da 0 da destra).
2. **Somma i risultati**.

**Esempio**: Convertire 1101 in decimale:
   - \( 1 * 2^3 + 1 * 2^2 + 0 * 2^1 + 1 * 2^0 = 8 + 4 + 0 + 1 = 13 \).

---

## 4. Rappresentazione in Modulo e Segno e in Complemento a 2

## Modulo e Segno
In questa rappresentazione, il **bit più significativo (MSB)** indica il segno: 0 per i numeri positivi e 1 per i numeri negativi. Gli altri bit rappresentano la parte assoluta del numero.

**Esempio**:
   - \( +5 \) in modulo e segno con 4 bit: `0101`
   - \( -5 \) in modulo e segno con 4 bit: `1101`

 Rappresenta \( 2^{n-1} - 1 \) numeri positivi e \( 2^{n-1} - 1 \) numeri negativi.
 Non è più comunemente utilizzata poiché è stata sostituita dal complemento a 2.


## Complemento a 2
Il complemento a 2 è una rappresentazione usata per rappresentare numeri negativi nei sistemi binari, poiché semplifica le operazioni aritmetiche binarie.

### Conversione Decimale-Binario

### Numeri Negativi
1. Prendi il valore assoluto del numero.
2. Esegui il complemento a 1 (inverto i bit).
3. Aggiungi 1 al risultato.

### Numeri Positivi
1. Converti il numero in binario normalmente.
2. Verifica che il primo bit non sia 1. Se lo è, il numero non è convertibile con quel numero di bit.

---

### Conversione Binario-Decimale

### Numeri Negativi
1. Inverti tutti i bit.
2. Aggiungi 1 al risultato.
3. Converti il risultato in decimale.

### Numeri Positivi
1. Converti direttamente i bit in decimale.

**Esempio**: Rappresentare \( -5 \) in complemento a 2 con 4 bit:
   - \( +5 = 0101 \)
   - Inverti i bit: `1010`
   - Aggiungi 1: `1011`

---

Questo riassunto copre i concetti fondamentali della logica digitale e delle rappresentazioni numeriche in sistemi binari.
```
