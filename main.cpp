#include <iostream>
#include <cstdlib>
#include <string>

int addNumbers(int first, int second) {
  return first + second;
}

int main(int argc, char **argv) {

  int firstNumber;
  int secondNumber;

  int sum = addNumbers(firstNumber, secondNumber);

  std::cout << "Enter the first number: ";
  std::cin >> firstNumber;
  std::cout << "Enter the second number: ";
  std::cin >> secondNumber;
  std::cout << "The sum of those numbers is: " << addNumbers(firstNumber, secondNumber) << std::endl;

  return 0;
}
