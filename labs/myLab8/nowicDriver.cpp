/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/

// For the sake of a simple testing
#include <iostream>
#include "nowic.h"

int main() {
  int i = GetInt("My GetInt prompt: ");
  std::cout << "i=" << i << "==" << std::endl;

  double x = GetDouble();
  std::cout << "x=" << x << "==" << std::endl;

  char ch = GetChar();
  std::cout << "ch=" << ch << "==" << std::endl;

  std::string str = GetString("My GetString prompt: ");
  std::cout << "str=" << str << "==" << std::endl;

  std::cout << "Happy Coding~~\n";
}
