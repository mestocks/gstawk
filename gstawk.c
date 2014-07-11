#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {

  FILE *fp;
  int size = 100;
  char buf[size];
  
  int i = 0;
  int n = 0;
  int l = 0;
  int L = 0;
  int min = 0;
  int non = 0;
  const char *dna = "ATGCatgc";
  
  fp = fopen(argv[1], "r");
  
  while (fgets(buf, size, fp) != NULL) {
    
    // Check for ">"
    if (strstr(buf, ">") != NULL) {
      
      // > header
      if (i > 0) {
	if (l >= min) {
	  printf("%d\n", l);
	  //printf("> %d %d %d %d\n", i, l, L, n);
	  L = L + l;
	  n++;
	}
      }
      l = 0;
    }
    // Sequence
    else {
      int seqlen = strlen(buf);
      
      if (buf[seqlen - 1] == '\n') {
	seqlen = seqlen - 1;
	  }
      
      l = l + seqlen;
      
      int b = 0;
      while(buf[b] != '\0' && buf[b] != '\n') {
	if(strchr(dna, buf[b++]) == NULL) non++;
      }
    }
    i++;
  }
  
  if (l >= min) {
    L = L + l;
    n++;
    printf("%d\n", l);
    printf("%d %d %d", L, n, non);
    printf("\n");
  }
  
 fclose(fp);
 
 return 0;
}
