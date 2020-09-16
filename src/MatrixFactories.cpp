#include "Matrix.h"
#include <vector>

LinearAlgebra::MatrixPointer LinearAlgebra::createIdentityMatrix(
    size_t matrixSize) {
  LinearAlgebra::TwoDArray identityMatrix(matrixSize);
  std::vector<float> row(matrixSize);
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

  return std::make_shared<LinearAlgebra::Matrix>(identityMatrix);
}
