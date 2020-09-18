#include "../TestLogger.cpp";

namespace Test {
  namespace Matrix {
    namespace Add {
      bool run_all_tests();

      bool should_not_add_matrices_without_columns();
      bool should_not_add_matrices_without_rows();
      bool should_not_add_matrices_with_varied_sizes();

      bool should_add_two_uniform_matrices();
      bool should_add_two_non_uniform_matrices();
      bool should_add_two_matrices_forward_and_reverse();

      bool should_add_two_single_element_matrices();
      bool should_add_two_large_matrices();
    }
  }
}
