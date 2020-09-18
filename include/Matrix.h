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
      Matrix(TwoDArray const &matrix);
      Matrix(Matrix const &other);
      Matrix(MatrixPointer const &otherPointer);

      int getWidth();
      int getHeight();

      Matrix multiplyAndCopy(Matrix const &other) const;
      Matrix divideAndCopy(Matrix const &other) const;
      Matrix addAndCopy(Matrix const &other) const;
      Matrix subtractAndCopy(Matrix const &other) const;

      Matrix& operator*(Matrix const &other);
      Matrix& operator/(Matrix const &other);
      Matrix& operator+(Matrix const &other);
      Matrix& operator-(Matrix const &other);

    private:
      TwoDArray matrix;

      void ensureMatrixHasRowsAndColumns() const;
      void ensureMatrixIsUniform() const;
  };

  MatrixPointer createMatrixCopyOnHeap(Matrix const &matrixToCopy);

  MatrixPointer createIdentityMatrix(size_t size);

  MatrixPointer createTranslationMatrix(
      float xTranslation, float yTranslation, float zTranslation);

  MatrixPointer createRotationMatrix(
      float xRotation, float yRotation, float zRotation);

  MatrixPointer createScaleMatrix(
      float xScale, float yScale, float zScale);
}

#endif
