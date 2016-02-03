#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)b - *(int*)a );
}

int main(int argc, char *argv[]) {

  FILE *fp;
  int size = 128;
  char buf[size];

  static int clen[10000000];
  
  int first_contig = 0;
  int ncontigs = 0;
  
  int seq_len = 0;
  int total_len = 0;
  
  int min = 0;
  
  fp = fopen(argv[1], "r");
  
  while (fgets(buf, size, fp) != NULL) {
    
    // Check for ">"
    if (strstr(buf, ">") != NULL) {
      
      // > header
      if (first_contig > 0) {
	if (seq_len >= min) {
	  total_len = total_len + seq_len;
	  ncontigs++;
	  clen[ncontigs - 1] = seq_len;
	}
      }
      else first_contig = 1;
      seq_len = 0;
    }
    // Sequence
    else {
      int line_len = strlen(buf);
      
      if (buf[line_len - 1] == '\n') {
	line_len = line_len - 1;
	  }
      
      seq_len = seq_len + line_len;
    }
  }
  
  if (seq_len >= min) {
    total_len = total_len + seq_len;
    ncontigs++;
    clen[ncontigs - 1] = seq_len;
  }
  
  qsort(clen, ncontigs, sizeof(int), cmpfunc);

  // Loop through reverse sorted contig sizes
  
  int percent = 0;
  int i = 0;
  int nx = clen[i];

  printf("%d %d\n", percent, nx);
  percent++;
  
  double cum_len = clen[i];
  double hundred = 100;
  double prop = percent / hundred;
  double pcutoff = total_len * prop;
  
  int last_i = percent;
  int last_nx = nx;
  
  while (i < ncontigs) {
    if (cum_len <= pcutoff) {
      i++;
      nx = clen[i];
      cum_len = cum_len + nx;
    } else {
      printf("%d %d\n", percent, nx);
      percent++;
      prop = percent / hundred;
      pcutoff = total_len * prop;
      
    }
  }

 fclose(fp);
 
 return 0;
}
