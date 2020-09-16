#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <memory>

namespace LinearAlgebra {
  template <size_t width, size_t height>
  class Matrix {
    public:
      Matrix() = delete;
      Matrix(const std::array<std::array<float, height>, width>& matrix);
      Matrix(const Matrix& other);

      void multiply(const Matrix& other);

    private:
      std::array<std::array<float, height>, width> rows;
  };

  template<size_t width, size_t height>
  std::shared_ptr<Matrix<width, height>> createIdentityMatrix();

  template<size_t width, size_t height>
  std::shared_ptr<Matrix<width, height>> createTranslationMatrix(
      float xTranslation, float yTranslation, float zTranslation);

  template<size_t width, size_t height>
  std::shared_ptr<Matrix<width, height>> createRotationMatrix(
      float xRotation, float yRotation, float zRotation);

  template<size_t width, size_t height>
  std::shared_ptr<Matrix<width, height>> createScaleMatrix(
      float xScale, float yScale, float zScale);
}

#endif
