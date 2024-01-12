#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char** argv) {

    typedef int pipe_t[2];

    int i, j, fd, status;
    char nome[1024];
    char nElementi[1024];
    
    if(argc < 2) {
        fprintf(stderr, "Uso: controlla_disponibilita magazzino-1 magazzino-2 ... magazzino-N");
        exit(1);
    }

    // controllo se sono nomi relativi di file
    for(i=1; i<argc; i++) {
        if(argv[i][0] == '/') {
            fprintf(stderr, "%s non è un nome relativo di file", argv[i]);
            exit(2);
        }
    }

    // controllo se i file esistono
    for(i=1; i<argc; i++) {
        fd = open(argv[i], O_RDONLY);
        if(fd < 0) {
            if(errno == ENOENT) {
                fprintf(stderr, "Il file %s non esiste\n ", argv[i]);
                exit(3);
            } else {
                fprintf(stderr, "apertura file\n");
                exit(4);
            }
        }
    }

    int nChildren = argc-1;
    int pid;

    pipe_t* pipes_in = (pipe_t*) malloc(nChildren * sizeof(pipe_t));
    pipe_t* pipes_out = (pipe_t*) malloc(nChildren * sizeof(pipe_t));

for (i = 0; i < (argc - 1); ++i) {
		
		/* Genero le pipe per comunicare con i figli;
		 * ho bisogno esattamente di (argc - 1) pipe e figli */
		if (pipe(pipes_in[i]) < 0) {
			perror("pipes_in");
			exit(2);
		}
		if (pipe(pipes_out[i]) < 0) {
			perror("pipes_out");
			exit(3);
		}
		
		if ((pid = fork()) < 0) {
			perror("fork padre");
			exit(4);
		}
		if (pid == 0) { // Figlio Fi
			/* chiudo le pipe non utilizzate: quelle create dal padre
			 * per i figli precedenti e ancora aperte e quelle create
			 * per il figlio i-esimo, ma al quale non servono.
			 * gli estremi pipes_in[x][0] per x da 0 a i-1 sono
			 * chiusi dal padre dopo avere creato l'x-esimo figlio
			 * e non sono quindi presenti nel figlio i-esimo */
			for (j = 0; j <= i; ++j) {
				close(pipes_in[j][1]);
				close(pipes_out[j][0]);
			}
			
			/* sfrutto il fatto che la read su pipe ritorni con valore 0
			 * quando tutti i processi che la condividono chiudono
			 * il loro estremo in scrittura per quella pipe. */
			while (read(pipes_in[i][0], nome, sizeof(nome)) > 0) {
				/* genero un nipote per contare le righe in cui compare
					* l'elemento selezionato e comunicare al processo padre
					* il risultato. 
					*/
				if ((pid=fork()) < 0) {
					perror("fork figlio");
					exit(3);
				} 
				if (pid == 0) { // Nipote Ni
					/* chiudo la pipe in lettura dal padre, che al nipote non serve */
					close(pipes_in[i][0]);
					
					/* redireziono lo stdout sulla pipe diretta al padre */
					close(1);
					dup(pipes_out[i][1]);
					close(pipes_out[i][1]);
					
					execlp("grep", "grep", "-c", nome, argv[i+1], (char*)0);
					perror("exec nipote");
					exit(4);
				}
				
				/* Figlio Fi: aspetto la terminazione del nipote */
				wait(&status);
			} // fine while figlio Fi
			
			/* Figlio Fi: chiudo le pipe e termino */
			printf("Fine figlio %d\n",i);
			close(pipes_in[i][0]);
			close(pipes_out[i][1]);
			
			free(pipes_in);
			free(pipes_out);
			
			exit(0);
		} // fine figlio Fi
		
		/* chiudo estremità delle pipe non usate dal padre */
		close(pipes_in[i][0]);
		close(pipes_out[i][1]);
	} // fine for padre

    // padre
    printf("Inserire materia prima:\n");
    scanf("%s", nome);

    while(strcmp(nome, "fine") != 0) {
        for(i=0; i<nChildren; i++) {
            if(write(pipes_in[i][1], nome, strlen(nome) + 1) < 0) {  // con +1 tengo conto anche \n
                fprintf(stderr, "Errore invio %s al figlio %d-esimo", nome, i);
                exit(1);
            }
        }
        
        for(i=0; i<nChildren; i++) {
            if((read(pipes_out[i][0], nElementi, strlen(nElementi))) < 0) {
                fprintf(stderr, "Errore ricevimento %s dal figlio %d-esimo", nElementi, i);
                exit(1);
            }

            printf("\nTrovate %d scorte nel magazzino %d-esimo per la materia prima %s", atoi(nElementi), i, nome);
        }

        printf("\nInserire altra materia prima (fine per uscire):\n");
        scanf("%s", nome);
    }

    return 0;
}