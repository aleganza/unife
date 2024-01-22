#!/bin/sh
# Lab03 - Es 2 ric

string=$1
dir=$2
num=$3

ext='.txt'

> /tmp/.counter.tmp

cd $dir
for file in `ls *.txt 2>/dev/null`
do
    if test -f $file -a -r $file -a `grep -c $string $file` -ge $num
    then
        echo "$file" >> /tmp/.counter.tmp
    fi
done

# controllo max_counter > counter
if test `wc -l < /tmp/.counter.tmp` -gt `wc -l < /tmp/.max_counter.tmp`
then
    cp /tmp/.counter.tmp /tmp/.max_counter.tmp
    echo `pwd` > /tmp/.max_dirname.tmp
fi

rm /tmp/.counter.tmp

for dir in *
do
    if test -d $dir -a -x $dir
    then
        cercaStringa.sh "$string" "`pwd`/$dir" "$num"
    fi
done