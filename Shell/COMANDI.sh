# CONSIGLI
    Sintassi alternativa:
    • invece di test ... → [ ... ]
    • invece di ` ... ` → $( ... )
    AltGr + ì => ~

# PASSAGGIO PARAMETRi
    ./nomefile arg1 arg2 # $0 = /nomefile
                         # $1 = arg1
                         # $2 = arg12
    shift # comando che sposta i parametri verso sinistra (tranne $s0 che rimane fisso), ex dopo shift: $1 => $2 
    set # riassegnamento di parametri
    $* # insieme di tutti gli parametri da $1
    $# # numero di parametri
    $? # valore (int) restituito dall'ultimo comando eseguito (utile per error handling)
    $$ id numerico del processo in esecuzione (pid)

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

# VARIABILI E METACARATTERI
    X=2 # creazione e assegnazione variabile
        echo $X # ex: per far riferimento si usa il $
    expr # le variabili sono tutte string, per fare operazioni si usa questa comando
        `expr $var + 1` # ex: in questo modo $var e 1 vengono considerati come valori
    eval # esegue un'ulteriore sostituzione (quando viene bloccata per esempio da '')
        y=3
        x='$y'
        eval echo $x # ex: stampa 3 (perché valuta $y, altrimenti senza eval avrebbe stampato "$y", cioè il valore di x)
    * # qualunque stringa di >= 0 caratteri in un nome di un file
    ? # qualunque carattere in un nome di un file
    [zfc] # qualunque carattere compreso n\ range dato
        [a-e]* # ex: qualunque file che inizia per a-e
        [a-p,1-7]*[c,f,d]? # ex: qualunque file che inizia per a-p oppure 1-7, il cui penultimo carattere sia c, f, d
    \  # escape, segnala di non interpretare il carattere successivo come speciale
        *\** # ex: qualunque file che contenga il carattere "*"
    '' # proteggono da tutte le espansioni
    "" # proteggono dalle espansioni tranne $, \, `` 
        echo ' * e $y ' # ex: produce * e $y
        echo " * e $y " # ex: produce * e 3
        echo "`pwd`" # ex: stampa nome dir corrente

# STRUTTURE
    # if else
    if <lista-comandi>
        then
            <comandi>
        [elif <lista_comandi>
            then <comandi>]
        [else <comandi>]
    fi

    # switch case
    case <var> in
        <pattern-1>)
            <comandi>;;
        ...
        <pattern-i> | <pattern-j> | <pattern-k>)
            <comandi>;;
        ...
        <pattern-n>)
            <comandi> ;;
    esac

    # ciclo for
    for <var> [in <list>] # list=lista di stringhe
    do
        <comandi>
    done

        # esempi di ciclo for
        for i # cicla per $*
        for i in * # cicla per tutti i file nella cartella corrente
        for i in `cat file` # cicla per ogni parola in file

    # ciclo while
    while <lista-comandi> # occhio! esce quando non è più zero!
    do
        <comandi>
    done

    until <lista-comandi> # come while, ma inverte la condizione
    do
        <comandi>
    done

    # uscite anomale
    exit [status]

    # menu testuale
    select # # capire bene come si usa

# GENERALI
    man comando # informazioni sul comando in questione
    echo <stringa> # stampa
    test -<opzioni> <nomefile> # valutazione di un'espressione
        valore zero ➔ true
        valore non-zero ➔ false
        -f <file> # esistenza di file
        -d <file> # esistenza di cartelle
        -r <file> # dirito di lettura su file (-w e -x)
        test <stringa1> = <stringa2> # uguaglianza stringhe (spazi tra = necessari!)
        test <stringa1> != <stringa2> # diversità stringhe (spazi tra != necessari!)
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
    cut [-options] <file> # seleziona parti di una stringa o di righe di file
        -c # seleziona i caratteri nelle posizioni specificate
        -f # divide la stringa in più campi e seleziona il campo
        -d # usato con -f, comunica il carattere da cui dividere
            echo $s | cut -f 2 -d `,` # ex: prende la seconda parte della stringa divisa per ,
    tr [-options] # sostituisce caratteri di una stringa o di righe di file con un altro carattere (anche più caratteri)
        echo $str | tr ",:" " ," # ex: sotituisce "," con " " e ":" con ","
        -d # rimuove direttamente il/i carattere/i
    seq <sequenzanumeri> # stampa sequenze di numeri
    find # cerca file con un certo criterio PRENDERE SA SLIDE COME SI USA
    diff <file1> <file2> # mostra righe diverse tra due file
    wc # WORD COUNT stampa il numero di roba (guardare sotto)
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
        aux # mostra tutti i processi + chi li ha eseguiti
