#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc (const void * a, const void * b) { return ( *(int*)b - *(int*)a ); }

int main(int argc, char *argv[]) {

  const int size = 128;
  const char *dna = "ATGCatgc";
  FILE *fp = fopen(argv[1], "r");

  char buf[size];
  int clen[1000000];
  
  int i = 0;
  int n = 0;
  int l = 0;
  int L = 0;
  int min = 0;
  int non = 0;
  
  while (fgets(buf, size, fp) != NULL) {
    // Check for ">"
    if (strstr(buf, ">") != NULL) {
      // > header
      if (i > 0) {
	if (l >= min) {
	  L = L + l;
	  n++;
	  clen[n - 1] = l; } }
      else i = 1;
      l = 0; }
    
    // Sequence
    else {
      int seqlen = strlen(buf);
      if (buf[seqlen - 1] == '\n') { seqlen = seqlen - 1; }
      l = l + seqlen;
      
      int b = 0;
      while(buf[b] != '\0' && buf[b] != '\n') {
	if (strchr(dna, buf[b++]) == NULL) non++; } } }
  
  if (l >= min) {
    L = L + l;
    n++;
    clen[n - 1] = l; }
  
  qsort(clen, n, sizeof(int), cmpfunc);
  
  int c = 0;
  int n50 = 0;
  int n50len = 0;
  int h = L / 2;
  
  while (n50 <= h) {
    n50 = n50 + clen[c];
    n50len = clen[c];
    c++; }
  
  printf("%d %d %d %d %d %d %d\n", n, L, L / n, clen[0], c, n50len, non);
  
 fclose(fp);
 
 return 0; }
