#include <cmath>
#include "Matrix.h"

namespace LinearAlgebra {
  Matrix::Matrix(TwoDArray const &rows)
      : rows(rows) {
    this->ensureMatrixHasRowsAndColumns();
    this->ensureMatrixIsUniform();
  }

  Matrix::Matrix(Matrix const &otherMatrix)
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
    ensureMatricesHavePositiveHeightAndWidth(*this, otherMatrix);
    ensureMatricesHaveEqualHeightAndWidth(*this, otherMatrix);

    return operateAndMakeCopy(std::plus<MatrixElement>(), otherMatrix);
  }

  Matrix& Matrix::operator+=(Matrix const &otherMatrix) {
    ensureMatricesHavePositiveHeightAndWidth(*this, otherMatrix);
    ensureMatricesHaveEqualHeightAndWidth(*this, otherMatrix);

    return operateAndAssignToSelf(std::plus<MatrixElement>(), otherMatrix);
  }

  Matrix Matrix::operator-(Matrix const &otherMatrix) const {
    ensureMatricesHavePositiveHeightAndWidth(*this, otherMatrix);
    ensureMatricesHaveEqualHeightAndWidth(*this, otherMatrix);

    return operateAndMakeCopy(std::minus<MatrixElement>(), otherMatrix);
  }

  Matrix& Matrix::operator-=(Matrix const &otherMatrix) {
    ensureMatricesHavePositiveHeightAndWidth(*this, otherMatrix);
    ensureMatricesHaveEqualHeightAndWidth(*this, otherMatrix);

    return operateAndAssignToSelf(std::minus<MatrixElement>(), otherMatrix);
  }

  Matrix& Matrix::operator=(Matrix const &otherMatrix) {
    this->rows = otherMatrix.rows;
    return *this;
  }

  template <class Operation>
  Matrix Matrix::operateAndMakeCopy(
      Operation operate, Matrix const &otherMatrix) const {
    TwoDArray summedMatrix;
    OneDArray temporaryRow(otherMatrix.getWidth());
    for (size_t i = 0; i < otherMatrix.getHeight(); i++) {
      for (size_t j = 0; j < otherMatrix.getWidth(); j++) {
        temporaryRow[j] = operate((*this)[i][j], otherMatrix[i][j]);
      }

      summedMatrix.push_back(temporaryRow);
    }

    return Matrix(summedMatrix);
  }

  template <class Operation>
  Matrix& Matrix::operateAndAssignToSelf(
      Operation operate, Matrix const &otherMatrix) {
    for (size_t i = 0; i < otherMatrix.getHeight(); i++) {
      for (size_t j = 0; j < otherMatrix.getWidth(); j++) {
        (*this)[i][j] = operate((*this)[i][j], otherMatrix[i][j]);
      }
    }

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

  void ensureMatricesHavePositiveHeightAndWidth(
      Matrix const &matrix1, Matrix const &matrix2) {
    if (matrix1.getHeight() == 0 || matrix2.getHeight() == 0 ||
        matrix1.getWidth() == 0 || matrix2.getWidth() == 0) {
      throw "Error: matrices must have positive width and height.";
    }
  }

  void ensureMatricesHaveEqualHeightAndWidth(
      Matrix const &matrix1, Matrix const &matrix2) {
    if (matrix1.getWidth() != matrix2.getWidth() ||
        matrix1.getHeight() != matrix2.getHeight()) {
      throw "Error: matrices must have equal heights and widths when adding.";
    }
  }

  bool operator==(Matrix const &matrix1, Matrix const &matrix2) {
    if (matrix1.getWidth() != matrix2.getWidth() ||
        matrix1.getHeight() != matrix2.getHeight()) {
      return false;
    }

    for (size_t i = 0; i < matrix1.getHeight(); i++) {
      for (size_t j = 0; j < matrix1.getWidth(); j++) {
        if (std::abs(matrix1[i][j] - matrix2[i][j]) >= EQ_PRECISION) {
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
