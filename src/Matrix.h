#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <memory>

namespace LinearAlgebra {
  template <size_t W, size_t H>
  using TwoDArray = std::array<std::array<float, W>, H>;
  
  template <size_t W, size_t H>
  class Matrix {
    public:
      Matrix() = delete;
      Matrix(const TwoDArray<W, H> &matrix);
      Matrix(const Matrix &other);

      void multiply(const Matrix &other);

    private:
      std::shared_ptr<TwoDArray<W, H> matrix;
  };

  std::shared_ptr<Matrix<W, H>> createIdentityMatrix();

  std::shared_ptr<Matrix<W, H>> createTranslationMatrix(
      float xTranslation, float yTranslation, float zTranslation);

  std::shared_ptr<Matrix<W, H>> createRotationMatrix(
      float xRotation, float yRotation, float zRotation);

  std::shared_ptr<Matrix<W, H>> createScaleMatrix(
      float xScale, float yScale, float zScale);
}

#endif
