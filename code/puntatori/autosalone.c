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
#include <string.h>

#define SLEN 30
#define DIM 5

typedef struct {
    char nome[SLEN];
    char cognome[SLEN];
} acquirente;

typedef struct {
    char marca[SLEN];
    int cilindrata;
    int annoImmatricolazione;
    acquirente acq;
} automobili;

void inserisciVetture(automobili *s) {
    for (int i=0; i<DIM; i++) {
        printf ("Inserire nome del proprietario: ");
        scanf ("%s", s[i].acq.nome);

        printf ("Inserire cognome del proprietario: ");
        scanf ("%s", s[i].acq.cognome);
        
        printf ("Inserire marca della vettura: ");
        scanf ("%s", s[i].marca);
        
        do {
            printf ("Inserire cilindrata della vettura: ");
            scanf ("%d", &s[i].cilindrata);
        } while (s[i].cilindrata < 800 || s[i].cilindrata > 2500);
        
        do {
            printf ("Inserire anno di immatricolazione della vettura: ");
            scanf ("%d", &s[i].annoImmatricolazione);
        } while (s[i].annoImmatricolazione < 2000 || s[i].annoImmatricolazione > 2019);

        printf ("\n");
    }
}

// void stampaTutto(automobili *s) {
//     for (int i=0; i<DIM; i++) {
//         printf ("%s\n", s[i].acq.nome);
//         printf ("%s\n", s[i].acq.cognome);
//         printf ("%s\n", s[i].marca);
//         printf ("%d\n", s[i].cilindrata);
//         printf ("%d\n", s[i].annoImmatricolazione);
//         printf ("\n");
//     }
// }

void stampaInfo(automobili *s, int index) {
    printf ("%s\n", s[index].acq.nome);
    printf ("%s\n", s[index].acq.cognome);
    printf ("%s\n", s[index].marca);
    printf ("%d\n", s[index].cilindrata);
    printf ("%d\n", s[index].annoImmatricolazione);
    printf ("\n");
}

void ricercaMarca(automobili *s, char* marca) {
    int cnt = 0;

    printf ("Vetture trovate:\n\n");

    for (int i=0; i<DIM; i++) {
        if (!strcmp(s[i].marca, marca)) {
            stampaInfo(s, i);
            cnt++;
        }
    }

    // se non trovo nessuna info lo comunico
    if (!cnt) {
        printf ("Nessuna vettura trovata.");
    }
}

// !! Stampa solo il cognome del proprietario !!
void ricercaCilindrata(automobili *s, int *cilindrata) {
    int cnt = 0;

    printf ("Proprietari trovati:\n\n");

    for (int i=0; i<DIM; i++) {
        if (s[i].cilindrata > *cilindrata) {
            printf ("%s\n", s[i].acq.cognome);
            cnt++;
        }
    }

    if (!cnt) {
        printf ("Nessun proprietario trovata.");
    }
}

// !! Stampa il numero di auto !!
void ricercaAnno(automobili *s, int *anno) {
    int cnt;

    for (int i=0; i<DIM; i++) {
        if (s[i].annoImmatricolazione == *anno) {
            cnt++;
        }
    }

    printf ("Sono state trovate %d auto", cnt);
}

int main() {
    automobili autosalone[DIM];
    char marca[SLEN];
    int cilindrata, 
        anno;

    printf ("--- AUTOSALONE ---\n\n");
    printf ("Inserimento vetture:\n");

    inserisciVetture(autosalone);

    printf("Ricerca per marca: ");
    scanf ("%s", &marca);
    ricercaMarca(autosalone, marca);
    
    // printf ("Ricerca per cilindrata");
    // scanf ("%d", &cilindrata);
    cilindrata = 1800;
    ricercaCilindrata(autosalone, &cilindrata);

    printf ("Ricerca per anno: ");
    scanf ("%d", &anno);
    ricercaAnno(autosalone, &anno);
    
    printf ("\n");
    return 0;
}