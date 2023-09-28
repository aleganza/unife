// occorrenze in una stringa tramite argc e argv

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int alphLen = strlen(alphabet);
    int cnt = 0;

    // ciclo gli argv
    for (int i=1; i<argc; i++) {
        printf ("Occorrenze in %s:\n", argv[i]);

        int len = strlen(argv[i]);

        // ciclo la parola per ogni lettera dell'alfabeto
        for (int j=0; j<alphLen; j++) {
            for (int k=0; k<len; k++) {
                if (alphabet[j] == argv[i][k]) 
                    cnt++;
            }

            // stamp se ce n'è almeno una
            if (cnt) {
                printf ("%c: %d\n", alphabet[j], cnt);
                cnt = 0;
            }
        }

        printf ("\n");
    }
    
    return 0;
}