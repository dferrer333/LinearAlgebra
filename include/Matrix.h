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
      Matrix(const TwoDArray &matrix);
      Matrix(const Matrix &other);
      Matrix(const MatrixPointer &otherPointer);

      MatrixPointer multiplyAndCopy(MatrixPointer const &other) const;
      MatrixPointer divideAndCopy(MatrixPointer const &other) const;
      MatrixPointer addAndCopy(MatrixPointer const &other) const;
      MatrixPointer subtractAndCopy(MatrixPointer const &other) const;

      MatrixPointer& operator*(MatrixPointer const &other);
      MatrixPointer& operator/(MatrixPointer const &other);
      MatrixPointer& operator+(MatrixPointer const &other);
      MatrixPointer& operator-(MatrixPointer const &other);

    private:
      TwoDArray matrix;

      void ensureMatrixHasRowsAndColumns() const;
      void ensureMatrixIsUniform() const;
  };

  MatrixPointer createIdentityMatrix(size_t size);

  MatrixPointer createTranslationMatrix(
      float xTranslation, float yTranslation, float zTranslation);

  MatrixPointer createRotationMatrix(
      float xRotation, float yRotation, float zRotation);

  MatrixPointer createScaleMatrix(
      float xScale, float yScale, float zScale);
}

#endif
