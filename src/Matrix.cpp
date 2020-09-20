#include "Matrix.h"

namespace LinearAlgebra {
  Matrix::Matrix(LinearAlgebra::TwoDArray const &rows)
      : rows(rows) {
    this->ensureMatrixHasRowsAndColumns();
    this->ensureMatrixIsUniform();
  }

  Matrix::Matrix(LinearAlgebra::Matrix const &otherMatrix)
      : rows(otherMatrix.rows) {
    this->ensureMatrixHasRowsAndColumns();
    this->ensureMatrixIsUniform();
  }

  size_t Matrix::getWidth() const {
    return this->rows[0].size();
  }

  size_t Matrix::getHeight() const {
    return this->rows.size();
  }

  Matrix Matrix::operator+(Matrix const &otherMatrix) const {
    if (this->getHeight() == 0 || otherMatrix.getHeight() == 0 ||
        this->getWidth() == 0 || otherMatrix.getWidth() == 0) {
      throw "Error: matrices must have positive width and height.";
    }
    if (this->getWidth() != otherMatrix.getWidth() ||
        this->getHeight() != otherMatrix.getHeight()) {
      throw "Error: matrices must have equal heights and widths when adding.";
    }

    TwoDArray summedMatrix;
    OneDArray temporaryRow(otherMatrix.getWidth());
    for (size_t i = 0; i < otherMatrix.getHeight(); i++) {
      for (size_t j = 0; j < otherMatrix.getWidth(); j++) {
        temporaryRow[j] = (*this)[i][j] + otherMatrix[i][j];
      }

      summedMatrix.push_back(temporaryRow);
    }

    return Matrix(summedMatrix);
  }

  Matrix& Matrix::operator+=(Matrix const &otherMatrix) {
    if (this->getHeight() == 0 || otherMatrix.getHeight() == 0 ||
        this->getWidth() == 0 || otherMatrix.getWidth() == 0) {
      throw "Error: matrices must have positive width and height.";
    }
    if (this->getWidth() != otherMatrix.getWidth() ||
        this->getHeight() != otherMatrix.getHeight()) {
      throw "Error: matrices must have equal heights and widths when adding.";
    }

    for (size_t i = 0; i < otherMatrix.getHeight(); i++) {
      for (size_t j = 0; j < otherMatrix.getWidth(); j++) {
        (*this)[i][j] += otherMatrix[i][j];
      }
    }

    return *this;
  }

  Matrix& Matrix::operator=(Matrix const &otherMatrix) {
    this->rows = otherMatrix.rows;
    return *this;
  }

  const OneDArray& Matrix::operator[](size_t const rowIndex) const {
    if (rowIndex >= this->getHeight()) {
      throw "Error: access row index is passed the row height.";
    }
    return this->rows[rowIndex];
  }

  OneDArray& Matrix::operator[](size_t const rowIndex) {
    if (rowIndex >= this->getHeight()) {
      throw "Error: access row index is passed the row height.";
    }

    return this->rows[rowIndex];
  }

  TwoDArray::iterator Matrix::begin() {
    return this->rows.begin();
  }

  TwoDArray::iterator Matrix::end()  {
    return this->rows.end();
  }

  void Matrix::ensureMatrixHasRowsAndColumns() const {
    if (this->rows.size() == 0 || this->rows[0].size() == 0) {
      throw "Error: matrix must have both rows and columns.";
    }
  }

  void Matrix::ensureMatrixIsUniform() const {
    size_t rowWidth = this->rows[0].size();

    for (auto row : this->rows) {
      if (row.size() != rowWidth) {
        throw "Error: matrix must be uniform.";
      }
    }
  }

  bool operator==(Matrix const &matrix1, Matrix const &matrix2) {
    if (matrix1.getWidth() != matrix2.getWidth() ||
        matrix1.getHeight() != matrix2.getHeight()) {
      return false;
    }

    for (size_t i = 0; i < matrix1.getHeight(); i++) {
      for (size_t j = 0; j < matrix1.getWidth(); j++) {
        if (matrix1[i][j] != matrix2[i][j]) {
          return false;
        }
      }
    }

    return true;
  }

  bool operator!=(Matrix const &matrix1, Matrix const &matrix2) {
    return !(matrix1 == matrix2);
  }
}
