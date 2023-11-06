#!/bin/sh
# Lab03 - Es 1

if test $# -lt 4
then
    echo 'Uso: muoviFile.sh <num> <dirSorgente> <dirDestinazione> <ext1> [...extN]'
    exit 1
fi

num=$1
shift
dirSorgente=$1
shift
dirDestinazione=$1
shift

# controllo num DA RIVEDERE
case $num in
    *[!0-9]*)
        echo "$num non è un intero"
        exit 2;;
esac

# controllo directory
# dirSorgente

case $dirSorgente in
    /*) ;;
    *)
        echo "$dirSorgente non è un nome assoluto di directory"
        exit 3;;
esac

if test ! -d $dirSorgente
then
    echo "$dirSorgente non è un nome valido di directory"
    exit 4;
fi

# dirDestinazione

case $dirDestinazione in
    /*) ;;
    *)
        echo "$dirDestinazione non è un nome assoluto di directory"
        exit 5;;
esac

if test ! -d $dirDestinazione
then
    echo "$dirDestinazione non è un nome valido di directory"
    exit 6;
fi

PATH=$PATH:`pwd`
export PATH

> /tmp/.counter.tmp

for ext in $*
do  
    # controllo estensioni
    case $ext in
        .*) ;;
        *) echo "$ext non è un'estensione valida"
           exit 7;;
    esac
    
    ricerca.sh "$num" "$dirSorgente" "$dirDestinazione" "$ext"
done

echo "File copiati: `wc -l < /tmp/.counter.tmp`"
rm /tmp/.counter.tmp
