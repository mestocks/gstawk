#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// fagrep <dna_string> <file>

// Searches for identifical matches in sequences in fasta
// file. Outputs chr, start and end positions in bed format
// (so start positions are 0-based and end positions are
// 1-based).

int main(int argc, char *argv[]) {

  FILE *fp;
  const char *needle = argv[1];

  int size = 128;
  fp = fopen(argv[2], "r");
  const char *dna = "ATGCatgc";
  
  char buf[size];
  char fastaid[size];
  
  int needle_size = strlen(needle);
  
  int posArray[needle_size];
  int j;
  for (j = 0; j < needle_size; j++) {
    posArray[j] = 0;
  }

  int ichar = 0;
  int f = 0;
  int b = 0;
  int pos = 0;
  
  while (fgets(buf, size, fp) != NULL) {
    
    // Check for ">"
    if (strstr(buf, ">") != NULL) {

      buf[strlen(buf)-1] = '\0';
      memcpy(fastaid, buf+1, strlen(buf));

      ichar = 0;
      pos = 0;
    }
    // Sequence
    else {
      b = 0;
      
      while(buf[b] != '\0' && buf[b] != '\n') {

	if (strchr(dna, buf[b]) == NULL) {
	  ichar = 0;
	}
	else {
	  
	  if (toupper(buf[b]) != toupper(needle[ichar])) {
	    ichar = 0;
	  }
	  
	  if (toupper(buf[b]) != toupper(needle[ichar])) {
	    ichar = 0;
	  }
	  else {
	    posArray[ichar] = pos;
	    ichar++;
	    
	    if (ichar == needle_size) {
	      printf("%s\t%d\t%d\n", fastaid, posArray[0], posArray[needle_size-1]+1);
	      ichar = 0;
	    }
	    
	  }
	}
	b++;
	pos++;
      }
    }

  }
 fclose(fp);
 
 return 0;
}
