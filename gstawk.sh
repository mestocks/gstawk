#! /bin/bash

FILES="${@:1}"
wrkdir=$(pwd)
echo $FILES > test.txt
make -s stats FILENAMES=test.txt PWD=$wrkdir
make -s print FILENAMES=test.txt PWD=$wrkdir
