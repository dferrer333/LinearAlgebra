#include "gtest/gtest.h"
#include "Matrix.h"

namespace {
  namespace LA = LinearAlgebra;

  TEST(MatrixConstructorTest, shouldNotConstructNonUniformMatrix) {
    LA::OneDArray row1 = {1,2,3};
    LA::OneDArray row2 = {3,4};
    LA::TwoDArray rows = {row1,row2};

    bool succeeded = false;
    try {
      LA::Matrix matrix(rows);
    } catch (...) {
      succeeded = true;
    }

    ASSERT_TRUE(succeeded);
  }

  TEST(MatrixConstructorTest, shouldNotConstructEmptyRowMatrix) {
    LA::TwoDArray rows(0);

    bool succeeded = false;
    try {
      LA::Matrix matrix(rows);
    } catch (...) {
      succeeded = true;
    }

    ASSERT_TRUE(succeeded);
  }

  TEST(MatrixConstructorTest, shouldNotConstructEmptyColumnMatrix) {
    LA::OneDArray row1(0);
    LA::OneDArray row2(0);
    LA::TwoDArray rows = {row1,row2};

    bool succeeded = false;
    try {
      LA::Matrix matrix(rows);
    } catch (...) {
      succeeded = true;
    }

    ASSERT_TRUE(succeeded);
  }

  TEST(MatrixConstructorTest, shouldConstructMatrixWithOneElement) {
    LA::OneDArray row1 = {1.5};
    LA::TwoDArray rows = {row1};

    bool succeeded = false;
    try {
      LA::Matrix matrix(rows);

      succeeded = matrix.getWidth() != 1 || matrix.getHeight() != 1;
    } catch (...) {
      succeeded = false;
    }

    ASSERT_TRUE(succeeded);
  }

  TEST(MatrixConstructorTest, shouldConstructVeryLargeMatrix) {
    LA::TwoDArray rows;

    for (size_t i = 0; i < 1000; i++) {
      rows.push_back(LA::OneDArray(1000));
    }

    bool succeeded = false;
    try {
      LA::Matrix matrix(rows);

      succeeded = matrix.getWidth() != 1000 || matrix.getHeight() != 1000;
    } catch (...) {
      succeeded = false;
    }

    ASSERT_TRUE(succeeded);
  }

  TEST(MatrixConstructorTest, shouldConstructSquareMatrix) {
    LA::OneDArray row1 = {1,2,3};
    LA::OneDArray row2 = {4,5,6};
    LA::OneDArray row3 = {7.2,3.1,4};
    LA::TwoDArray rows = {row1,row2,row3};

    bool succeeded = true;
    try {
      LA::Matrix matrix(rows);
    } catch (...) {
      succeeded = false;
    }

    ASSERT_TRUE(succeeded);
  }

  TEST(MatrixConstructorTest, shouldConstructNonSquareMatrix) {
    LA::OneDArray row1 = {1,2};
    LA::OneDArray row2 = {4,5};
    LA::OneDArray row3 = {7.2,3.1};
    LA::TwoDArray rows = {row1,row2,row3};

    bool succeeded = true;
    try {
      LA::Matrix matrix(rows);
    } catch (...) {
      succeeded = false;
    }

    ASSERT_TRUE(succeeded);
  }

  TEST(MatrixConstructorTest, shouldCopyConstructMatrix) {
    LA::OneDArray row1 = {1};
    LA::TwoDArray rows = {row1};
    LA::Matrix matrix(rows);

    bool succeeded = true;
    try {
      LA::Matrix copiedMatrix = matrix;
      LA::Matrix otherCopiedMatrix(copiedMatrix);
    } catch (...) {
      succeeded = false;
    }

    ASSERT_TRUE(succeeded);
  }
}
