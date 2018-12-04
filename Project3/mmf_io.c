/**
 * Project 3 -- mmf_io.c
 * Finds the number of each character in given file
 * Includes counts of spaces and new lines
**/

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "util.h"

int main() {

  int count[256] = {0};  // initialize 256 element (for 256 ASCII chars) int array to zero
  FILE *fp = fopen("Anna.txt" , "r");
  if (!fp) {
    perror("fopen");
  }
  int c;  // int used for counter

  fseek(fp, 0, SEEK_END);
  size_t fsize = ftell(fp);  // Get size of file by seeking to end, getting size, and rewinding
  rewind(fp);

  char *data = mmap(NULL, fsize, PROT_READ, MAP_PRIVATE, fileno(fp), 0);
  if (data == MAP_FAILED) {
    perror("mmap");
  }

  for (size_t i = 0; i < fsize; ++i) {
    count[data[i]] += 1;
  }

  printcounts(count);

  fclose(fp);
  return 0;
}
