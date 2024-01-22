#!/bin/sh
# Lab03 - Es 2

# CONTROLLI

if test $# -ne 3
then
    echo 'Uso: cercaFile string dir num'
    exit 1
fi

string=$1
dir=$2
num=$3

case $string in
    *[!a-z]*)
        echo 'argomento $string non è una stringa'
        echo 'Uso: cercaFile string dir num'
        exit 2
esac

case $dir in
    /*) 
        if test ! -d $dir 
        then
            echo 'argomento $dir non è un direttorio esistente'
            echo 'Uso: cercaFile string dir num'
            exit 3;
        fi;;
    *)  echo 'argomento $dir non è un direttorio assoluto'
        echo 'Uso: cercaFile string dir num'
        exit 4;;
esac

case $num in
    *[!0-9]*)
        echo 'argomento $num non è un numero intero'
        echo 'Uso: cercaFile string dir num'
        exit 2
esac

PATH=$PATH:`pwd`
export PATH

> /tmp/.max_counter.tmp
> /tmp/.max_dirname.tmp

cercaStringa.sh "$string" "$dir" "$num"

echo "Il direttorio con più file trovati è `cat /tmp/.max_dirname.tmp` con `wc -l < /tmp/.max_counter.tmp` file trovati"

rm /tmp/.max_counter.tmp
rm /tmp/.max_dirname.tmp
