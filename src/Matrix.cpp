#include <iostream>
#include "Matrix.h"

LinearAlgebra::Matrix::Matrix(LinearAlgebra::TwoDArray const &rows)
    : rows(rows) {
  this->ensureMatrixHasRowsAndColumns();
  this->ensureMatrixIsUniform();

  this->matrixWidth(rows.size());
  this->matrixHeight(rows[0].size());
}

LinearAlgebra::Matrix::Matrix(LinearAlgebra::Matrix const &otherMatrix)
    : rows(otherMatrix.rows),
      matrixWidth(otherMatrix.getWidth()),
      matrixHeight(otherMatrix.getHeight()) {
  this->ensureMatrixHasRowsAndColumns();
  this->ensureMatrixIsUniform();
}

LinearAlgebra::Matrix::Matrix(
    LinearAlgebra::MatrixPointer const &otherMatrixPointer)
        : rows(otherMatrixPointer->rows),
          matrixWidth(otherMatrixPointer->rows.getWidth()),
          matrixHeight(otherMatrixPointer->rows.getHeight()) {
  this->ensureMatrixHasRowsAndColumns();
  this->ensureMatrixIsUniform();
}

void LinearAlgebra::Matrix::ensureMatrixHasRowsAndColumns() {
  if (this->rows.size() == 0 || this->rows[0].size() == 0) {
    throw "Error: matrix must have both rows and columns.";
  }
}

void LinearAlgebra::Matrix::ensureMatrixIsUniform() {
  size_t rowWidth = this->rows[0].size();

  for (auto row : this->rows) {
    if (row.size() != rowWidth) {
      throw "Error: matrix must be uniform.";
    }
  }
}
