#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cctype>

int main() {

  char szText[] = "Hello world!";
  char * pText = szText;

  pText++;

  std::cout << pText << std::endl;

  pText += 5;

  std::cout << pText << std::endl;
}
