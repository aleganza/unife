#

// GENERALI
int fork(void) -> crea processo
    ritorna:
        - 0 al processo
        - PID del processo al padre che è <0 in caso di errore

void exit(int status) -> terminazione processo
    lo status è usato per comunicare qualcosa al padre

int wait(int *status) sospensione in attesa terminazione figli
    ritorna:
        pid del processo terminato, o <0 se errore

getpid() ritorna il pid del processo chiamante

// FILE
int open(char nomefile[], int flag, [int mode]) -> apre file
    flag: (separabili da |)
        O_RDONLY -> accesso in lettura
        O_WRONLY -> accesso in scrittura
        O_APPEND -> accesso in scrittura dalla fine del file, da associare a O_WRONLY
        O_TRUNC -> lunghezza del file troncata a 0, si associa a O_WRONLY
        O_CREAT -> creazione file + accesso in scrittura, (da fornire mode)
    mode:
        bit di protezione in caso di O_CREAT
    ritorna:
        puntatore al file o -1 in errore

int creat(char nomefile[], int mode) -> crea e apre file

int close(int fd) -> chiude file
