#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include "Matrix.h"

namespace LinearAlgebra {
  Matrix& translate_matrix(const Matrix& matrixToTranslate,
                           const Matrix& translationMatrix);
  Matrix& rotate_matrix(const Matrix& matrixToRotate,
                        const Matrix& rotationMatrix);
  Matrix& scale_matrix(const Matrix& matrixToScale,
                       const Matrix& scaleMatrix);
}

#endif
