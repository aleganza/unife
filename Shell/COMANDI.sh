# CONSIGLI
    Sintassi alternativa:
    • invece di test ... → [ ... ]
    • invece di ` ... ` → $( ... )
    AltGr + ì => ~

# COSTANTI GLOBALI
    BASH=/usr/bin/bash
    HOME=/space/home/wwwlia/www
    PATH=/usr/local/bin:/usr/bin:/bin
    PPID=7497
    PWD=/home/Staff/CarloGiannelli
    SHELL=/usr/bin/bash
    TERM=xterm
    UID=1015
    USER=cgiannelli

# VARIABILI
    X=2 # creazione e assegnazione variabile
        echo $X # ex: per far riferimento si usa il $

# METACARATTERI
    * # qualunque stringa di >= 0 caratteri in un nome di un file
    ? # qualunque carattere in un nome di un file
    [zfc] # qualunque carattere compreso nel range dato
        [a-e]* # ex: qualunque file che inizia per a-e
        [a-p,1-7]*[c,f,d]? # ex: qualunque file che inizia per a-p oppure 1-7, il cui penultimo carattere sia c, f, d
    \  # escape, segnala di non interpretare il carattere successivo come speciale
        *\** # ex: qualunque file che contenga il carattere "*"

# GENERALI
    man comando # informazioni sul comando in questione
    echo <stringa> # stampa
    cd ~ # vai alla root delle cartelle
    pwd # mostra PATH assoluta della dir corrente
    sudo comando # comando con amministratore
    sudo -u target comando # target è l'utente che si vuole utilizzare
    <comando> < <file> # legge input da file per il comando
    <comando> > <file> # sovrascrive il file con ciò che stampa il comando
    <comando> >> <file> # non sovrascrive ma aggiunge
    ln [-s] # collegamento fisico
    ls # lista roba in dir
        -p # aggiunge "/" alle cartelle
        -l # più info (anche permessi)
        -t # ordina per data
        -r # ordine invertito
        -a # mostra anche file nascosti
        -F # indica anche il tipo di file

# CARTELLE
    mkdir # crea cartella
    rmdir # elimina cartella
    cd # cambia cartella
    pwd # stampa cartella corrente
    ls [<dir>] # visualizza contenuto cartella
        / # root
    chmod [u g o] [+ -] [rwx] <file> # cambia i permessi di un file/cartella
        <user><group><others> <file> # in binario, ex 750 file.txt

# FILE
    ln <vecchionome> <nuovonome> # link
    cp <filesorgente> <filedestinazione> # copia file
    mv <vecchionome> <nuovonome> # rinonima / sposta file
    rm <file> # cancella file
    cat <file> # stampa contenuto file
    more/less

# GESTIONE
    echo # stampa stringa a video
    sort <file> # elenca righe del file in ordine alfabetico crescente
        -r # decrescente
        -o <fileoutput> # stampa il contenuto di sort su altro file
        -n # interpreta le righe del file come numeri
        -k <n> # ordina file secondo n-esima colonna
    rev <file> # inverte l'ordine delle linne di un file
    cut [-options] <file> # seleziona colonne da file
    diff <file1> <file2> # mostra righe diverse tra due file
    wc # stampa il numero di roba (guardare sotto)
        -l <file> # conta le linee
        -w <file> # conta le parole
        -c <file> # conta i caratteri
    grep <stringa> <file> # stampa righe di un file che contengono una stringa passata (ricerca di testo)
        -c # stampa invece il numero di righe trovate
        -r <stringa> <nomecartella> # lo fa con tutti i file in una cartella
    tee <file> # scrive l'input sia su output, che su un file passato
        -a # aggiunge al file, non sovrascrive
    head # mostra le prime righe di un file
        -n 15 <file> # prime 15 righe
        -c 30 <file> # primi 30 caratteri
    tail # identico ad head ma dal fondo
    time <comando> # cronometra il tempo di esecuzione di un comando
    who # mostra gli utenti collegati al sistema
    man <comando> # helper di sistema
    ps # mostra i processi attivi
        a # mostra i processi anche di altri utenti
        u # fornisce nome dell'utente che lo ha lanciato + ora di esecuzione
        x # mostra anche i processi "demoni" (senza terminale di controllo)
        aux # mostra tutti i procesi + chi li ha aperti
