
#se ci sono < 4 argomenti -> ERRORE!
if test $# -lt 4
then
    echo errore
    exit 1
fi

case $1 in
    *[!0-9]*) 
        echo num deve essere un numero
        exit 2;;
esac

num=$1
shift # shifto gli argomenti (il 2 va nell' 1)

case $1 in
    /*) if test ! -d $1 # test ritorna -f con file e -d con directory
    