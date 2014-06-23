

###### ######

FSA = $(shell cat $(FILENAMES))
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
	awk -f bin/contig_info.awk $^ | sort -nr | awk -f bin/n50.awk >> $@


