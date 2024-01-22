#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

static volatile sig_atomic_t cnt = 0;

void gestore(int signo) {
    printf("Il processo %d ha eseguito %d iterazioni per il segnale %d\n", getpid(), cnt, signo);
    exit(0);
}

int main(int argc, char** argv) {
    
    if(argc != 3) {
        printf("Uso: ./itercounter <num_processi> <num_secondi>");
        exit(1);
    }

    int i, status;
    int Nf = atoi(argv[1]);
    int Nsec = atoi(argv[2]);

    if(Nf <= 0) {
        printf("<num_processi> dev'essere un intero positivo");
        exit(2);
    }

    if(Nsec <= 0) {
        printf("<num_secondi> dev'essere un intero positivo");
        exit(3);
    }

    int *pid = (int *) malloc(Nf * sizeof(int));

    for(i=0; i<Nf; i++) {
        pid[i] = fork();

        if(pid[i] < 0) {
            perror("fork");
            exit(4);
        } else if(pid[i] == 0) {
            // figlio

            struct sigaction sa;
            sigemptyset(&sa.sa_mask);
            sa.sa_flags = 0;
            sa.sa_handler = gestore;
            if(sigaction(SIGUSR1, &sa, NULL) < 0) {
                perror("sigaction");
                exit(5);
            }

            while(1) {
                sleep(1);
                cnt++;
            }
 
        }
    }

    // padre
    sleep(Nsec);
    for(i=0; i<Nf; i++) {
        kill(pid[i], SIGUSR1);
    }

    free(pid);

    for (i = 0; i < Nf; i++) {
        wait(&status);
    }

    return 0;
}