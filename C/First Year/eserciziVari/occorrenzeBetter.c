// occorrenze in una stringa tramite argc e argv, ma better

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int cnt = 0;
    char tmp;

    // ciclo gli argv
    for (int i=1; i<argc; i++) {
        printf ("Occorrenze in %s:\n", argv[i]); // leoiexeù

        int len = strlen(argv[i]);
        
        // ciclo la parola
        for (int j=0; j<len; j++) {
            if (argv[i][j] != '-'){
                // cerco la lettera
                for (int k=j; k<len; k++) {
                    // salvo la lettera da controllare
                    if (k == j)
                        tmp = argv[i][j];

                    // se trovo la lettera aumento e rimuovo la lettera
                    if (argv[i][k] == tmp) {
                        cnt++;
                        argv[i][k] = '-';
                    }
                }
                printf ("%c: %d\n", tmp, cnt);
            }
            cnt = 0;
        }
        printf ("\n");
    }
    
    return 0;
}