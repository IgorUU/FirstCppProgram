#include <iostream>

int main() {

  bool red_light{false};
  bool green_light{false};
  int number{1};

  if (red_light){
    std::cout << "Stop!" << std::endl;
  } else{
    std::cout << "Go through!" << std::endl;
  }

  std::cout << "sizeof(bool): " << sizeof(bool) << std::endl;
  std::cout << std::boolalpha;
  std::cout << "boolean value: " << red_light << std::endl;
  std::cout << "ordinary value: " << number << std::endl;
  std::cout << "sizeof(number)" << sizeof(number) << std::endl;

  return 0;
}
