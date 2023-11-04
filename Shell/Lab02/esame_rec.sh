#!/bin/sh

ext=$1
dirSearch=$2
dirDestination=$3

cd $dirSearch

for i in *
do
    if test -d $i
    then
        esame_rec.sh "$ext" "`pwd`/$i" "$dirDestination"
    fi
    case $i in
        *$ext)
            if test ! -f "$dirDestination/$i"
            then
                cp $i $dirDestination
            fi;;
    esac
done
