/**
 * Project 3 -- reg_io.c
 * Finds the number of each character in given file
 * Includes counts of spaces and new lines
**/

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

int main() {

  int count[256] = {0};  // initialize 256 element (for 256 ASCII chars) int array to zero
  FILE *fp = fopen("Anna.txt" , "r");
  int c;  // int used for counter

  while((c = fgetc(fp))) {  // fgetc() -- reads next char from stream and returns unsigned char cast to int
    if (c == EOF) break;  // if end of file, break and print
    count[c]+= 1;

  }

  printcounts(count);

  fclose(fp);
  return 0;
}
