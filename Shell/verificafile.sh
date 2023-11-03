#!/bin/sh
# Lab02 - Es 1

echo "Scrivi il nome del file"
read nome

while test $nome != 'fine'
    do
    if test -f "$nome"
        then
        echo "$nome è un file"
    elif test -d "$nome"
        then
        echo "$nome è un direttorio"
    else
        echo "$nome inesistente"
    fi

    echo "Scrivi il nome del file"
    read nome
done

