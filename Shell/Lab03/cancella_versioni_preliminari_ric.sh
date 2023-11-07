#!/bin/sh
# Lab03 - Es 3 ric

dirArticoli=$1

> /tmp/.counter.tmp

cd $dirArticoli
for file in `ls *.txt 2>/dev/null`
do
    if test -f $file -a -w $file -a `head -n 1 $file | cut -f 3 -d ','` = "preliminare"
    then
        rm -f $file
        echo $file >> /tmp/.counter.tmp
    fi
done

if test `wc -l < /tmp/.counter.tmp` -gt `wc -l < /tmp/.max_counter.tmp`
then
    cp /tmp/.counter.tmp /tmp/.max_counter.tmp
    echo `pwd > /tmp/.max_dirname.tmp`
fi

rm /tmp/.counter.tmp

for dir in *
do
    if test -d $dir -a -x $dir
    then
        cancella_versioni_preliminari_ric.sh "`pwd`/$dir"
    fi
done
