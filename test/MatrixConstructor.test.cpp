#include "gtest/gtest.h"
#include "../src/Matrix.h"

namespace {
  namespace LA = LinearAlgebra;

  TEST(MatrixConstructorTests, shouldNotConstructNonUniformMatrix) {
    LA::OneDArray row1 = {1,2,3};
    LA::OneDArray row2 = {3,4};
    LA::TwoDArray rows = {row1,row2};

    ASSERT_ANY_THROW(LA::Matrix matrix(rows));
  }

  TEST(MatrixConstructorTests, shouldNotConstructEmptyRowMatrix) {
    LA::TwoDArray rows(0);

    ASSERT_ANY_THROW(LA::Matrix matrix(rows));
  }

  TEST(MatrixConstructorTests, shouldNotConstructEmptyColumnMatrix) {
    LA::OneDArray row1(0);
    LA::OneDArray row2(0);
    LA::TwoDArray rows = {row1,row2};

    ASSERT_ANY_THROW(LA::Matrix matrix(rows));
  }

  TEST(MatrixConstructorTests, shouldConstructMatrixWithOneElement) {
    LA::OneDArray row1 = {1.5};
    LA::TwoDArray rows = {row1};

    ASSERT_NO_THROW(LA::Matrix matrix(rows));
  }

  TEST(MatrixConstructorTests, shouldConstructVeryLargeMatrix) {
    LA::TwoDArray rows;

    for (size_t i = 0; i < 1000; i++) {
      rows.push_back(LA::OneDArray(1000));
    }

    ASSERT_NO_THROW(LA::Matrix matrix(rows));

    LA::Matrix matrix(rows);
    ASSERT_TRUE(matrix.getWidth() == 1000 || matrix.getHeight() == 1000);
  }

  TEST(MatrixConstructorTests, shouldConstructSquareMatrix) {
    LA::OneDArray row1 = {1,2,3};
    LA::OneDArray row2 = {4,5,6};
    LA::OneDArray row3 = {7.2,3.1,4};
    LA::TwoDArray rows = {row1,row2,row3};

    ASSERT_NO_THROW(LA::Matrix matrix(rows));
  }

  TEST(MatrixConstructorTests, shouldConstructNonSquareMatrix) {
    LA::OneDArray row1 = {1,2};
    LA::OneDArray row2 = {4,5};
    LA::OneDArray row3 = {7.2,3.1};
    LA::TwoDArray rows = {row1,row2,row3};

    ASSERT_NO_THROW(LA::Matrix matrix(rows));
  }

  TEST(MatrixConstructorTests, shouldCopyConstructMatrix) {
    LA::OneDArray row1 = {1};
    LA::TwoDArray rows = {row1};
    LA::Matrix matrix(rows);

    ASSERT_NO_THROW(LA::Matrix copiedMatrix = matrix);
    ASSERT_NO_THROW(LA::Matrix otherCopiedMatrix(matrix));
  }
}
