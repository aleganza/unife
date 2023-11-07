#!/bin/sh
# Lab03 - Es 3

errorMessage="Uso: cancella_versioni_preliminari dir_articoli"

dirArticoli=$1

if test $# -ne 1
then
    echo $errorMessage
    exit 1
fi

PATH=$PATH:`pwd`
export PATH

> /tmp/.max_counter.tmp
> /tmp/.max_dirname.tmp

cancella_versioni_preliminari_ric.sh "$dirArticoli"

echo `cat /tmp/.max_dirname.tmp`

rm /tmp/.max_counter.tmp
rm /tmp/.max_dirname.tmp
