#ifndef MATRIX_H
#define MATRIX_H

#include <array>

namespace LinearAlgebra {
  template <size_t width, size_t height>
  class Matrix {
    public:
      // creates identity matrix of specified size
      Matrix();
      // constructs matrix with provided 2-D Array
      Matrix(const std::array<std::array<float, height>, width>& matrix);
      Matrix(const Matrix& other);

      void multiply(const Matrix& other);

    private:
      std::array<std::array<float, height>, width> rows;
  };

  template<size_t width, size_t height>
  Matrix<width, height> createIdentityMatrix();

  template<size_t width, size_t height>
  Matrix<width, height> createTranslationMatrix(
      float xTranslation, float yTranslation, float zTranslation);

  template<size_t width, size_t height>
  Matrix<width, height> createRotationMatrix(
      float xRotation, float yRotation, float zRotation);

  template<size_t width, size_t height>
  Matrix<width, height> createScaleMatrix(
      float xScale, float yScale, float zScale);
}

#endif
