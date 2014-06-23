BEGIN { i = 0; l = 0 }
{

    if (i == 0) {
	L = $1
	n = $2
	non = $3
        half = $1 / 2
    }
    else
    {
	l += $1
	if (l >= half) {
	    print n, L, L / n, max, i, $1, non
	    exit
	}
    }
    
    if (i == 1) max = $1
    
    i++

}
