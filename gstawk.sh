#! /bin/bash

FILES="${@:1}"
wrkdir=$(pwd)
makedir=$(dirname $(readlink -f "$0"))
TEST=$pwd"/"test.txt
echo $FILES > $(TEST)
make -n -C $makedir -s stats FILENAMES=$(TEST) PWD=$wrkdir
make -n -C $makedir -s print FILENAMES=$(TEST) PWD=$wrkdir
