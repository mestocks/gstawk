
BEGIN { FS = "[^ATGCatgc]"; i = 0; n = 0; L = 0; min = 100; non = 0 }

{
    if (index($0,">")) {
	    
	    if (i > 0) {
		if (l >= min) { print l; L += l; NA += non; n++ }
		}
		
	    l = 0
	    non = 0
	    seq = ""
	    i++
	}
    else {
	l += length($0)
	non += NF - 1
    }
}

END { if (l >= min) { print l; L += l; NA += non; n++; print L, n, NA } }
