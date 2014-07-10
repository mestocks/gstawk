BEGIN { i = 0; l = 0 }
{

    if (i == 0) {
	L = $1
	n = $2
	non = $3
        half = $1 / 2
	Ghalf = 1200000000 / 2
	done1 = 0
	done2 = 0
    }
    else
    {
	l += $1
	if (done1 == 1 && done2 == 1) {
	    print n, L, L / n,  max, n50n, ng50n, n50, ng50, non
	    exit
	}
	if (l >= half && done1 == 0) {
	    n50 = $1
	    n50n = i
	    done1 = 1
	}
	if (l >= Ghalf && done2 == 0) {
	    ng50 = $1
	    ng50n = i
	    done2 = 1
	}
    }
    
    if (i == 1) max = $1
    
    i++

}
