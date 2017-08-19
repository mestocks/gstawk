#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DNA 128
#define BSIZE 8192
#define NCHR 1000000

int cmpfunc (const void * a, const void * b)
{
  return ( *(long long int*)b - *(long long int*)a );
}

int main(int argc, char *argv[])
{
  if (argc == 1) {
    printf("Help!\n");
    exit(0);
  }
  
  int d;
  int darray[DNA];
  const char *dna = "ATGCatgc";
  
  /*
   * darray[(int)<char>] should return 1 for the characters 
   * given in 'dna', and 0 otherwise. Quick and easy way to 
   * check whether a character 'is.dna()' without using a bunch 
   * of if statements or switches.
   */
  for (d = 0; d < DNA; d++) {
    darray[d] = 0;
  }
  
  for (d = 0; d < 8; d++) {
    darray[(int)dna[d]] = 1;
  }
  
  int f;
  int res;
  int arg1;
  FILE *fp;
  char *tmp;
  char buffer[BSIZE];
  long long int chrlen[NCHR];

  for (d = 0; d < NCHR; d++) {
    chrlen[d] = 0;
  }

  int inseqid;
  long long int l;
  long long int L;
  long long int non;
  unsigned int ichr;

  int c;
  double h;
  long long int n50;
  long long int n50len;
  
  printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "assembly", "ncontigs", "nbps", "ulen", "maxlen", "n50num", "n50len", "nonATGC");
  
  for (f = 1; f < argc; f++) {
    fp = fopen(argv[f], "r");
    
    l = 0;
    L = 0;
    non = 0;
    ichr = 0;
    inseqid = 0;
    
    while (!feof(fp)) {
      res = fread(buffer, sizeof(char), BSIZE - 1, fp);
      buffer[res] = '\0';
      tmp = buffer;

      while (*tmp) {
	if (*tmp == '>') {
	  inseqid = 1;
	  if (ichr != 0) {	    
	    chrlen[ichr - 1] = l;
	    l = 0;
	  }
	  ichr++;
	} else if (inseqid == 1) {
	  if (*tmp == '\n') {
	    inseqid = 0;
	  }
	} else if (*tmp != '\n') {
	  l++;
	  L++;
	  if (darray[(int)(*tmp)] == 0) {
	    non++;
	  }
	}
	tmp++;
      }
    }
    chrlen[ichr - 1] = l;
    qsort(chrlen, ichr, sizeof(long long int), cmpfunc);
    
    c = 0;
    n50 = 0;
    n50len = 0;
    h = L / 2;
    
    while (n50 <= h) {
      n50 = n50 + chrlen[c];
      n50len = chrlen[c];
      c++;
    }
    printf("%s\t%d\t%lli\t%lli\t%lli\t%d\t%lli\t%lli\n", argv[f], ichr, L, L / ichr, chrlen[0], c, n50len, non);
    
    fclose(fp);
  }
 return 0;
}
