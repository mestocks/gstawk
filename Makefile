HOME = $(shell echo $$HOME)
PFX = $(HOME)/.local/bin/

BIN = bin/
SRC = src/

EXE = gstat nx fagrep cinv cluster gstawk filterFasta
BINS = $(addprefix $(BIN),$(EXE))
PFXS = $(addprefix $(PFX),$(EXE))

.PHONY:	all
all:	$(BINS)

$(BIN)%:	$(SRC)%.c
	gcc -o $@ $^

$(BIN)%:	$(SRC)%.sh
	cp $^ $@

$(BIN)%:	$(SRC)%.cpp
	g++ -o $@ $^

.PHONY:	install
install:	$(PFXS)

$(PFX)%:	$(BIN)%
	cp $^ $@
