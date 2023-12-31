#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cctype>

int main() {

  int aNumbers[] = {1,2,3,4,5};
  int * pNumbers = aNumbers;

  pNumbers++;

  std::cout << pNumbers << std::endl;
  std::cout << aNumbers << std::endl;

}
