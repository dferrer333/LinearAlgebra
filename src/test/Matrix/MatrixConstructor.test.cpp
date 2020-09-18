#include "Matrix.h";
#include "../TestLogger.cpp";

namespace Test {
  namespace Matrix {
    namespace Constructor {
      namespace LA = LinearAlgebra;

      bool run_all_tests();

      bool should_not_construct_non_uniform_matrix();
      bool should_not_construct_empty_row_matrix();
      bool should_not_construct_empty_column_matrix();

      bool should_construct_matrix_with_one_element();
      bool should_construct_very_large_matrix();
      bool should_construct_square_matrix();
      bool should_construct_non_square_matrix();

      bool should_copy_construct_a_matrix();
      bool should_copy_construct_a_matrix_pointer();
    }
  }
}

bool Test::Matrix::Constructor::run_all_tests() {
  return (
      Test::Matrix::Constructor::should_not_construct_non_uniform_matrix() &&
      Test::Matrix::Constructor::should_not_construct_empty_row_matrix() &&
      Test::Matrix::Constructor::should_not_construct_empty_column_matrix() &&
      Test::Matrix::Constructor::should_construct_matrix_with_one_element() &&
      Test::Matrix::Constructor::should_construct_very_large_matrix() &&
      Test::Matrix::Constructor::should_construct_square_matrix() &&
      Test::Matrix::Constructor::should_construct_non_square_matrix() &&
      Test::Matrix::Constructor::should_copy_construct_a_matrix() &&
      Test::Matrix::Constructor::should_copy_construct_a_matrix_pointer());
}

bool Test::Matrix::Constructor::should_not_construct_non_uniform_matrix() {
  LA::OneDArray row1 = {1,2,3};
  LA::OneDArray row2 = {3,4};
  LA::TwoDArray rows = {row1,row2};

  try {
    LA::Matrix matrix(rows);
  } catch (...) {
    Logger::print_success(__FUNCTION__, __FILE__, __LINE__);
    return true;
  }

  Logger::print_failure(__FUNCTION__, __FILE__, __LINE__);
  return false;
}
bool Test::Matrix::Constructor::should_not_construct_empty_row_matrix() {
  LA::TwoDArray rows(0);

  try {
    LA::Matrix matrix(rows);
  } catch (...) {
    Logger::print_success(__FUNCTION__, __FILE__, __LINE__);
    return true;
  }

  Logger::print_failure(__FUNCTION__, __FILE__, __LINE__);
  return false;
}
bool Test::Matrix::Constructor::should_not_construct_empty_column_matrix() {
  LA::OneDArray row1(0);
  LA::OneDArray row2(0);
  LA::TwoDArray rows = {row1,row2};

  try {
    LA::Matrix matrix(rows);
  } catch (...) {
    Logger::print_success(__FUNCTION__, __FILE__, __LINE__);
    return true;
  }

  Logger::print_failure(__FUNCTION__, __FILE__, __LINE__);
  return false;
}

bool Test::Matrix::Constructor::should_construct_matrix_with_one_element() {
  LA::OneDArray row1 = {1.5};
  LA::TwoDArray rows = {row1};

  try {
    LA::Matrix matrix(rows);

    if (matrix.getWidth() != 1 || matrix.getHeight() != 1) {
      throw "matrix width or height not equal to 1";
    }
  } catch (...) {
    Logger::print_failure(__FUNCTION__, __FILE__, __LINE__);
    return false;
  }

  Logger::print_success(__FUNCTION__, __FILE__, __LINE__);
  return true;
}
bool Test::Matrix::Constructor::should_construct_very_large_matrix() {
  LA::TwoDArray rows;

  for (size_t i = 0; i < 1000; i++) {
    rows.push_back(LA::OneDArray(1000));
  }

  try {
    LA::Matrix matrix(rows);

    if (matrix.getWidth() != 1000 || matrix.getHeight() != 1) {
      throw "matrix width or height not equal to 1000";
    }
  } catch (...) {
    Logger::print_failure(__FUNCTION__, __FILE__, __LINE__);
    return false;
  }

  Logger::print_success(__FUNCTION__, __FILE__, __LINE__);
  return true;
}
bool Test::Matrix::Constructor::should_construct_square_matrix() {
  LA::OneDArray row1 = {1,2,3};
  LA::OneDArray row2 = {4,5,6};
  LA::OneDArray row3 = {7.2,3.1,4};
  LA::TwoDArray rows = {row1,row2,row3};

  try {
    LA::Matrix matrix(rows);
  } catch (...) {
    Logger::print_failure(__FUNCTION__, __FILE__, __LINE__);
    return false;
  }

  Logger::print_success(__FUNCTION__, __FILE__, __LINE__);
  return true;
}
bool Test::Matrix::Constructor::should_construct_non_square_matrix() {
  LA::OneDArray row1 = {1,2};
  LA::OneDArray row2 = {4,5};
  LA::OneDArray row3 = {7.2,3.1};
  LA::TwoDArray rows = {row1,row2,row3};

  try {
    LA::Matrix matrix(rows);
  } catch (...) {
    Logger::print_failure(__FUNCTION__, __FILE__, __LINE__);
    return false;
  }

  Logger::print_success(__FUNCTION__, __FILE__, __LINE__);
  return true;
}

bool Test::Matrix::Constructor::should_copy_construct_a_matrix() {
  LA::OneDArray row1 = {1};
  LA::TwoDArray rows = {row1};
  LA::Matrix matrix(rows);

  try {
    LA::Matrix copiedMatrix = matrix;
    LA::Matrix otherCopiedMatrix(copiedMatrix);
  } catch (...) {
    Logger::print_failure(__FUNCTION__, __FILE__, __LINE__);
    return false;
  }

  Logger::print_success(__FUNCTION__, __FILE__, __LINE__);
  return true;
}
bool Test::Matrix::Constructor::should_copy_construct_a_matrix_pointer() {
  LA::OneDArray row1 = {1};
  LA::TwoDArray rows = {row1};
  LA::Matrix matrix(rows);
  LA::MatrixPointer matrixToCopy = LA::createMatrixCopyOnHeap(matrix);
  
  try {
    LA::Matrix newMatrix(matrixToCopy);
  } catch (...) {
    Logger::print_failure(__FUNCTION__, __FILE__, __LINE__);
    return false;
  }

  Logger::print_success(__FUNCTION__, __FILE__, __LINE__);
  return true;
}
