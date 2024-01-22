#include <stdio.h>

//una struttura o record si fa in questo modo, poi all'interno ci metti quello che vuoi
struct studente
{
    char nome[20];
    char cognome[20];
    int eta;
    float media_voti;
};

//in caso non voglio riscrivere ogni volta "struct studente persona*" perchè sono prigro, posso utilizzare "typedef"

typedef struct studente stud_t; //fatti il typedef, usi solo la parte finale stud_t;

//qua salti la parte del nome della struttura, dato che utilizzerai solamente il nome del tipo: stud2_t
typedef struct {
    char nome[20];
    char cognome[20];
    int eta;
    float media_voti;
} stud2_t;

//posso definire robe già esistenti come altra roba POGGERS
typedef char byte;
typedef short half_word_t;
typedef int word_t;
typedef double_word_t;

int main(){

    int n;

    //determinata una struttura o "record", posso inizializzare QUANTE VARIABILI VOGLIO che si basano sullo struct selezionato (in questo caso "studente")
    struct studente persona;  
    struct studente persona2 = {"Matteo", "Besutti", 17, 7.8};

    //in questo caso verrà inizializzato un record dedicata solamente a "persona 3"
    struct{
        char nome[20];
        char cognome[20];
        int eta;
        float media_voti;
    } persona3 = {"Pietro", "Rossi", 16, 6};

    stud2_t studente4;

    stud_t persona5;
    

    return 0;
}
