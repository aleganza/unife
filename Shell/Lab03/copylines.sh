#!/bin/sh
# Lab03 - Es 4

errorMessage='Uso: copylines nome_dir_assoluto stringa nomefile1 nomefile2 ... nomefileN'

if test $# -lt 3
then
    echo $errorMessage
    exit 1
fi

dirAbsolute=$1
shift
string=$1
shift
fileNames=$*

case $dirAbsolute in
    /*) 
        if ! test -d $dirAbsolute
        then
            echo $errorMessage
            exit 2
        fi;;
    *) 
        echo $errorMessage
        exit 3;;
esac

# ops non serve
# case $string in
#     *[!a-z]*) 
#         echo $errorMessage
#         exit 4;;
# esac

> /tmp/.counter.tmp
> /tmp/.lines.tmp

PATH=$PATH:`pwd`
export PATH

copylines_rec.sh "$dirAbsolute" "$string" "$fileNames"


if test `wc -l < /tmp/.counter.tmp` -eq 0
then
    echo 'SPOSTATO NIENTE STOP 1 ORA'
else
    echo "`wc -l < /tmp/.counter.tmp` file spostati."
    echo "Linee:"
    echo `cat /tmp/.lines.tmp`
fi

rm -f /tmp/.counter.tmp
rm -f /tmp/.lines.tmp
