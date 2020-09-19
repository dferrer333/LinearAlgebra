#include <iostream>
#include <string>
#include "TestLogger.h"

namespace Test {
  namespace Matrix {
    namespace Add {
      namespace LA = LinearAlgebra;

      bool run_all_tests();

      bool should_not_add_matrices_without_columns();
      bool should_not_add_matrices_without_rows();
      bool should_not_add_matrices_with_varied_sizes();

      bool should_add_two_uniform_matrices();
      bool should_add_two_non_uniform_matrices();

      bool should_add_two_single_element_matrices();
      bool should_add_two_large_matrices();

      bool run_matrix_addition(
          std::string callingFunctionName,
          LA::Matrix &matrix1,
          LA::Matrix &matrix2);
      bool run_matrix_addition(
          std::string callingFunctionName,
          LA::Matrix &matrix1,
          LA::Matrix &matrix2,
          LA::Matrix &matrixResult);
    }
  }
}

bool Test::Matrix::Add::run_all_tests() {
  return (
      should_not_add_matrices_without_columns() &&
      should_not_add_matrices_with_varied_sizes() &&
      should_add_two_uniform_matrices() &&
      should_add_two_non_uniform_matrices() &&
      should_add_two_single_element_matrices() &&
      should_add_two_large_matrices());
}

bool Test::Matrix::Add::should_not_add_matrices_without_columns() {
  LA::TwoDArray rows = {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2}};
  LA::Matrix matrix1(rows);
  LA::Matrix matrix2(rows);

  matrix2[0] = LA::OneDArray();
  matrix2[1] = LA::OneDArray();
  matrix2[2] = LA::OneDArray();

  return run_matrix_addition(__FUNCTION__, matrix1, matrix2);
}
bool Test::Matrix::Add::should_not_add_matrices_with_varied_sizes() {
  LA::TwoDArray rows1 = {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2}};
  LA::Matrix matrix1(rows1);
  LA::TwoDArray rows2 =
      {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2},{1.2,3.2,4.6}};
  LA::Matrix matrix2(rows2);

  return run_matrix_addition(__FUNCTION__, matrix1, matrix2);
}

bool Test::Matrix::Add::should_add_two_uniform_matrices() {
  LA::TwoDArray rows = {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2}};
  LA::Matrix matrix1(rows);
  LA::Matrix matrix2(rows);
  
  LA::TwoDArray resultRows =
      {{2.4,7.32,4.0},{-4.68,18,0.0},{15.6,-10.0,-36.4}};
  LA::Matrix matrixResult(resultRows);

  return run_matrix_addition(__FUNCTION__, matrix1, matrix2, matrixResult);
}
bool Test::Matrix::Add::should_add_two_non_uniform_matrices() {
  LA::TwoDArray rows = {{1.2,3.66,2.0},{-2.34,9,0.0}};
  LA::Matrix matrix1(rows);
  LA::Matrix matrix2(rows);

  LA::TwoDArray resultRows = {{2.4,7.32,4.0},{-4.68,18,0.0}};
  LA::Matrix matrixResult(resultRows);

  return run_matrix_addition(__FUNCTION__, matrix1, matrix2, matrixResult);
}

bool Test::Matrix::Add::should_add_two_single_element_matrices() {
  LA::TwoDArray rows = {{1.2}};
  LA::Matrix matrix1(rows);
  LA::Matrix matrix2(rows);

  LA::TwoDArray resultRows = {{2.4}};
  LA::Matrix matrixResult(resultRows);
  
  return run_matrix_addition(__FUNCTION__, matrix1, matrix2, matrixResult);
}
bool Test::Matrix::Add::should_add_two_large_matrices() {
  LA::OneDArray row;
  row.assign(100, 13.7);
  LA::TwoDArray rows;
  for (size_t i = 0; i < 100; i++) {
    rows.push_back(row);
  }
  LA::Matrix matrix1(rows);
  LA::Matrix matrix2(rows);

  LA::OneDArray resultRow;
  LA::TwoDArray resultRows;
  resultRow.assign(100, 27.4);
  for (size_t i = 0; i < 100; i++) {
    resultRows.push_back(resultRow);
  }
  LA::Matrix resultMatrix(resultRows);

  return run_matrix_addition(__FUNCTION__, matrix1, matrix2, resultMatrix);
}

bool Test::Matrix::Add::run_matrix_addition(
    std::string callingFunctionName,
    LA::Matrix &matrix1,
    LA::Matrix &matrix2) {
  callingFunctionName += std::string(",") + std::string(__FUNCTION__);
  try {
    LA::Matrix result = matrix1 + matrix2;
    Logger::print_failure(__FILE__, callingFunctionName, __LINE__);
    return false;
  } catch (std::string errorMessage) {
    std::cerr << "[SUCCESS] - " << errorMessage << '\n';
  }
  try {
    LA::Matrix result = matrix2 + matrix1;
    Logger::print_failure(__FILE__, callingFunctionName, __LINE__);
    return false;
  } catch (std::string errorMessage) {
    std::cerr << "[SUCCESS] - " << errorMessage << '\n';
  }
  try {
    matrix1 += matrix2;
    Logger::print_failure(__FILE__, callingFunctionName, __LINE__);
    return false;
  } catch (std::string errorMessage) {
    std::cerr << "[SUCCESS] - " << errorMessage << '\n';
  }
  try {
    matrix1 += matrix2;
  } catch (std::string errorMessage) {
    Logger::print_success(__FILE__, callingFunctionName, __LINE__);
    return true;
  }
  
  Logger::print_failure(__FILE__, callingFunctionName, __LINE__);
  return false;
}

bool Test::Matrix::Add::run_matrix_addition(
    std::string callingFunctionName,
    LA::Matrix &matrix1,
    LA::Matrix &matrix2,
    LA::Matrix &matrixResult) {
  callingFunctionName += std::string(",") + std::string(__FUNCTION__);
  if ((matrix1 + matrix2) != matrixResult) {
    Logger::print_failure(__FILE__, callingFunctionName, __LINE__);
    return false;
  }

  matrix1 += matrix2;
  if (matrix1 != matrixResult) {
    Logger::print_failure(__FILE__, callingFunctionName, __LINE__);
    return false;
  }
  
  Logger::print_success(__FILE__, callingFunctionName, __LINE__);
  return true;
}
