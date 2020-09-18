#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
#include <vector>

namespace LinearAlgebra {
  using OneDArray = std::vector<float>;
  using TwoDArray = std::vector<std::vector<float>>;
  using MatrixPointer = std::unique_ptr<Matrix>;

  class Matrix {
    public:
      Matrix() = delete;
      Matrix(TwoDArray const &rows);
      Matrix(Matrix const &otherMatrix);
      Matrix(MatrixPointer const &otherMatrixPointer);

      int getWidth();
      int getHeight();

      Matrix multiplyAndCopy(Matrix const &otherMatrix) const;
      Matrix divideAndCopy(Matrix const &otherMatrix) const;
      Matrix addAndCopy(Matrix const &otherMatrix) const;
      Matrix subtractAndCopy(Matrix const &otherMatrix) const;

      Matrix& operator*(Matrix const &otherMatrix);
      Matrix& operator/(Matrix const &otherMatrix);
      Matrix& operator+(Matrix const &otherMatrix);
      Matrix& operator-(Matrix const &otherMatrix);

    private:
      TwoDArray rows;
      int matrixWidth;
      int matrixHeight;

      void ensureMatrixHasRowsAndColumns() const;
      void ensureMatrixIsUniform() const;
  };

  MatrixPointer createMatrixCopyOnHeap(Matrix const &otherMatrix);

  MatrixPointer createIdentityMatrix(size_t size);

  MatrixPointer createTranslationMatrix(
      float xTranslation, float yTranslation, float zTranslation);

  MatrixPointer createRotationMatrix(
      float xRotation, float yRotation, float zRotation);

  MatrixPointer createScaleMatrix(
      float xScale, float yScale, float zScale);
}

#endif
