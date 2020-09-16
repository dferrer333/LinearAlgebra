#include <iostream>
#include "Matrix.h"

LinearAlgebra::Matrix::Matrix(const LinearAlgebra::TwoDArray &matrix)
    : matrix(matrix) { }

LinearAlgebra::Matrix::Matrix(const LinearAlgebra::Matrix &otherMatrix)
    : matrix(otherMatrix.matrix) { }

void LinearAlgebra::Matrix::multiply(
    const LinearAlgebra::Matrix &otherMatrix) {
  std::cerr << "LinearAlgebra::Matrix::multiply Not Implemented!\n";
}
