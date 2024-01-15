#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define PIPE_MAX 20

/* NON VA */
/* NON VA */
/* NON VA */
/* NON VA */
/* NON VA */
/* NON VA */
/* NON VA */
/* NON VA */
/* NON VA */
/* NON VA */

int main(int argc, char** argv) {

    int i, j, fd, status, n_cantine, n_read,
        pid, pid_n1, pid_n2,
        n1n2[2], n2pi[2], pip0[PIPE_MAX][2];
    char vino[100],
         buffer[100];

    // controllo argomenti
    if(argc < 2) {
        fprintf(stderr, "Uso ./trova_vini cantina-1 ... cantina-N");
        exit(1);
    }

    for(i=1; i<argc; i++) {
        if( (fd = open(argv[i], O_RDONLY)) < 0 ) {
            if(errno == ENOENT) {
                fprintf(stderr, "Il file %s non esiste", argv[1]);
                exit(1);
            } else {
                fprintf(stderr, "Impossibile aprire il file %s", argv[1]);
                exit(1);
            }
        }
    }

    // signal(SIGINT, SIG_IGN);

    printf("Inserire nome del vino:\n");
    scanf("%s", vino);

    n_cantine = argc-1;

    if(n_cantine > PIPE_MAX) {
        fprintf(stderr, "n_cantine troppo grande");
        exit(1);
    }

    // while(strcmp(vino, "fine") != 0) {
        // generazione argc-1(n_cantine) processi
        for(i=0; i<n_cantine; i++) {
            if( (pid = fork()) < 0 ) {
                fprintf(stderr, "Errore creazione processo n.%d", i);
                exit(1);
            } else if(pid == 0) {
                if( (pipe(n1n2)) < 0 ) {
                    fprintf(stderr, "Errore pipe n1-n2");
                    exit(1);
                }

                if( (pid_n1 = fork()) < 0) {
                    fprintf(stderr, "Errore processo n1");
                    exit(1);
                } else if(pid_n1 == 0) {
                    // PROCESSO N1 - grep dei disponibili

                    close(n1n2[0]);

                    // redirect stdout
                    close(1);
                    dup(n1n2[1]);
                    close(n1n2[1]);

                    execlp("grep", "grep", "disponibile", argv[i+1], (char*)0);
                    perror("grep1");
                    exit(1);
                }

                if( (pipe(n2pi)) < 0 ) {
                    fprintf(stderr, "Errore pipe n2-pi");
                    exit(1);
                }

                if( (pid_n2 = fork()) < 0) {
                    fprintf(stderr, "Errore processo n2");
                    exit(1);
                } else if(pid_n2 == 0) {
                    // PROCESSO N2 - grep del vino
                    close(n1n2[1]);
                    close(n2pi[0]);

                    // redirect stdin
                    close(0);
                    dup(n1n2[0]);
                    close(n1n2[0]);

                    // redirect stdout
                    close(1);
                    dup(n2pi[1]);
                    close(n2pi[1]);

                    execlp("grep", "grep", vino, (char*)0);
                    perror("grep2");
                    exit(1);
                }

                if( (pipe(pip0[i])) < 0 ) {
                    fprintf(stderr, "Errore pipe p%d-p0", i);
                    exit(1);
                }

                for(j=0; j<i; j++) {
                    close(pip0[j][0]);
                    close(pip0[j][1]);
                }

                wait(&status);
                wait(&status);

                // PROCESSO Pi - sort in base al prezzo

                close(n1n2[0]);
                close(n1n2[1]);
                close(n2pi[1]);
                close(pip0[i][0]);

                // redirect stdin
                close(0);
                dup(n2pi[0]);
                close(n2pi[0]);

                // redirect stdout
                close(1);
                dup(pip0[i][1]);
                close(pip0[i][1]);
                
                execlp("sort", "sort", "-n", (char*)0);
                perror("sort");
                exit(1);
            }
        }

        close(n1n2[0]);
        close(n1n2[1]);
        close(n2pi[0]);
        close(n2pi[1]);

        // P0
        for(i=0; i<n_cantine; i++) {
            close(pip0[i][1]);

            printf("\nciao %d\n", i);

            while( (n_read = read(pip0[i][0], buffer, 100)) > 0 ) {
                
                printf("%s", buffer);
            }

            close(pip0[i][0]);
        }

        printf("Inserire nome del vino (fine per uscire):\n");
        scanf("%s", vino);
    // }

    printf("\n");
    return 0;
}
