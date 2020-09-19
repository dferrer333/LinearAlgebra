#ifndef MATRIX_H
#define MATRIX_H

#include <iterator>
#include <memory>
#include <vector>

namespace LinearAlgebra {
  using OneDArray = std::vector<float>;
  using TwoDArray = std::vector<std::vector<float>>;

  class Matrix {
    using MatrixPointer = std::unique_ptr<Matrix>;

    public:
      Matrix() = delete;
      Matrix(TwoDArray const &rows);
      Matrix(Matrix const &otherMatrix);

      int getWidth() const;
      int getHeight() const;

      MatrixPointer multiplyAndCopy(Matrix const &otherMatrix) const;
      MatrixPointer divideAndCopy(Matrix const &otherMatrix) const;
      MatrixPointer addAndCopy(Matrix const &otherMatrix) const;
      MatrixPointer subtractAndCopy(Matrix const &otherMatrix) const;

      Matrix& operator*(Matrix const &otherMatrix);
      Matrix& operator/(Matrix const &otherMatrix);
      Matrix& operator+(Matrix const &otherMatrix);
      Matrix& operator-(Matrix const &otherMatrix);

      TwoDArray::const_iterator begin() const;
      TwoDArray::const_iterator end() const;

    private:
      TwoDArray rows;

      void ensureMatrixHasRowsAndColumns() const;
      void ensureMatrixIsUniform() const;
  };

  using MatrixPointer = std::unique_ptr<Matrix>;

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
