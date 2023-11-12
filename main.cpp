#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char **argv) {

  int number1 = 15;
  int number2 = 017;
  int number3 = 0x0f;
  int number4 = 0b00001111;

  std::cout << number1 << std::endl;
  std::cout << number2 << std::endl;
  std::cout << number3 << std::endl;
  std::cout << number4 << std::endl;


  std::cout << "sizeof int: " << sizeof(int) << std::endl;
  std::cout << "sizeof number1: " << sizeof(number2) << std::endl;

  return 0;
}
