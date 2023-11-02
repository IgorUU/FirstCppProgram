#include <iostream>
#include <cstdlib>
#include <string>

int addNumbers(int first, int second) {
  return first + second;
}

int main(int argc, char **argv) {

  int age;
  std::string name;

  std::cout << "Type in your last name and age, separated by spaces: " << std::endl;
  std::cin >> name >> age;
  std::cout << "Hello " << name << "! You are " << age << " years old." << std::endl;


  return 0;
}
