#include <array>
#include "Matrix.h"

template <size_t W, size_t H>
LinearAlgebra::MatrixPointer<W, H> LinearAlgebra::createIdentityMatrix(
    size_t matrixSize) {
  LinearAlgebra::TwoDArray<matrixSize, matrixSize> identityMatrix();
  std::array<float, matrixSize> row;
  for (size_t i = 0; i < matrixSize; i++) {
    for (size_t j = 0; j < matrixSize; j++) {
      if (i == j) {
        row[j] = 1;
      } else {
        row[j] = 0;
      }
    }

    identityMatrix[i] = row;
  }

  return std::make_shared<LinearAlgebra::Matrix<matrixSize, matrixSize>>(
      identityMatrix);
}
