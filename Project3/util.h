
#include <ctype.h>

/**
 * Prints the counts of each character (count must be length 256)
 */
void printcounts(int* count) {
  for(unsigned char i=1; i != 0; i++) {
    // Cannot include null character so loop until overflow to 0
    if(count[i] > 0) {  // if there is at least 1 occurrance of char
      if (!isprint(i) || (i != ' ' && isspace(i))) {
        printf("char %#02X: ", i);
      } else {
        printf("char %c: ", i);
      }
      printf("%d times\n", count[i]);  // print the char and how many occurrances
    }
  }
}
