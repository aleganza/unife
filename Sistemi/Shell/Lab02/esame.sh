#!/bin/sh
# Lab02 - Es 3

if test $# -ne 3
then
    echo 'Uso: esame.sh <estensione> <dirSearch> <dirDestination>'
    exit 1
fi

ext=$1
dirSearch=$2
dirDestination=$3

# RIVEDERE
case $ext in
    .*) ;;
    *) 
        echo "Estensione non valida"
        exit 2;;
esac

# RIFARE CON METODO FIGO LOOP
case $dirSearch in
    /*) ;;
    *) echo "Il secondo argomento ($dirSearch) deve essere una directory assoluta"
       exit 3;;
esac

case $dirDestination in
    /*) ;;
    *) echo "Il terzo argomento ($dirDestination) deve essere una directory assoluta"
       exit 4;;
esac

if test ! -d $dirSearch
then
    echo "Il secondo argomento ($dirSearch) non è una directory esistente"
    exit 5
fi

if test ! -d $dirDestination
then
    echo "Il terzo argomento ($dirDestination) non è una directory esistente"
    exit 6
fi

PATH=$PATH:`pwd`
export PATH

esame_rec.sh "$ext" "$dirSearch" "$dirDestination"
