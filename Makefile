BIN = bin/
SRC = src/

.PHONY:	all
all:	$(BIN)gstat.o $(BIN)nx.o $(BIN)fagrep $(BIN)cinv $(BIN)cluster

$(BIN)%.o:	$(SRC)%.c
	gcc -o $@ $^

$(BIN)%:	$(SRC)%.c
	gcc -o $@ $^

$(BIN)%:	$(SRC)%.cpp
	g++ -o $@ $^
