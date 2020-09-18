#include "../TestLogger.cpp";

namespace Test {
  namespace Matrix {
    namespace Constructor {
      bool run_all_tests();

      bool should_not_construct_non_uniform_matrix();
      bool should_not_construct_matrix_with_empty_rows();
      bool should_not_construct_matrix_with_empty_columns();

      bool should_construct_matrix_with_one_element();
      bool should_construct_very_large_matrix();
      bool should_construct_square_matrix();
      bool should_construct_non_square_matrix();

      bool should_copy_assign_from_another_matrix();
      bool should_copy_construct_from_another_matrix();
    }
  }
}
