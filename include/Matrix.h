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

      Matrix operator*(Matrix const &otherMatrix) const;
      Matrix& operator*=(Matrix const &otherMatrix);
      Matrix operator/(Matrix const &otherMatrix) const;
      Matrix& operator/=(Matrix const &otherMatrix);
      Matrix operator+(Matrix const &otherMatrix) const;
      Matrix& operator+=(Matrix const &otherMatrix);
      Matrix operator-(Matrix const &otherMatrix) const;
      Matrix& operator-=(Matrix const &otherMatrix);
      Matrix& operator=(Matrix const &otherMatrix);

      const OneDArray& operator[](size_t rowIndex) const;
      OneDArray& operator[](size_t rowIndex);

      TwoDArray::iterator begin();
      TwoDArray::iterator end();

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
