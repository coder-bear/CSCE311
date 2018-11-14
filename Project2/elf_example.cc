/* Code snippet for ELF example */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

const int TURKEY_MONTH = 11;  // global var -- should be in .data
const int TURKEY_DAY = 22;  // global var -- should be in .data

void printmsg();  // forward declaration

void input_month() {  // function
  int month;  // local var, should be allocated in .bss
  cin >> month;
  if (month != TURKEY_MONTH) {
    cout << "Sorry, that is incorrect. Program terminating" << endl;  // string literal -- should be in .rodata
    exit(1);
  }
}

void input_day() {  // function
  int day;  // local var, should be allocated in .bss
  cin >> day;
  if (day != TURKEY_DAY) {
    cout << "Sorry, that is incorrect. Program terminating" << endl;  // string literal-- should be in .rodata
    exit(1);
  }
  else
    printmsg();
}

void printmsg() {  // function
  cout << "Happy Thanksgiving!" << endl;  // string literal -- .rodata
}

int main() {  // function
  cout << "Can you guess the date of Thanksgiving?" << endl;  // string literal -- .rodata
  cout << "Enter the 2 digit month of Thanksgiving" << endl;  // string literal -- .rodata
  input_month();
  cout << "Great, now enter the 2 digit day" << endl;  // string literal  -- .rodata
  input_day();
  return 0;
}
