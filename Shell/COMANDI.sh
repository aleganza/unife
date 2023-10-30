# CONSIGLI
    Sintassi alternativa:
    • invece di test ... → [ ... ]
    • invece di ` ... ` → $( ... )
    AltGr + ì => ~

# GENERALI
    man comando # informazioni sul comando in questione
    cd ~ # vai alla root delle cartelle
    pwd # mostra PATH assoluta della dir corrente
    sudo comando # comando con amministratore
    sudo -u target comando # target è l'utente che si vuole utilizzare
    ln [-s] # collegamento fisico
    ls # lista roba in dir
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
    chmod # cambia i permessi di un file/cartella
        <user><group><others> <nomefile> # ex 750 file.txt

# FILE
    ln <vecchionome> <nuovonome> # link
    cp <filesorgente> <filedestinazione> # copia file
    mv <vecchionome> <nuovonome> # rinonima sposta file
    rm <nomefile> # cancella file
    cat <nomefile> # stampa contenuto file
    more/less

# GESTIONE
    echo # stampa stringa a video
    sort <nomefile> # elenca righe del file in ordine alfabetico crescente
        -r # decrescente
        -o <nomefileoutput> # stampa il contenuto di sort su altro file
        -n # interpreta le righe del file come numeri
        -k <n> # ordina file secondo n-esima colonna
    diff <file1> <file2> # mostra righe diverse tra due file
    wc # stampa il numero di roba (guardare sotto)
        -l <nomefile> # conta le linee
        -w <nomefile> # conta le parole
        -c <nomefile> # conta i caratteri
    grep <stringa> <nomefile> # stampa righe di un file che contengono una stringa passata
        -c # stampa invece il numero di righe trovate
        -r <stringa> <nomecartella> # lo fa con tutti i file in una cartella
    head # mostra le prime righe di un file
        -n 15 <nomefile> # prime 15 righe
        -c 30 <nomefile> # primi 30 caratteri
    tail # identico ad head ma dal fondo
    time <comando> # cronometra il tempo di esecuzione di un comando
    who # mostra gli utenti collegati al sistema
    man <comando> # helper di sistema
    ps # mostra i processi attivi
