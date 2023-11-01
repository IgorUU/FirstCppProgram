#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char **argv) {

  int age;
  std::string name;

  std::cout << "Please enter your name and age: " << std::endl;

  // std::cin >> name;
  // std::cin >> age;

  std::getline(std::cin, name);
  std::cin >> age;

  std::cout << "Hello " << name << ". Your age is " << age << std::endl;

  return 0;
}
