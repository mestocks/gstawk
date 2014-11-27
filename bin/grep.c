#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[]) {

  FILE *fp;
  int size = 128;
  char buf[size];

  const char *dna = "ATGCatgc";
  
  int mcount = 0;
  char seqid[size];

  const char *needle = argv[1];
  int needle_size = strlen(needle);
  fp = fopen(argv[2], "r");

  int i = 0;
  int f = 0;
  int b = 0;
  int n = 0;
  
  while (fgets(buf, size, fp) != NULL) {
    
    // Check for ">"
    if (strstr(buf, ">") != NULL) {
      if (f != 0) {
	printf("%d\t%d\n", mcount, n);
      }
      buf[strlen(buf)-1] = '\0';
      printf("%s\t", buf);
      i = 0;
      n = 0;
      mcount = 0;
      f = 1;
    }
    // Sequence
    else {
      b = 0;
      
      while(buf[b] != '\0' && buf[b] != '\n') {

	if (strchr(dna, buf[b]) == NULL) {
	  i = 0;
	}
	else {
	  if (toupper(buf[b]) != toupper(needle[i])) {
	    i = 0;
	  }
	  if (toupper(buf[b]) != toupper(needle[i])) {
	    i = 0;
	  }
	  else {
	    i++;
	    if (i == needle_size) {
	      mcount++;
	      i = 0;
	    }
	  }
	}
	b++;
	n++;
      }
    }

  }
  printf("%d\t%d\n", mcount, n);  
 fclose(fp);
 
 return 0;
}
