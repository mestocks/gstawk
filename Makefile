HOME = $(shell echo $$HOME)
PFX = $(HOME)/.local/bin/

BIN = bin/
SRC = src/

EXE = gstat nx fagrep cinv cluster gstawk filterFasta
BINS = $(addprefix $(BIN),$(EXE))
PFXS = $(addprefix $(PFX),$(EXE))

.PHONY:	all
all:	$(BINS) $(BIN)gstawk_make

$(BIN)%:	$(SRC)%.c
	gcc -o $@ $^

$(BIN)%:	$(SRC)%.sh
	cp $^ $@

$(BIN)%:	$(SRC)%.cpp
	g++ -o $@ $^

$(BIN)gstawk_make:	$(SRC)gstawk_make
	cp $^ $@

###

.PHONY:	clean
clean:
	-rm $(BINS) $(BIN)gstawk_make

###### ######

.PHONY:	install
install:	$(PFXS) $(PFX)gstawk_make

$(PFX)%:	$(BIN)%
	cp $^ $@

###

.PHONY:	uninstall
uninstall:
	-rm $(PFXS) $(PFX)gstawk_make
