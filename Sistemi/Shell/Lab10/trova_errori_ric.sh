#!/bin/sh
# Lab10 - Es 2 ric

> /tmp/.counter.tmp
cd $1

for log in `ls *.log 2>/dev/null`
do
    if test -f $log -a -r $log
    then
        for row in `cat $log`
        do
            # echo `echo $row | grep "error"`
            message="`echo $row | cut -f 4 -d ','`"
            projectName="`echo $row | cut -f 2 -d ','`"
            fileName="`echo $row | cut -f 1 -d ','`"
            dettInfo="`echo $row | cut -f 6 -d ','`"

            if test $message = error
            then
                echo "$projectName $fileName $dettInfo" >> $ERRORI
                echo $message >> /tmp/.counter.tmp
            elif test $message = warning
            then
                echo "$projectName $fileName $dettInfo" >> $WARNING
            fi
        done
    fi
done

if test `wc -l < /tmp/.counter.tmp` -gt `wc -l < /tmp/.max_counter.tmp`
then
    mv /tmp/.counter.tmp /tmp/.max_counter.tmp
    echo $1 > /tmp/.max_dir.tmp
fi

for dir in *
do
    if test -d $dir -a -x $dir
    then
        trova_errori_ric.sh "`pwd`/$dir"
    fi
done
