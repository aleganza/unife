#!/bin/sh

cd $1

for fornitore in `ls *.txt 2>/dev/null`
do
    # se ha il ricambio
    if test -f $fornitore -a -r $fornitore -a `grep -c $2 $fornitore` -gt 0
    then
        for row in `cat $fornitore`
        do  

            nome="`echo $row | cut -f 1 -d ','`"
            codice="`echo $row | cut -f 2 -d ','`"
            ricambi="`echo $row | cut -f 4 -d ','`"
            # se ha il numero giusto e più di tutti gli altri
            if test "$codice" = "$2" -a "$ricambi" -ge "$3" -a "$ricambi" -gt `cat /tmp/.maxRicambi.tmp`
            then
                echo $ricambi > /tmp/.maxRicambi.tmp
                echo $nome > /tmp/.miglioreFornitore.tmp
            fi
        done
    fi
done

for dir in *
do
    if test -d $dir -a -x $dir
    then
        trova_fornitori_migliori_ric.sh "`pwd`/$dir" $2 $3
    fi
done
