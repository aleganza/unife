#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

static volatile sig_atomic_t cnt = 0;

void handler_sigint() {
    printf("Terminazione. Numero di richieste servite: %d.\n", cnt);
    exit(0);
}

void handler_sigusr1() {}

int main(int argc, char** argv) {

    int fd, n_results, n_read,
        pid1, pid2, pid3,
        p1p2[2], p2p3[2], p3p0[2];
    char user_id[100],
         path_file[1024],
         buffer[100];

    if(argc != 2) {
        fprintf(stderr, "Uso: ./libri_prestati dir");
        exit(1);
    }

    if(argv[1][0] != '/') {
        fprintf(stderr, "%s deve essere un nome assoluto di directory", argv[1]);
        exit(1);
    }

    signal(SIGINT, handler_sigint);

    while(1) {
        printf("Inserire identificativo utente:\n");
        scanf("%s", user_id);

        sprintf(path_file, "%s/%s.txt", argv[1], user_id);

        if((fd = open(path_file, O_RDONLY)) < 0) {
            fprintf(stderr, "Impossibile aprire file %s/%s.txt", argv[1], user_id);
            exit(1);
        }
        close(fd);

        printf("Inserire quanti risultati mostrare:\n");
        scanf("%d", &n_results);

        // PROCESSI

        if(pipe(p1p2) < 0) {
            fprintf(stderr, "Errore pipe p1->p2");
            exit(1);
        }

        if((pid1 = fork()) < 0) {
            fprintf(stderr, "Errore p1");
            exit(1);
        } else if (pid1 == 0) {
            // P1

            // gestisco segnali
            signal(SIGINT, handler_sigint);
            signal(SIGUSR1, handler_sigusr1);

            pause();

            close(p1p2[0]);

            // metto risultato del sort in p1p2
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("sort", "sort", "-n", path_file, (char*)0);
            perror("sort");
            exit(1);
        }

        if(pipe(p2p3) < 0) {
            fprintf(stderr, "Errore pipe p2->p3");
            exit(1);
        }

        if((pid2 = fork()) < 0) {
            fprintf(stderr, "Errore p2");
            exit(1);
        } else if (pid2 == 0) {
            // P2

            // gestisco segnale
            signal(SIGINT, handler_sigint);

            close(p1p2[1]);
            close(p2p3[0]);

            // prelevo risultato del sort da p1p2
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            // metto risultato del grep in p2p3
            close(1);
            dup(p2p3[1]);
            close(p2p3[1]);

            execlp("grep", "grep", "NON RESTITUITO", (char*)0);
            perror("grep");
            exit(1);
        }

        close(p1p2[0]);
        close(p1p2[1]);

        if(pipe(p3p0) < 0) {
            fprintf(stderr, "Errore pipe p3->p0");
            exit(1);
        }

        if((pid3 = fork()) < 0) {
            fprintf(stderr, "Errore p3");
            exit(1);
        } else if (pid3 == 0) {
            // P3

            // gestisco segnale
            signal(SIGINT, handler_sigint);

            close(p2p3[1]);
            close(p3p0[0]);

            // prelevo risultato del grep da p2p3
            close(0);
            dup(p2p3[0]);
            close(p2p3[0]);

            // metto risultato del head in p3p0
            close(1);
            dup(p3p0[1]);
            close(p3p0[1]);

            char n_str[10];
            sprintf(n_str, "%d", n_results);

            execlp("head", "head", "-n", n_str, (char*)0);
            // execlp("head", "head", "-n", n_results, (char*)0);
            perror("head");
            exit(1);
        }

        close(p2p3[0]);
        close(p2p3[1]);
        close(p3p0[1]);

        kill(pid1, SIGUSR1);

        // padre
        wait(NULL);
        wait(NULL);
        wait(NULL);

        while((n_read = read(p3p0[0], buffer, strlen(buffer))) > 0) {
            buffer[n_read] = '\0';
            printf("%s", buffer);
        }

        cnt++;
    }

    printf("\n");
    return 0;
}
