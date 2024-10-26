Ecco il contenuto di un file `.md` con un riassunto dei temi richiesti. Puoi copiare questo testo e salvarlo in un file `.md`, per esempio `LogicaDigitale.md`.

```markdown
# Riassunto di Logica Digitale

Questo documento fornisce un riassunto dei principali argomenti relativi alla logica digitale, inclusi la costruzione delle tabelle di verità, le tecniche di semplificazione in algebra booleana, la conversione binaria/decimale e decimale/binaria, e la rappresentazione dei numeri in modulo e segno e in complemento a 2.

---

## 1. Costruzione delle Tabelle di Verità
Le tabelle di verità sono usate per descrivere tutte le possibili combinazioni di input e l'output corrispondente per un'espressione logica o una funzione booleana.

1. **Identifica le variabili**: determina tutte le variabili (es. A, B) nella funzione.
2. **Elenca le combinazioni di input**: per \( n \) variabili, ci sono \( 2^n \) combinazioni.
3. **Calcola l'output**: per ciascuna combinazione, calcola il risultato della funzione booleana.
   
**Esempio**: Per la funzione \( F = A \land B \lor \neg A \):
| A | B | \( \neg A \) | \( A \land B \) | \( F = A \land B \lor \neg A \) |
|---|---|-------------|----------------|---------------------------------|
| 0 | 0 | 1           | 0              | 1                               |
| 0 | 1 | 1           | 0              | 1                               |
| 1 | 0 | 0           | 0              | 0                               |
| 1 | 1 | 0           | 1              | 1                               |

---

## 2. Tecniche di Semplificazione in Algebra Booleana

L'algebra booleana può essere semplificata per ridurre la complessità delle espressioni logiche. Le tecniche principali includono:

- **Leggi di Identità**: \( A \lor 0 = A \), \( A \land 1 = A \).
- **Leggi di Complemento**: \( A \lor \neg A = 1 \), \( A \land \neg A = 0 \).
- **Leggi di De Morgan**: \( \neg (A \land B) = \neg A \lor \neg B \) e \( \neg (A \lor B) = \neg A \land \neg B \).
- **Teoremi di Assorbimento**: \( A \lor (A \land B) = A \), \( A \land (A \lor B) = A \).
- **Metodo delle Mappe di Karnough (K-Map)**: utile per semplificare espressioni booleane con 2, 3 o 4 variabili, dove le combinazioni sono organizzate per visualizzare i termini simili e semplificarli.

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
   - \( 1 \times 2^3 + 1 \times 2^2 + 0 \times 2^1 + 1 \times 2^0 = 8 + 4 + 0 + 1 = 13 \).

---

## 4. Rappresentazione in Modulo e Segno e in Complemento a 2

### Modulo e Segno
In questa rappresentazione, il **bit più significativo (MSB)** indica il segno: 0 per i numeri positivi e 1 per i numeri negativi. Gli altri bit rappresentano la parte assoluta del numero.

**Esempio**:
   - \( +5 \) in modulo e segno con 4 bit: `0101`
   - \( -5 \) in modulo e segno con 4 bit: `1101`

### Complemento a 2
Il complemento a 2 è una rappresentazione usata per rappresentare numeri negativi nei sistemi binari, poiché semplifica le operazioni aritmetiche binarie.

1. **Positivi**: rappresentati normalmente.
2. **Negativi**: inverti tutti i bit del numero positivo, quindi **aggiungi 1** al risultato.

**Esempio**: Rappresentare \( -5 \) in complemento a 2 con 4 bit:
   - \( +5 = 0101 \)
   - Inverti i bit: `1010`
   - Aggiungi 1: `1011`

---

Questo riassunto copre i concetti fondamentali della logica digitale e delle rappresentazioni numeriche in sistemi binari.
```
