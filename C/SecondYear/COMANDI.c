// LIBRERIE
<fcntl.h> -> flag per apertura file
<sys/types.h>
<dirent.h> -> roba per dir
<unistd.h>

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

int read(int fd, char *buf, int n) -> legge file

int write(int fd, char *buf, int n) -> scrive file

int lseek(int fd, int offset, int origine) -> sposta puntatore nel file
    fd: file descriptor
    offset: spostamento in byte rispetto all origine
    origine: 
        0: inizio file, (SEEK_SET)
        1: posizione corrente, (SEEK_CUR)
        2: fine file, (SEEK_END)

int unlink(char *name) -> cancellare file

int link(char *oldname, char *newname) -> incrementa link al file
    oldname: nome del file esistente
    newname: nome associato al nuovo link

int chmod (char *pathname, char *newmode) -> modifica bit protezione di file
    pathname: nome del file
    newmode: contiene i nuovi diritti

int chown (char *pathname, int owner, int group) -> modifica proprietario e gruppo di file
    pathname: nome del file
    owner: uid del nuovo proprietario
    group: gid del gruppo

int chdir (char *nomedir) -> cambia dir

DIR *opendir (char *nomedir) -> apre dir

int closedir (DIR *dir) -> chiude dir

struct dirent *descr
descr = readdir(DIR *dir) -> legge dir

int mkdir (char *pathname, int mode) -> creazione dir
    pathname: nome del direttorio da creare
    mode: esprime i bit di protezione
