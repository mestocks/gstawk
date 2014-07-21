

###### ######

#FSA = $(shell cat $(FILENAMES))
FNAMES = $(shell cat $(FILENAMES))
FSA = $(addprefix $(PWD)/,$(FNAMES))
base = $(basename $(FSA))
STS = $(addsuffix .txt,$(base))

###### ######

.PHONY:	print
print:	$(STS)
	echo "assembly ncontigs nbps ulen maxlen n50num n50len nonATGC"
	cat $^

###### ######

.PHONY:	stats
stats:	$(STS)

%.txt:	%.fa
	echo -n $^" " >> $@
	bin/gstawk2.o $^ >> $@

#./gstawk.o $^ | sort -nr | awk -f bin/n50.awk >> $@
#awk -f bin/contig_info.awk $^ | sort -nr | awk -f bin/n50.awk >> $@


