// LIBRERIE
#include <fcntl.h> -> flag per apertura file
#include <sys/types.h>
#include <sys/wait.h> -> per usare syscall wait()
#include <dirent.h> -> roba per dir
#include <unistd.h>
#include <errno.h> -> per usare errno
#include <signal.h> -> per usare i segnali

// ROBA
static volatile sig_atomic_t

// GENERALI
char *fgets(char *s, int size, FILE *stream)
    legge una linea dallo stream immagazzinandola nel buffer puntato da s

int atoi(const char *string)
    converte stringa in int
    alternative:
        strtol -> in long int
        strtoul -> in unsigned long int

// PROCESSI
int fork(void) -> crea processo
    ritorna:
        - 0 al processo
        - PID del processo al padre che è <0 in caso di errore

void exit(int status) -> terminazione processo
    lo status è usato per comunicare qualcosa al padre

int wait(int *status) sospensione in attesa terminazione figli
    ritorna:
        pid del processo terminato, o <0 se errore

int getpid() ritorna il pid del processo chiamante

// SEGNALI
int kill(pid_t pid, int sig)
    pid è l identificatore del processo a cui si vuole inviare il segnale
    sig è il segnale che si vuole inviare

// impostazione sigaction
struct sigaction sa;
sigemptyset(&sa.sa_mask);
sa.sa_flags = 0;
sa.sa_handler = sighandlerUSR1;
if(sigaction(SIGURS1, &sa, NULL) < 0) {
    perror("sigaction")
    exit(3);
}

pause()
    il processo attende un segnale, quando arriva gestisce
    l handler e poi si mette ancora in attesa 

// segnali
#define SIGHUP 1 /* Hangup (POSIX). Action: exit */
#define SIGINT 2 /* Interrupt (ANSI). Action: exit */
#define SIGQUIT 3 /* Quit (POSIX). Action: exit, core dump */
#define SIGILL 4 /* Illegal instr (ANSI). Action: exit,
core dump */
...
#define SIGKILL 9 /* Kill, unblockable (POSIX). Action: exit */
#define SIGUSR1 10 /* User-def sig1 (POSIX). Action: exit */
#define SIGSEGV 11 /* Segm. violation (ANSI). Action: exit, core
dump */
#define SIGUSR2 12 /* User-def sig2 (POSIX). Action: exit */
#define SIGPIPE 13 /* Broken pipe (POSIX). Action: exit */
#define SIGALRM 14 /* Alarm clock (POSIX). Action: exit */
#define SIGTERM 15 /* Termination (ANSI). Action: exit */
...
#define SIGCHLD 17 /* Chld stat changed (POSIX). Action: ignore */
#define SIGCONT 18 /* Continue (POSIX). Action ignore */
#define SIGSTOP 19 /* Stop, unblockable (POSIX). Action: stop *#include */

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

// esistenza
if(errno == ENOENT) {
    printf("Il file non esiste %s", nome);
    exit();
}
