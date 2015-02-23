
.PHONY:	all
all:	bin/gstat.o bin/nx.o bin/fagrep.o bin/cinv bin/cluster

bin/%.o:	bin/%.c
	gcc -o $@ $^

bin/%:	bin/%.cpp
	g++ -o $@ $^
