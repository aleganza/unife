#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int fd, fdlog, status, i;
    
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
    close(fd);

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

            sprintf(log, "%s %s\n", argv[1], argv[i]);
            write(fdlog, log, strlen(log));
            close(fd);

            // da fare parte 2
        }
    }

    // padre
    for(i=2; i<argc; i++) {
		wait(&status);
	}

    printf("\n");
    return 0;
}
