
.PHONY:	all
all:	bin/gstat.o bin/nx.o bin/fagrep.o bin/cinv

bin/%.o:	bin/%.c
	gcc -o $@ $^

bin/cinv:	bin/cinv.cpp
	g++ -o $@ $^
