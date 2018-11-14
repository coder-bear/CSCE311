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



/*
bool valid;
//  Sets boolean of pointer validity to false
markInvalid() {
  valid = false;
}

signal(SIGSEGV, markInvalid);
*/