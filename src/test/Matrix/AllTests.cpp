#include "MatrixAdd.test.cpp"
#include "MatrixConstructor.test.cpp"
#include "MatrixDivide.test.cpp"
#include "MatrixMultiply.test.cpp"
#include "MatrixSubtract.test.cpp"

namespace Test {
  namespace Matrix {
    bool run_all_tests();
  }
}

bool Test::Matrix::run_all_tests() {
  return (
      Test::Matrix::Add::run_all_tests() &&
      Test::Matrix::Constructor::run_all_tests() &&
      Test::Matrix::Divide::run_all_tests() &&
      Test::Matrix::Multiply::run_all_tests() &&
      Test::Matrix::Subtract::run_all_tests());
}
