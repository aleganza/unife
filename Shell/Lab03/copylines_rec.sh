#!/bin/sh
# Lab03 - Es 4 rec

dirAbsolute=$1
shift
string=$1
shift
fileNames=$*

cd $dirAbsolute
# per tutti i file nella cartella
for file in `ls * 2>/dev/null`
do
    if test -f $file -a -r $file
    then
        # per tutti i nomi di file inseriti dall'utente
        for fileName in $fileNames
        do
            case "`echo $file | cut -f 1 -d '.'`" in
                $fileName)
                    if test `grep $string $file | wc -l` -gt 0
                    then
                        mv $file /mnt/x/Sistema/Scuola/Informatica/GitHub/UniFe-Programming/Shell/Lab03/tmp
                        echo $file >> /tmp/.counter.tmp
                        echo `grep $string $file` >> /tmp/.lines.tmp
                    fi;;
            esac
        done
    fi
done

# case $fileName in
#     *[!a-z]*) 
# esac

for dir in *
do
    if test -d $dir -a -x $dir
    then
        copylines_rec.sh "`pwd`/$dir" "$string" "$fileNames"
    fi
done
