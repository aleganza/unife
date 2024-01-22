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
    printf("Terminazione programma. Richieste eseguite: %d\n", cnt);

    // Zombies
	wait(&status);
	wait(&status);

    exit(0);
}

int main(int argc, char** argv) {

    int fd, n_read, status,
        pid1, pid2,
        p1p2[2], p2p0[2];
    char nome_fornitore[50],
         nome_applicazione[50],
         path[100],
         buffer[100];
    
    // controllo argomenti e cartella
    if(argc != 2) {
        fprintf(stderr, "Uso: ./conta_vm dir");
        exit(1);
    }

    // if(argv[1][0] != '/') {
    //     fprintf(stderr, "%s deve essere un nome assoluto di directory", argv[1]);
    //     exit(1);
    // }

    if((fd = open(argv[1], O_RDONLY)) < 0) {
        fprintf(stderr, "Impossibile trovare dir %s", argv[1]);
        exit(1);
    }
    close(fd);
    
    // gestisco sigint per il padre
    signal(SIGINT, sigint_handler);

    // gestione richieste
    printf("Inserire nome fornitore:\n");
    scanf("%s", nome_fornitore);

    while(strcmp(nome_fornitore, "fine") != 0) {
        // controllo esistenza file
        sprintf(path, "%s/%s.txt", argv[1], nome_fornitore);
        if((fd = open(path, O_RDONLY)) < 0) {
            fprintf(stderr, "Impossibile trovare file %s", path);
            exit(1);
        }
        close(fd);

        printf("Inserire nome applicazione:\n");
        scanf("%s", nome_applicazione);

        // apro pipe p1p2
        if(pipe(p1p2) < 0) {
            fprintf(stderr, "Errore pipe p1 -> p2");
            exit(1);
        }

        // processi
        if((pid1 = fork()) < 0) {
            fprintf(stderr, "Errore processo 1");
            exit(1);
        } else if(pid1 == 0) {
            // P1
            // gestisco sigint per P1
            signal(SIGINT, sigint_handler);

            close(p1p2[0]);

            // redirect stdout
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("grep", "grep", nome_applicazione, path, (char*)0);
            perror("grep");
            exit(1);
        }

        // apro pipe p2p0
        if(pipe(p2p0) < 0) {
            fprintf(stderr, "Errore pipe p2 -> p0");
            exit(1);
        }

        if((pid2 = fork()) < 0) {
            fprintf(stderr, "Errore processo 2");
            exit(1);
        } else if(pid2 == 0) {
            // P2
            // gestisco sigint per P2
            signal(SIGINT, sigint_handler);

            close(p1p2[1]);
            close(p2p0[0]);

            // redirect stdin
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            // redirect stdout
            close(1);
            dup(p2p0[1]);
            close(p2p0[1]);

            execlp("grep", "grep", "operativa", "-c", (char*)0);
            perror("grep");
            exit(1);
        }

        // P0
        close(p1p2[0]);
		close(p1p2[1]);
		close(p2p0[1]);

        n_read = read(p2p0[0], buffer, strlen(buffer));
		close(p2p0[0]);
		buffer[n_read] = '\0';

        printf("Trovate %s VM\n", buffer);

        cnt++;
        wait(&status);
        wait(&status);

        // prossima richiesta
        printf("Inserire nome fornitore (fine per uscire):\n");
        scanf("%s", nome_fornitore);
    }

    if(!strcmp(nome_fornitore, "fine")) {
        sigint_handler();
    }
    
    printf("\n");
    return 0;
}
