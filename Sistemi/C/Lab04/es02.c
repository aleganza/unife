#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int fdlog, status, i;
    
    // controllo argomenti
    if(argc < 3) {
        fprintf(stderr, "Usage: ./a.out <nomefile> <stringa1> ... <stringaN>");
        exit(1);
    }

    // creo, se non esiste, file conteggi (non è richiesto nella consegna ma vabbè)
    fdlog = open("conteggi.txt", O_WRONLY | O_TRUNC | O_CREAT);
    if(fdlog < 0) {
        fprintf(stderr, "Errore opening file \"conteggi.txt\"");
        exit(2);
    }
    close(fdlog);

    // algoritmo
    for(i=2; i<argc; i++) {
        int pid = fork();

        if(pid < 0) {
            perror("fork");
            exit(3);
        } else if(pid == 0) {
            // figlio
            char log[256];
            fdlog = open("conteggi.txt", O_WRONLY | O_APPEND);

            // parte 1
            sprintf(log, "%s %s\n", argv[1], argv[i]);
            write(fdlog, log, strlen(log));
            close(fdlog);

            // parte 2
            printf("\nNum di righe in cui compare la stringa %s:\n", argv[i]);

            execlp("grep", "grep", "-c", argv[i], argv[1], (char *)0);
            perror("grep");
            exit(4);
        } else {
            // padre
            wait(&status);
        }
    }

    printf("\n");
    return 0;
}
