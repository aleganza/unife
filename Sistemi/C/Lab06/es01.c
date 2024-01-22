#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char** argv) {

    int p1p2[2];
    int fd, pid1, pid2, status;
    char matricola[1024];
    
    if(argc != 2) {
        printf("Uso: controlla_esami <file_dati>");
        exit(1);
    }

    if(argv[1][0] != '/') {
        printf("%s non è un nome assoluto di file", argv[1]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        if(errno == ENOENT) {
            printf("Il file non esiste %s", argv[1]);
            exit(2);
        } else {
            perror("file");
            exit(3);
        }
    }
    close(fd);

    printf("Inserisci un numero di matricola:\n"),
    scanf("%s", matricola);

    while(strcmp(matricola, "fine") != 0) {
        if(pipe(p1p2) < 0){
            perror("pipe p1-p2");
            exit(4);
        }

        //figlio 1
        pid1 = fork();
        if(pid1 < 0) {
            perror("fork");
            exit(4);
        } else if (pid1 == 0) {
            // il figlio 1 manda l'output della grep al figlio 2
            close(p1p2[0]);
            
            // redirect stdout
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("grep", "grep", matricola, argv[1], (char*)0);
            perror("grep");
            exit(5);
            
        }

        //figlio 2
        pid2 = fork();
        if(pid2 < 0) {
            perror("fork");
            exit(4);
        } else if (pid2 == 0) {
            // il figlio 2 preleva l'output della grep da figlio 1 e lo da in input a wc -l
            close(p1p2[1]);

            // redirect stdin
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            execlp("wc", "wc", "-l", (char*)0);
            perror("wc -l");
            exit(5);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        
        // padre (aspetto i 2 figli)
        wait(&status);
        wait(&status);

        printf("Inserisci un altro numero di matricola (fine per uscire):\n"),
        scanf("%s", matricola);
    }

    return 0;
}
