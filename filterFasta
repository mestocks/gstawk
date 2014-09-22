#! /bin/bash

# Usage:
#
#       filterFasta [-l min_length -r] <file.fsa>
#
# -l    minimum length of sequence
# -r    rename each sequence ">contig"$n, where $n
#       is the sequence position within the file
#       (starting from 1)

LEN=0
NAME=0

while getopts rl: opt
do
    case $opt in
	r) NAME=1;;
	l) LEN=$OPTARG;;
    esac
done

index=$((OPTIND))
FILE="${@:$index}"

awk -v l=$LEN -v r=$NAME -- ' BEGIN { n=0; seq="" }; { if (/^>/) { if (n > 0 && length(seq) >= l) { if (r == 1) seqid=">contig"n; print seqid"\n"seq }; n++; seqid=$0; seq="" } else { newseq=$0"\n"; seq=seq$0 } } ' $FILE
