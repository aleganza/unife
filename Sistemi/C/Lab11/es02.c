#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

static volatile sig_atomic_t cnt = 0;

void sigint_handler() {
    printf("Terminazione. Numero di richieste eseguite: %d\n", cnt);

    // zombies
    // wait(&status);
    // wait(&status);

    exit(0);
}

void sigusr1_handler() {}

int main(int argc, char** argv) {

    int fd, n_risultati, status, n_read,
        pid1, pid2,
        p1p2[2], p2p0[2];
    char autore[100],
         genere[100],
         path[200],
         buffer[100],
         n_risultati_str[10];

    if(argc != 2) {
        fprintf(stderr, "Uso: ./cerca <archivio>");
        exit(1);
    }

    if(argv[1][0] != '/') {
        fprintf(stderr, "%s non è un nome assoluto di directory", argv[1]);
        exit(1);
    }

    if( (fd = open(argv[1], O_RDONLY)) < 0 ) {
        if(errno == ENOENT) {
            fprintf(stderr, "La cartella %s non esiste", argv[1]);
            exit(1);
        } else {
            fprintf(stderr, "Impossibile aprire la cartella");
            exit(1);
        }
    }
    close(fd);

    // segnale di interrupt
    signal(SIGINT, sigint_handler);

    printf("Inserire il genere desiderato:\n");
    scanf("%s", genere);

    while(strcmp(genere, "fine") != 0) {
        // controllo se il file genere esiste
        sprintf(path, "%s/%s.txt", argv[1], genere);
        if( open(path, O_RDONLY) < 0 ) {
            if(errno == ENOENT) {
                fprintf(stderr, "Il file %s non esiste", path);
                exit(1);
            } else {
                fprintf(stderr, "Impossibile aprire il file");
                exit(1);
            }     
        }
        close(fd);

        printf("Inserire l'autore:\n");
        scanf("%s", autore);

        printf("Inserire il numero di risultati da visualizzare:\n");
        scanf("%d", &n_risultati);
        if(n_risultati <= 0) {
            fprintf(stderr, "Devi inserire un numero intero positivo di risultati da visualizzare.");
            exit(1);
        }

        if( (pipe(p1p2)) < 0 ) {
            fprintf(stderr, "Errore apertura pipe p1-p2");
            exit(1);        
        }

        // processi
        if( (pid1 = fork()) < 0 ) {
            fprintf(stderr, "Errore creazione processo P1");
            exit(1);
        } else if(pid1 == 0) {
            // P1

            // segnali
            signal(SIGINT, sigint_handler);
            signal(SIGUSR1, sigusr1_handler);

            // pause();

            close(p1p2[0]);

            // redirezione stdout
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("grep", "grep", autore, path, (char*)0);
            perror("grep");
            exit(1);
        }


        if( (pipe(p2p0)) < 0 ) {
            fprintf(stderr, "Errore apertura pipe p2-p0");
            exit(1); 
        }


        if( (pid2 = fork()) < 0 ) {
            fprintf(stderr, "Errore creazione processo P2");
            exit(1);
        } else if(pid2 == 0) {
            // P2

            // segnale di interrupt
            signal(SIGINT, sigint_handler);

            close(p1p2[1]);
            close(p2p0[0]);

            // redirezione stdin
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            // redirezione stdout
            close(1);
            dup(p2p0[1]);
            close(p2p0[1]);

            sprintf(n_risultati_str, "%d", n_risultati);
            execlp("head", "head", "-n", n_risultati_str, (char*)0);
            perror("head");
            exit(1);
        }

        // P0
        close(p1p2[0]);
        close(p1p2[1]);
        close(p2p0[1]);

        kill(pid1, SIGUSR1);

        wait(NULL);
        wait(NULL);

        while( (n_read = read(p2p0[0], buffer, strlen(buffer) + 1)) > 0 ) {
            buffer[n_read] = '\0';
            printf("%s", buffer);
        }
        close(p2p0[0]);

        cnt++;
        // wait(&status);
        // wait(&status);

        // prossima richiesta
        printf("Inserire il genere desiderato (fine per uscire):\n");
        scanf("%s", genere);
    }

    if(!strcmp(genere, "fine")) {

    }

    printf("\n");
    return 0;
}
