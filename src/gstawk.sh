#! /bin/bash

# gstawk *.fa
# gstawk -x assembly.fa

# Defaults
J=1
X=0

while getopts j:x opt
do
    case $opt in
	j) J=$OPTARG;;
	x) X=1;;
    esac
done

INDEX=$(($OPTIND))
FILES="${@:$INDEX}"

wrkdir=$(pwd)
makedir=$(dirname $(readlink -f "$0"))

if [ $X -eq 1 ]
then
    nx $FILES
else
    FILELOG=$wrkdir"/".gstawk.log
    echo $FILES > $FILELOG
    make -j $J -f gstawk_make -C $makedir -s stats FILENAMES=$FILELOG PWD=$wrkdir
    make -f gstawk_make -C $makedir -s print FILENAMES=$FILELOG PWD=$wrkdir
fi