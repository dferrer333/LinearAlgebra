#include <iostream>
#include "Matrix.h"

LinearAlgebra::Matrix::Matrix(LinearAlgebra::TwoDArray const &matrix)
    : matrix(matrix) {
  this->ensureMatrixHasRowsAndColumns();
  this->ensureMatrixIsUniform();
}

LinearAlgebra::Matrix::Matrix(LinearAlgebra::Matrix const &otherMatrix)
    : matrix(otherMatrix.matrix) {
  this->ensureMatrixHasRowsAndColumns();
  this->ensureMatrixIsUniform();
}

LinearAlgebra::Matrix::Matrix(
    LinearAlgebra::MatrixPointer const &otherMatrixPointer)
        : matrix(otherMatrixPointer->matrix) {
  this->ensureMatrixHasRowsAndColumns();
  this->ensureMatrixIsUniform();
}

void LinearAlgebra::Matrix::multiply(
    LinearAlgebra::Matrix const &otherMatrix) {
  std::cerr << "LinearAlgebra::Matrix::multiply Not Implemented!\n";
}

void LinearAlgebra::Matrix::ensureMatrixHasRowsAndColumns() {
  if (this->matrix.size() == 0 || this->matrix[0].size() == 0) {
    throw "Error: matrix must have both rows and columns.";
  }
}

void LinearAlgebra::Matrix::ensureMatrixIsUniform() {
  size_t rowWidth = this->matrix[0].size();

  for (auto row : this->matrix) {
    if (row.size() != rowWidth) {
      throw "Error: matrix must be uniform.";
    }
  }
}
