#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

static volatile sig_atomic_t cnt = 0;

void sigint_handler () {
    printf("Terminazione. Numero di richieste soddisfatte: %d\n", cnt);
    exit(0);
}

int main(int argc, char** argv) {

    int fd, status, n_read,
        pid1, pid2,
        p1p2[2], p2p0[2];
    char argomento[100],
         data[100],
         path[200],
         buffer[100];

    if(argc != 2) {
        fprintf(stderr, "Uso: ./trova_news dir");
        exit(1);
    }

    // if(argv[1][0] != '/') {
    //     fprintf(stderr, "Dir deve essere assoluta");
    //     exit(1);
    // }

    if( (fd = open(argv[1], O_DIRECTORY)) < 0 ) {
        fprintf(stderr, "Dir non esiste");
        exit(1);
    }
    close(fd);

    signal(SIGINT, sigint_handler);

    printf("Inserire data notizia:\n");
    scanf("%s", data);

    while(strcmp(data, "fine") != 0) {
        sprintf(path, "%s/%s.txt", argv[1], data);
        if( (fd = open(path, O_RDONLY)) < 0) {
            if(errno = ENOENT) {
                fprintf(stderr, "%s non esiste", path);
                exit(1);
            } else {
                fprintf(stderr, "Impossibile aprire %s", path);
                exit(1);
            }
        }

        printf("Inserire argomento notizia:\n");
        scanf("%s", argomento);

        if( (pipe(p1p2)) < 0 ) {
            fprintf(stderr, "Errore creazione pipe p1p2");
            exit(1);
        }

        if( (pid1 = fork()) < 0 ) {
            fprintf(stderr, "Errore creazione processo 1");
            exit(1);
        } else if(pid1 == 0) {
            // P1
            close(p1p2[0]);

            // redirect stdout
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("grep", "grep", argomento, path, (char*)0);
            perror("grep");
            exit(1);
        }

        if( (pipe(p2p0)) < 0 ) {
            fprintf(stderr, "Errore creazione pipe p2p0");
            exit(1);
        }

        if( (pid2 = fork()) < 0 ) {
            fprintf(stderr, "Errore creazione processo 2");
            exit(1);
        } else if(pid2 == 0) {
            // P2
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

            execlp("sort", "sort", "-n", "-r", (char*)0);
            perror("sort");
            exit(1);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        close(p2p0[1]);

        while( (n_read = read(p2p0[0], buffer, 100)) > 0 ) {
            printf("%s\n", buffer);
        }

        wait(&status);
        wait(&status);

        cnt++;

        printf("Inserire data notizia (fine per uscire):\n");
        scanf("%s", data);
    }

    printf("\n");
    return 0;
}
