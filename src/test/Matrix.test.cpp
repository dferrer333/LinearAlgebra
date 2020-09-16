#include <array>
#include <cassert>
#include <iostream>
#include "Matrix.h"

namespace LA = LinearAlgebra;

bool simple_matrix_construction();

int main() {
  assert(simple_matrix_construction() == true);

  return 0;
}

bool simple_matrix_construction() {
  try {
    LA::OneDArray row1 = {1, 2};
    LA::OneDArray row2 = {3, 4};
    LA::TwoDArray matrix = {row1, row2};

    LA::Matrix myMatrix(matrix);
  } catch (std::exception &error) {
    return false;
  }

  return true;
}
