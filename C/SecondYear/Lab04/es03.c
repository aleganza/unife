#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char** argv) {
    int fd, num, pid, status;
    char nome[1024];

    if(argc != 2) {
        printf("Uso: anteprima <num>");
        exit(1);
    }

    if((num = atoi(argv[1])) <= 0) {
        printf("Il secondo argoment0 dev'essere un intero maggiore di 0");
        exit(2);
    } 

    printf("Inserire il nome di un file di cui si vuole l'anteprima: \n");
    scanf("%s", nome);
    
    while(strcmp(nome, "fine") != 0) {
        fd = open(nome, O_RDONLY);
        if (fd < 0) {
            
            if(errno == ENOENT) {
                printf("Il file non esiste %s", nome);
                exit(3);
            } else {
                perror("open");
                exit(4);
            }
        } else {
            close(fd);
            pid = fork();

            if(pid < 0) {
                perror("fork");
                exit(5);
            } else if (pid == 0) {
                printf("\nPrime %d righe di %s:\n", num, nome);
                execlp("head", "head", "-n", argv[1], nome, (char *)0);

                perror("exec");
				exit(5);
            }

            wait(&status);
        }
        printf("Inserire il nome di un altro file (uscita digitando fine): ");
        scanf("%s", nome);
    }

    return 0;
}
