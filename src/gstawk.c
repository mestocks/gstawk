#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 1028
#define NCHR 1000000

int cmpfunc (const void * a, const void * b) { return ( *(int*)b - *(int*)a ); }

int main(int argc, char *argv[])
{  
  const char *dna = "ATGCatgc";

  int f;
  FILE *fp;
  int chrlen[NCHR];
  char buffer[BSIZE];
  
  for (f = 1; f < argc; f++) {
    fp = fopen(argv[f], "r");
    
    
    int i = 0;
    int n = 0;
    int l = 0;
    int L = 0;
    int min = 0;
    int non = 0;
    int b;
    int seqlen;
    
    while (fgets(buffer, BSIZE, fp) != NULL) {
      
      if (strstr(buffer, ">") != NULL) {
	if (i > 0) {
	  if (l >= min) {
	    L = L + l;
	    n++;
	    chrlen[n - 1] = l; } }
	else i = 1;
	l = 0; }
      
      else {
	seqlen = strlen(buffer);
	if (buffer[seqlen - 1] == '\n') { seqlen = seqlen - 1; }
	l = l + seqlen;
	
	b = 0;
	while(buffer[b] != '\0' && buffer[b] != '\n') {
	  if (strchr(dna, buffer[b++]) == NULL) non++; } }
    }
    
    if (l >= min) {
      L = L + l;
      n++;
      chrlen[n - 1] = l; }
    
    qsort(chrlen, n, sizeof(int), cmpfunc);
    
    int c = 0;
    int n50 = 0;
    int n50len = 0;
    int h = L / 2;
    
    while (n50 <= h) {
      n50 = n50 + chrlen[c];
      n50len = chrlen[c];
      c++; }
    
    printf("%s %d %d %d %d %d %d %d\n", argv[f], n, L, L / n, chrlen[0], c, n50len, non);
    
    fclose(fp);
  }
 
 return 0;
}
