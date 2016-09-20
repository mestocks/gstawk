#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1028

int main(int argc, char *argv[])
{
  int start;
  int seqlen;
  long long int len;
  
  char buf[MAXLEN];
  char chrname[MAXLEN];
  
  len = 0;
  start = 0;
  seqlen = 0;

  FILE *fp = fopen(argv[1], "r");
  
  while (fgets(buf, MAXLEN, fp) != NULL) {
    if (strstr(buf, ">") != NULL) {
      if (start == 1) {
	printf("%s\t%lli\n", chrname, len);
	len = 0;
      }
      strcpy(chrname, &buf[1]);
      chrname[strlen(chrname) - 1] = '\0';
    } else {
      seqlen = strlen(buf);
      if (buf[seqlen - 1] == '\n') {
	seqlen = seqlen - 1;
      }
      len = len + seqlen;
    }
    start = 1;
  }
  printf("%s\t%lli\n", chrname, len);
  
 fclose(fp);
 
 return 0; }
