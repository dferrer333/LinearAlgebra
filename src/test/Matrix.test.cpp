#include <array>
#include <cassert>
#include <iostream>
#include "Matrix.h"

bool simple_matrix_construction();

int main() {
  assert(simple_matrix_construction() == true);

  return 0;
}

bool simple_matrix_construction() {
  try {
    std::array<float, 2> row1 = {1, 2};
    std::array<float, 2> row2 = {3, 4};
    std::array<std::array<float, 2>, 2> matrix = {row1, row2};

    LinearAlgebra::Matrix<2, 2> myMatrix(matrix);
  } catch (std::exception &error) {
    return false;
  }

  return true;
}
