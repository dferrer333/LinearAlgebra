#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <memory>

namespace LinearAlgebra {
  template <size_t W, size_t H>
  using TwoDArray = std::array<std::array<float, W>, H>;

  template <size_t W, size_t H>
  using MatrixPointer = std::shared_ptr<TwoDArray<W, H>>;
  
  template <size_t W, size_t H>
  class Matrix {
    public:
      Matrix() = delete;
      Matrix(const TwoDArray<W, H> &matrix);
      Matrix(const Matrix &other);

      void multiply(const Matrix &other);

    private:
      TwoDArray<W, H> matrix;
  };

  template <size_t W, size_t H>
  MatrixPointer<W, H> createIdentityMatrix(size_t size);

  template <size_t W, size_t H>
  MatrixPointer<W, H> createTranslationMatrix(
      float xTranslation, float yTranslation, float zTranslation);

  template <size_t W, size_t H>
  MatrixPointer<W, H> createRotationMatrix(
      float xRotation, float yRotation, float zRotation);

  template <size_t W, size_t H>
  MatrixPointer<W, H> createScaleMatrix(
      float xScale, float yScale, float zScale);
}

#endif
