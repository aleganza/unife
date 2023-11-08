#!/bin/sh

if test $# -ne 3
then
    echo 'err 3 parametro'
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

> /tmp/.maxRicambi.tmp
echo 0 > /tmp/.maxRicambi.tmp
> /tmp/.miglioreFornitore.tmp

trova_fornitori_migliori_ric.sh $1 $2 $3

echo "`cat /tmp/.miglioreFornitore.tmp` con `cat /tmp/.maxRicambi.tmp`"

rm /tmp/.maxRicambi.tmp
rm /tmp/.miglioreFornitore.tmp