#include <array>
#include <iostream>
#include "Matrix.h"

int main() {
  std::cout << "Implement Matrix Test!!";

  LinearAlgebra::Matrix<5, 5> myMatrix();

  std::cout << &myMatrix << std::endl;

  return 0;
}
