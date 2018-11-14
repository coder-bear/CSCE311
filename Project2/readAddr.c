#include <unistd.h>
//  TODO: Include asm/current.h

unsigned long PAGE_SIZE = 0;
unsigned long TASK_SIZE = 0;

PAGE_SIZE = sysconf(_SC_PAGE_SIZE);

if(sizeof(void*)==sizeof(int)) { //  32-bit system
  TASK_SIZE = 0xc0000000UL;
} else {  //  64-bit system
  TASK_SIZE = (1UL << 47) - PAGE_SIZE;
}

int main(int argc, char* argv[]) {
  char *p = 0;
  unsigned long countValid = 0;  //  Count of valid addresses
  unsigned long countInvalid = 0;  //  Count of invalid addresses

  for (; (unsigned long)p < TASK_SIZE; p += PAGE_SIZE*1024) {
    int r = readAddr(p);
    //  TODO: get/ print info
  }
}
