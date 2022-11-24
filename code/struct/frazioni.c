// https://drive.google.com/drive/folders/19H3tL0MO8uaWSDiTElxseeJf21TNdiTI
// Strutture, astrazione sui dati, enumerativi, passaggio per riferimento

#include <stdio.h>

typedef struct {
    int num;
    int den;
} Frazione;

// creazione frazione dati numeratore e denominatore (costruttore)
Frazione frazione (int a, int b) {
    Frazione f;
    f.num = a;
    f.den = b;

    return f;
}

// creazione di una frazione
Frazione inputFrazione () {
    Frazione f;

    printf ("Inserisci numeratore: ");
    scanf ("%d", &f.num);
    printf ("Inserisci denominatore: ");
    scanf ("%d", &f.den);

    return f;
}

int vAssoluto (int a) {
    return a < 0 ? -a : a;
}

// massimo comun divisore tra due numeri (metodo di Euclide)
int MCD (int a, int b) {
    a = vAssoluto (a);
    b = vAssoluto (b);
    int resto;

    while (b > 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
        
    return a;
}

// semplifica una frazione ai minimi termini
Frazione semplificaFrazione (int a, int b) {
    Frazione f = frazione (a, b);
    int mcd = MCD (a, b);

    f.num /= mcd;
    f.den /= mcd;

    return f;
}

// stampa di una frazione in formato frazionario
void printFrazionario (int a, int b) {
    Frazione f = frazione (a, b);
    f = semplificaFrazione (f.num, f.den);

    printf ("Stampa frazionaria (minimi termini): ");
    printf ("%d/%d\n", f.num, f.den);
}

// stampa di una frazione in formato decimale
void printDecimale (int a, int b) {
    printf ("Stampa decimale: ");
    printf ("%f\n", (float)a / (float) b);
}

// somma tra due frazioni
void somma (Frazione a, Frazione b) {
    Frazione somma;

    somma.num = a.num * b.den + b.num * a.den;
    somma.den = a.den * b.den;
    
    printFrazionario(somma.num, somma.den);
}

// sottrazione tra due frazioni
void sottrazione (Frazione a, Frazione b) {
    Frazione sottr;

    sottr.num = a.num * b.den - (b.num * a.den);
    sottr.den = a.den * b.den;

    printFrazionario(sottr.num, sottr.den);
}

// moltiplicazione tra due frazioni
void moltiplicazione (Frazione a, Frazione b) {
    Frazione molt;

    molt.num = a.num * b.num;
    molt.den = a.den * b.den;

    printFrazionario(molt.num, molt.den);
}

// divisione tra due frazioni
void divisione (Frazione a, Frazione b) {
    if (a.den != 0 && b.den != 0) {
        Frazione div;

        div.num = a.num * b.den;
        div.den = a.den * b.num;

        printFrazionario(div.num, div.den);
    } else {
        printf ("La divisione non è eseguibile");
    }
}

int main () {
    printf ("Frazione A\n");
    Frazione a = inputFrazione ();
    printf ("Frazione B\n");
    Frazione b = inputFrazione ();

    int scelta;

    do {
        printf ("Che operazione eseguire?\n");
        printf ("1. Somma\n");
        printf ("2. Sottrazione\n");
        printf ("3. Moltiplicazione\n");
        printf ("4. Divisione\n");
        printf ("0. Esci\n");
        printf ("La tua scelta: ");
        scanf ("%d", &scelta);

        switch (scelta) {
            case 1: {
                somma (a, b);
                break;
            }
            case 2: {
                sottrazione (a, b);
                break;
            }
            case 3: {
                moltiplicazione (a, b);
                break;
            }
            case 4: {
                divisione (a,b);
                break;
            }
        }
    } while (scelta != 0);

    printf ("\n");
    return 0;
}