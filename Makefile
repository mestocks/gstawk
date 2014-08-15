
.PHONY:	all
all:	bin/gstat.o bin/nx.o

bin/%.o:	bin/%.c
	gcc -o $@ $^
