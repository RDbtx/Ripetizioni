# Calcolo delle Correnti e della Potenza nel Sistema Trifase

## Calcolo delle Correnti \( I_1 \), \( I_2 \), e \( I_3 \)
### Dati del problema
- Tensione di linea: \( V_{12} = 220 \sqrt{3} \, \text{V} \)
- Impedenze:
  - \( Z_1 = 10 (1 + j) \, \Omega \)
  - \( Z_3 = 5 (1 + j) \, \Omega \)

### Calcolo della tensione di fase
La tensione di fase è calcolata come:
\[
V_{1N} = \\frac{V_{12}}{\\sqrt{3}} = \\frac{220 \\sqrt{3}}{\\sqrt{3}} = 220 \, \\text{V}
\]

### Calcolo delle correnti
#### Corrente \( I_1 \)
\[
I_1 = \\frac{V_{1N}}{Z_1} = \\frac{220}{10 (1 + j)} = 11 - 11j \, \\text{A}
\]

#### Corrente \( I_2 \)
Essendo un sistema trifase simmetrico:
\[
I_2 = I_1 \\cdot e^{-j \\frac{2\\pi}{3}} \approx -5,5 + 19,05j \, \\text{A}
\]

#### Corrente \( I_3 \)
Analogamente:
\[
I_3 = I_1 \\cdot e^{j \\frac{2\\pi}{3}} \approx -5,5 - 19,05j \, \\text{A}
\]

### Riassunto delle correnti
- \( I_1 = 11 - 11j \, \\text{A} \)
- \( I_2 \\approx -5,5 + 19,05j \, \\text{A} \)
- \( I_3 \\approx -5,5 - 19,05j \, \\text{A} \)

## Calcolo della Potenza misurata dal Wattmetro
La potenza misurata dal wattmetro in un sistema trifase simmetrico è data da:
\[
P = \\sqrt{3} \\cdot V_{12} \\cdot I \\cdot \\cos(\\phi)
\]
dove:
- \( V_{12} = 220 \\sqrt{3} \, \\text{V} \)
- \( I = \\sqrt{11^2 + 11^2} \\approx 15.56 \, \\text{A} \)
- Il fattore di potenza è \( \\cos(\\phi) = \\frac{1}{\\sqrt{2}} \\approx 0.707 \)

### Calcolo della Potenza
\[
P = \\sqrt{3} \\cdot 220 \\sqrt{3} \\cdot 15.56 \\cdot 0.707 \\approx 9680 \, \\text{W}
\]
Pertanto, la potenza misurata dal wattmetro è:
\[
P \\approx 9680 \, \\text{W}
\]
"""
