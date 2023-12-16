#include <iostream>

int main() {

  int value { 5 };

  std::cout << "The value is : " << value++ << std::endl;
  std::cout << "The value is : " << ++value << std::endl;

}
