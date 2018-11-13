bool valid;

//  Sets boolean of pointer validity to false
markInvalid() {
  valid = false;
}

signal(SIGSEGV, markInvalid);