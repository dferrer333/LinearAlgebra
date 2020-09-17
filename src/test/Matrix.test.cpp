#include <array>
#include <cassert>
#include <iostream>
#include "Matrix.h"

namespace LA = LinearAlgebra;

bool test_default_matrix_constructor();
bool test_2D_array_matrix_constructor();

int main() {
  assert(
      test_default_matrix_constructor() &&
      test_2D_array_matrix_constructor());

  return 0;
}


bool test_default_matrix_constructor() {
  try {
    LA::Matrix myMatrix();
  } catch (...) {
    std::cout << "[SUCCESS] - " << __FUNCTION__ << '\n';
    return true;
  }
  std::cerr << "[FAILURE] - " << __FUNCTION__ << '\n';
  return false;
}

bool test_non_uniform_2D_array();
bool test_empty_row_array();
bool test_empty_column_array();
bool test_normal_2D_array_constructor();

bool test_2D_array_matrix_constructor() {
  return test_non_uniform_2D_array() && test_empty_row_array() &&
      test_empty_column_array() && test_normal_2D_array_constructor();
}

bool test_non_uniform_2D_array() {
  LA::OneDArray row1 = {1,2,3};
  LA::OneDArray row2 = {3,4};
  LA::TwoDArray rows = {row1, row2};

  try {
    LA::Matrix matrix(rows);
  } catch (...) {
    std::cout << "[SUCCESS] - " << __FUNCTION__ << '\n';
    return true;
  }
  
  std::cerr << "[FAILURE] - " << __FUNCTION__ << '\n';
  return false;
}

bool test_empty_row_array() {
  LA::TwoDArray rows(0);

  try {
    LA::Matrix matrix(rows);
  } catch (...) {
    std::cout << "[SUCCESS] - " << __FUNCTION__ << '\n';
    return true;
  }

  std::cerr << "[FAILURE] - " << __FUNCTION__ << '\n';
  return false;
}

bool test_empty_column_array() {
  LA::OneDArray row1(0);
  LA::OneDArray row2(0);
  LA::TwoDArray rows = {row1, row2};

  try {
    LA::Matrix matrix(rows);
  } catch (...) {
    std::cout << "[SUCCESS] - " << __FUNCTION__ << '\n';
    return true;
  }

  std::cerr << "[FAILURE] - " << __FUNCTION__ << '\n';
  return false;
}

bool test_normal_2D_array_constructor() {
  LA::OneDArray row1 = {1.5, 3.2, 4.1, 5.5};
  LA::OneDArray row2 = {2.5, 3.3, 4.2, 15.2};
  LA::OneDArray row3 = {7.7, 65.4, 3.6, 23.43};
  LA::OneDArray row4 = {5.5, 3.4, 2.6, 1.1};
  LA::TwoDArray rows = {row1, row2, row3, row4};

  try {
    LA::Matrix matrix(rows);
  } catch (...) {
    std::cerr << "[FAILURE] - " __FUNCTION__ << '\n';
    return false;
  }

  std::cout << "[SUCCESS] - " __FUNCTION__ << '\n';
  return true;
}
