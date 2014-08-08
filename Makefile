
.PHONY:	all
all:	bin/gstat.o

bin/gstat.o:	bin/gstat.c
	gcc -o $@ $^
