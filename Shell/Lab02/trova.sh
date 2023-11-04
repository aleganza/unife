#!/bin/sh
# Lab02 - Es 3

# controlli

if test $# -ne 2
then
    echo 'Inserire due parametri'
    exit 1
fi

dirName=$1
if test ! -d $dirName
then
    echo 'Il primo parametro deve essere una cartella'
    exit 2
fi

# echo `ls $dirName`

fileName=$2
if test ! -f $fileName
then
    echo 'Il secondo parametro deve essere un file'
    exit 3
fi

# verifica se ho i permessi per entrare in una directory
if test ! -x $dirName
then
    # echo 'Non hai i permessi per entrare in questa directory'
    exit 4
fi

# tmp="`pwd`/$i"

# echo $tmp
# PATH=$PATH:`pwd`
# export PATH

# echo $PATH

# echo $dirName
# echo `pwd`
# scorro il path passato alla ricerca di file o cartelle

cd "$dirName"
for i in *
do
# echo "$dirName/$i"
    if test -f $i -a $i = $fileName
    then
        echo "trovato in $dirName"
    elif test -d $i
    then
        # echo "entro in cartella $dirName/$i"
        echo `pwd`
        sh "`pwd`/trova.sh" "$dirName/$i" "$fileName"
    fi
done
