HOME = $(shell echo $$HOME)
PFX = $(HOME)/.local/bin/

BIN = bin/
SRC = src/

EXE = chrlen gstawk nx fagrep cinv cluster make_gstawk filterFasta
BINS = $(addprefix $(BIN),$(EXE))
PFXS = $(addprefix $(PFX),$(EXE))

Wgcc = -Wall -Wextra -Wpedantic

.PHONY:	all
all:	$(BINS) $(BIN)gstawk_make

$(BIN)%:	$(SRC)%.c
	mkdir -p $(BIN)
	gcc $(Wgcc) -o $@ $^

$(BIN)%:	$(SRC)%.sh
	mkdir -p $(BIN)
	cp $^ $@

$(BIN)%:	$(SRC)%.cpp
	mkdir -p $(BIN)
	g++ -o $@ $^

$(BIN)gstawk_make:	$(SRC)gstawk_make
	mkdir -p $(BIN)
	cp $^ $@

###

.PHONY:	clean
clean:
	-rm $(BINS) $(BIN)gstawk_make

###### ######

.PHONY:	install
install:	$(PFXS) $(PFX)gstawk_make

$(PFX)%:	$(BIN)%
	mkdir -p $(PFX)
	cp $^ $@

###

.PHONY:	uninstall
uninstall:
	-rm $(PFXS) $(PFX)gstawk_make
