/**
 * Project 3 -- reg_io.c
 * Finds the number of each character in given file
 * Includes counts of spaces and new lines
 * Execution time: 19 ms
**/

#include <stdio.h>
#include <stdlib.h>

int main() {

  int count[256] = {0};  // initialize 256 element (for 256 ASCII chars) int array to zero
  FILE *fp = fopen("Anna.txt" , "r");
  int c;  // int used for counter

  while((c = fgetc(fp))) {  // fgetc() -- reads next char from stream and returns unsigned char cast to int
    if (c == EOF) break;  // if end of file, break and print
    count[c]+= 1;

  }
  for(int i=0; i<256; i++) {
    if(count[i] > 0) {  // if there is at least 1 occurrance of char
      printf("char %c: %d times\n" , i, count[i]);  // print the char and how many occurrances
    }
  }
  fclose(fp);
  return 0;
}
