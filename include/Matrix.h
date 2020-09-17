#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
#include <vector>

namespace LinearAlgebra {
  using OneDArray = std::vector<float>;
  using TwoDArray = std::vector<std::vector<float>>;

  class Matrix {
    public:
      Matrix() = delete;
      Matrix(const TwoDArray &matrix);
      Matrix(const Matrix &other);

      void multiply(const Matrix &other);

    private:
      TwoDArray matrix;

      void ensureMatrixHasRowsAndColumns();
      void ensureMatrixIsUniform();
  };

  using MatrixPointer = std::unique_ptr<Matrix>;;

  MatrixPointer createIdentityMatrix(size_t size);

  MatrixPointer createTranslationMatrix(
      float xTranslation, float yTranslation, float zTranslation);

  MatrixPointer createRotationMatrix(
      float xRotation, float yRotation, float zRotation);

  MatrixPointer createScaleMatrix(
      float xScale, float yScale, float zScale);
}

#endif
