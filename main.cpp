#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cctype>

int main() {

  const char * p = "Hello world";
  const char ** p1 = &p;

  std::cout << *p1 << std::endl;

}
