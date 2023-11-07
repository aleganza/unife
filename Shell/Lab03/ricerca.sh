#!/bin/sh
# Lab03 - Es 1 ric

num=$1
dirSorgente=$2
dirDestinazione=$3
ext=$4

cd $dirSorgente
for file in *
do
    if test -d $file
    then
        ricerca.sh "$num" "`pwd`/$file" "$dirDestinazione" "$ext"
    elif test -f $file -a -r $file -a `wc -l < $file` -gt $num
    then
        # controllo estensione giusta
        case $file in
            *$ext)
                cp $file $dirDestinazione
                echo $file >> /tmp/.counter.tmp;;
        esac
    fi
done
