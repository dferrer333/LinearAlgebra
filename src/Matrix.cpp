#include <iostream>
#include "Matrix.h"

LinearAlgebra::Matrix::Matrix(LinearAlgebra::TwoDArray const &rows)
    : rows(rows) {
  this->ensureMatrixHasRowsAndColumns();
  this->ensureMatrixIsUniform();
}

LinearAlgebra::Matrix::Matrix(LinearAlgebra::Matrix const &otherMatrix)
    : rows(otherMatrix.rows) {
  this->ensureMatrixHasRowsAndColumns();
  this->ensureMatrixIsUniform();
}

int LinearAlgebra::Matrix::getWidth() const {
  return this->rows.size();
}

int LinearAlgebra::Matrix::getHeight() const {
  return this->rows[0].size();
}

LinearAlgebra::MatrixPointer LinearAlgebra::Matrix::addAndCopy(
    LinearAlgebra::Matrix const &otherMatrix) const {
  if (this->getWidth() != otherMatrix.getWidth() ||
      this->getHeight() != otherMatrix.getHeight()) {
    throw "Error: matrices must have equal heights and widths when adding.";
  }

  MatrixPointer summedMatrix =
      std::make_unique<Matrix>(otherMatrix.getHeight());
  
  // TODO - add iterators before continuing
  // for (auto row : )
}

void LinearAlgebra::Matrix::ensureMatrixHasRowsAndColumns() const {
  if (this->rows.size() == 0 || this->rows[0].size() == 0) {
    throw "Error: matrix must have both rows and columns.";
  }
}

void LinearAlgebra::Matrix::ensureMatrixIsUniform() const {
  size_t rowWidth = this->rows[0].size();

  for (auto row : this->rows) {
    if (row.size() != rowWidth) {
      throw "Error: matrix must be uniform.";
    }
  }
}
