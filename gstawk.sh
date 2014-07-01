#! /bin/bash

FILES="${@:1}"
wrkdir=$(pwd)
makedir=$(dirname $(readlink -f "$0"))
echo $FILES > test.txt
make -n -C $makedir -s stats FILENAMES=test.txt PWD=$wrkdir
make -n -C $makedir -s print FILENAMES=test.txt PWD=$wrkdir
