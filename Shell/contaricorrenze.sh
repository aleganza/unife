#!/bin/sh
# Lab02 - Es 2

if test $# -lt 2
    then
    echo 'Bisogna inserire almeno 2 parametri'
    exit 1
fi

# il primo argomento deve essere un file
fileName=$1

if test ! -f $1
    then
    echo 'Il primo argomento deve essere un file'
    exit 2
fi

shift

for i
    do
    echo `grep "$i" "$fileName"`
done
