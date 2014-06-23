#! /bin/bash

FILES="${@:1}"
echo $FILES > test.txt
make -s stats FILENAMES=test.txt
make -s print FILENAMES=test.txt
