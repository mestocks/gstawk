HOME = $(shell echo $$HOME)
PFX = $(HOME)/.local/bin/

BIN = bin/
SRC = src/

EXE = gstat nx.o fagrep cinv cluster
BINS = $(addprefix $(BIN),$(EXE))
PFXS = $(addprefix $(PFX),$(EXE))

.PHONY:	all
all:	$(BINS)

$(BIN)%.o:	$(SRC)%.c
	gcc -o $@ $^

$(BIN)%:	$(SRC)%.c
	gcc -o $@ $^

$(BIN)%:	$(SRC)%.cpp
	g++ -o $@ $^

.PHONY:	install
install:	$(PFXS)

$(PFX)%:	$(BIN)%
	cp $^ $@
