ZIP Extractor
ZIP Extractor
Free app for opening and creating ZIP files
ALESSIO
Google Account
arrow_back
Lab11-soluzioni.zip
code Highlight Syntax
skip_previous skip_next close
code
Lab11-2010-06-08-trova_vini.c (4 KB)
file_download Download Save to Drive Save to Drive more_vert
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 20
#define N 256

void handler(int s){
	int status;
	wait(&status);
}

int main(int argc, char **argv){
	
	int pid, pid_n1, pid_n2;
	int ncantine, i, j, nread;
	int n1n2[2], n2pi[2], pip0[MAX][2];
	char nome_vino[N], buff[N];
	
	signal(SIGINT, SIG_IGN);
	signal(SIGCHLD, handler);
	
	if (argc < 2) {
		fprintf(stderr, "Uso: ./esame cantina1 ... cantinaN\n");
		exit(1);
	}
	
	ncantine = argc-1;
	if (ncantine > MAX){
		fprintf(stderr, "Inserire al massimo %d cantine!\n", MAX);
		exit(1);
	}
	
	printf("Inserire il vino da cercare:\n");
	scanf("%s", nome_vino);
	
	while (strcmp(nome_vino,"fine")){
		
		for (i = 0; i < ncantine; i++){
			if (pipe(pip0[i]) < 0){
				perror("errore pipe");
				exit(2);
			}
			if ((pid=fork()) < 0){
				perror("errore fork");
				exit(3);
			}
			
			if (pid == 0){
				/* Figlio i-simo */
                
				for (j=0;j<i;j++){
					close(pip0[j][0]);
				}
				
				if (pipe(n1n2) < 0){
					perror("errore pipe 1");
					exit(4);
				}
				if (pipe(n2pi) < 0){
					perror("errore pipe 2");
					exit(4);
				}
				if ((pid_n1=fork()) < 0){
					perror("errore fork nipote 1");
					exit(5);
				}
				if (pid_n1 == 0){ 
					/* Primo nipote N1 –
					esegue grep "disponibile" */
					
					close(pip0[i][0]);
					close(pip0[i][1]);

					close(n2pi[0]);
					close(n2pi[1]);
					
					close(1);
					dup(n1n2[1]);
					
					close(n1n2[1]);
					close(n1n2[0]);
					execlp("grep","grep", "disponibile", argv[i+1], (char*)0);
					perror("errore grep 1");
					exit(6);
				} // fine primo nipote N1
				
				if (pid_n1 > 0){ /* Continuo figlio Pi */
					if ((pid_n2=fork()) < 0){
						perror("errore fork nipote 2");
						exit(5);
					}
					if (pid_n2 == 0){ 
						/* Secondo nipote N2 -
						esegue grep sul nome del vino */
						
						close(pip0[i][0]);
						close(pip0[i][1]);
	
						close(0);
						dup(n1n2[0]);
						
						close(n1n2[0]);
						close(n1n2[1]);
						
						close(1);
						dup(n2pi[1]);
						
						close(n2pi[1]);
						close(n2pi[0]);
						
						execlp("grep","grep", nome_vino, (char*)0);
						perror("errore grep 2");
						exit(7);
					} // fine secondo nipote N2
					
					if (pid_n2 > 0){ 
						/* Continuo figlio Pi */
						
						/* Chiudo pipe usate solo dai due nipoti */
						close(n1n2[0]);
						close(n1n2[1]);
						
						/* Ridirezione stdout verso il padre */
						close(1);
						dup(pip0[i][1]);
						close(pip0[i][0]);
						close(pip0[i][1]);
						
						/* Redireziono lo stdin in lettura
						dal secondo nipote */
						close(0);
						dup(n2pi[0]);
						close(n2pi[0]);
						close(n2pi[1]);
						
						// qui termina il figlio i-esimo
						execlp("sort","sort","-n",(char*)0);
						perror("errore sort");
						exit(8);
					}
				}
			} // fine codice figlio i-esimo
			
			if (pid > 0){ 
				/* Padre */
				close(pip0[i][1]);
			}
			
		} // fine for
		
		/* P0 */
		
		/* Mi metto in attesa delle risposte dei figli e le stampo a video */
		for (i = 0; i < ncantine; i++) {
			printf("%s:\n", argv[i+1]);
			while (( nread = read(pip0[i][0],buff,N-1) ) > 0){
				write(1,buff,nread);
			}
			close(pip0[i][0]);
		}
		
		/* Inizio un nuovo ciclo */
		printf("Inserire il vino da cercare:\n");
		scanf("%s", nome_vino);
		
	} // fine while
	
	return 0;
}