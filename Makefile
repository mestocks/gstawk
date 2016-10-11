HOME = $(shell echo $$HOME)
PFX = $(HOME)/.local/bin/

BIN = bin/
SRC = src/

#EXE = chrlen gstawk nx fagrep cinv cluster filterFasta
EXE = chrlen gstawk
BINS = $(addprefix $(BIN),$(EXE))
PFXS = $(addprefix $(PFX),$(EXE))

Wgcc = -Wall -Wextra -Wpedantic

.PHONY:	all
all:	$(BINS)

$(BIN)%:	$(SRC)%.c
	mkdir -p $(BIN)
	gcc $(Wgcc) -o $@ $^

#$(BIN)%:	$(SRC)%.cpp
#	mkdir -p $(BIN)
#	g++ -o $@ $^


###

.PHONY:	clean
clean:
	-rm $(BINS)

###### ######

.PHONY:	install
install:	$(PFXS)

$(PFX)%:	$(BIN)%
	mkdir -p $(PFX)
	cp $^ $@

###

.PHONY:	uninstall
uninstall:
	-rm $(PFXS)
