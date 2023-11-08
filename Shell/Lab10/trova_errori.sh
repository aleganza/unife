#!/bin/sh
# Lab10 - Es 2

if test $# -ne 1
then
    echo 'err 1 parametro'
    exit 1
fi

case $1 in
    /*) if test ! -d $1
        then
            echo 'err no dir'
            exit 2
        fi;;
    *)     
        echo 'err no assoluta'
        exit 3;;
esac

PATH=$PATH:`pwd`
export PATH

ERRORI="/mnt/x/Sistema/Scuola/Informatica/GitHub/UniFe-Programming/Shell/Lab10/errori.txt"
export ERRORI
WARNING="/mnt/x/Sistema/Scuola/Informatica/GitHub/UniFe-Programming/Shell/Lab10/warning.txt"
export WARNING

> /tmp/.max_counter.tmp
> /tmp/.max_dir.tmp

trova_errori_ric.sh $1

echo "Cartella con più file di errore: `cat /tmp/.max_dir.tmp`"

rm /tmp/.max_counter.tmp
rm /tmp/.max_dir.tmp
