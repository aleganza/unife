#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

static volatile sig_atomic_t cnt = 0;
static volatile sig_atomic_t child_index;
static volatile sig_atomic_t nChildren;
static volatile sig_atomic_t fine = 0;

void gestore_sigint(int signo) {
    printf("Terminazione figlio\n");
    exit(0);
}

void gestore_sigusr1(int signo) {
    cnt++;
    printf("Incremento cnt per %d\n", child_index);
    printf("%d ha ora cnt: %d\n", child_index, cnt);
}

void gestore_sigusr2(int signo) {
    cnt--;
    printf("Decremento cnt per %d\n", child_index);
    printf("%d ha ora cnt: %d\n", child_index, cnt);
}

void gestore_sigint_padre(int signo) {
    printf("Ricevuto CTRL-C --> Attendo sincronizzazione con i children...\n");
    int status; 
    for(int i = 0; i < nChildren; i++){
        wait(&status);
    }
    
    printf("Tutti i children terminati, chiudo il programma\n");
    fine = 1;
}

int main(int argc, char** argv) {

    int i, status;
    srand(time(NULL));
    
    if(argc != 2) {
        printf("Uso: ./figlicounter <Nf>");
        exit(1);
    }

    int Nf = atoi(argv[1]);
    if(Nf <= 0) {
        printf("<Nf> dev'essere un intero positivo maggiore di 0"),
        exit(2);
    }

    nChildren = Nf;

    int *pid = (int*)malloc(Nf * sizeof(int));

    for(i=0; i<Nf; i++) {
        pid[i] = fork();

        if(pid[i] < 0) {
            perror("fork");
            exit(3);
        } else if (pid[i] == 0) {
            // figlio
            child_index = i;

            struct sigaction sigint;
            sigemptyset(&sigint.sa_mask);
            sigint.sa_flags = 0;
            sigint.sa_handler = gestore_sigint;
            if(sigaction(SIGINT, &sigint, NULL) < 0) {
                perror("sigaction");
                exit(4);
            }

            struct sigaction sigusr1;
            sigemptyset(&sigusr1.sa_mask);
            sigusr1.sa_flags = 0;
            sigusr1.sa_handler = gestore_sigusr1;
            if(sigaction(SIGUSR1, &sigusr1, NULL) < 0) {
                perror("sigaction");
                exit(4);
            }

            struct sigaction sigusr2;
            sigemptyset(&sigusr2.sa_mask);
            sigusr2.sa_flags = 0;
            sigusr2.sa_handler = gestore_sigusr2;
            if(sigaction(SIGUSR2, &sigusr2, NULL) < 0) {
                perror("sigaction");
                exit(5);
            }

            while(1) {
                pause();
            }
        }
    }

    // padre

    struct sigaction sigint_padre;
    sigemptyset(&sigint_padre.sa_mask);
    sigint_padre.sa_flags = 0;
    sigint_padre.sa_handler = gestore_sigint_padre;
    if(sigaction(SIGINT, &sigint_padre, NULL) < 0) {
        perror("sigaction");
        exit(4);
    }

    while(!fine) {
        int randomChild = rand() % nChildren;
        int randomSignal = rand() % 2 == 0 ? SIGUSR1 : SIGUSR2;

        kill(pid[randomChild], randomSignal);
        sleep(2);
    }

    free(pid);

    return 0;
}