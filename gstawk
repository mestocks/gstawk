#! /bin/bash

FILES="${@:1}"
wrkdir=$(pwd)
makedir=$(dirname $(readlink -f "$0"))
TEST=$wrkdir"/"test.txt
echo $FILES > $TEST
make -C $makedir -s stats FILENAMES=$TEST PWD=$wrkdir
make -C $makedir -s print FILENAMES=$TEST PWD=$wrkdir
