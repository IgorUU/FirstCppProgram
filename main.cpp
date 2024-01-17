#include <iostream>
#include <iomanip>

int main(){

  // Different number systems: std::dec, std::hex, std::oct

  int pos_int {707070};
  int neg_int {-47347};
  double double_var {498.32};

  std::cout << "default base format : " << std::endl;
  std::cout << std::hex << "pos_int : " << pos_int << std::endl;
  std::cout << "neg_int : " << neg_int << std::endl;
  std::cout << "double_var : " << double_var << std::endl;

  return 0;
}
