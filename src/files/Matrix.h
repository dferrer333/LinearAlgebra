#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

namespace LinearAlgebra {
  // TODO
  class Matrix {
    public:
      Matrix();

    private:
      std::vector<std::vector<long>> rows;
  };
}

#endif
