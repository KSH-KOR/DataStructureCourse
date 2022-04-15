#include <iostream>
using namespace std;

int main() {
  int *pi;
  pi = new int;
  *pi = 17;
  cout << "i = " << *pi << endl;
  delete pi;
}

/*
what type of error?
1. linker error
2. run-time error
3. syntax error
4. logic error

############## My answer: 4. logic error ######################
*/

/*
fix the code such that it outputs "i = 17"
1. adding two lines
2. using new and delete
*/