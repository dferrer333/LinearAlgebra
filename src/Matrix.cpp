#include <array>
#include "Matrix.h"
#include <memory>

template <size_t W, size_t H>
LinearAlgebra::Matrix<W, H>::Matrix(
    const LinearAlgebra::TwoDArray<W, H>& matrix) : this.matrix(matrix) { }

template <size_t W, size_t H>
LinearAlgebra::Matrix<W, H>::Matrix(
    const LinearAlgebra::Matrix<W, H> &otherMatrix)
        : this.matrix(otherMatrix.matrix) { }

template <size_t W, size_t H>
void LinearAlgebra::Matrix::multiply(
    const LinearAlgebra::Matrix<W, H> &otherMatrix) {
  // TODO
}
