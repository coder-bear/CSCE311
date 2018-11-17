/* Code snippet for ELF example */
#include <stdio.h>

const int TURKEY_MONTH = 11;  // global var -- should be in .data
const int TURKEY_DAY = 22;  // global var -- should be in .data
int TEST_NUMBER;

void printmsg();  // forward declaration

void input_month() {  // function
  int month;  // local var, should be allocated in .bss
  month = 11;
  if (month != TURKEY_MONTH) {
    printf("%s", "Test message 1");
  }
  char world[5] = {'H', 'e', 'l', 'l', 'o'};
}

void printmsg() {  // function
  printf("%s", "Happy Thanksgiving!");  // string literal -- .rodata
}

int main() {  // function
  //cout << "Can you guess the date of Thanksgiving?" << endl;  // string literal -- .rodata
  //cout << "Enter the 2 digit month of Thanksgiving" << endl;  // string literal -- .rodata
  input_month();
  //cout << "Great, now enter the 2 digit day" << endl;  // string literal  -- .rodata
  //input_day();
  return 0;
}
