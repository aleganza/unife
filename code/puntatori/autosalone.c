/* 
- Definire la struttura automobili che descrivere un’automobile in base alla marca, cilindrata, anno di
    immatricolazione e acquirente con nome e cognome.
- Scriviamo quindi un programma in C, che dichiara una tabella autosalone di tipo automobili con 5 elementi.
- Il programma deve consentire di:
    - inserire i dati delle auto vendute (controlli: cilindrata compresa tra 800 e 2500cc; anno immatricolazione 2000 - 2019
    - effettuare una ricerca sulla base della marca: se si trova una macchina della marca richiesta, stampare a video tutte le info
    - visualizzare il cognome dei proprietari con auto che hanno una cilindrata superiore a 1800 cc
    - visualizzare il numero di auto immatricolate in un determinato anno.
*/

#include <stdio.h>

#define DIM 30

typedef struct {
    char nome[DIM];
    char cognome[DIM];
} acquirente;

typedef struct {
    char marca[DIM];
    int cilindrata;
    int annoImmatricolazione;
    acquirente a;
} automobili;

int main() {
    int scelta;

    do {
        printf ("--- AUTOSALONE ---\n\n");
        printf ("")


    } while (scelta != 0);
    
    printf ("\n");
    return 0;
}