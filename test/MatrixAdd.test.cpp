#include "gtest/gtest.h"
#include "../src/Matrix.h"

namespace {
  namespace LA = LinearAlgebra;

  TEST(MatrixAddTests, shouldNotAddMatricesWithoutColumns) {
    LA::TwoDArray rows = {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2}};
    LA::Matrix matrix1(rows);
    LA::Matrix matrix2(rows);

    matrix2[0] = LA::OneDArray();
    matrix2[1] = LA::OneDArray();
    matrix2[2] = LA::OneDArray();

    ASSERT_ANY_THROW(matrix1 + matrix2);
    ASSERT_ANY_THROW(matrix2 + matrix1);
    ASSERT_ANY_THROW(matrix1 += matrix2);
    ASSERT_ANY_THROW(matrix2 += matrix1);
  }

  TEST(MatrixAddTests, shouldNotAddMatricesWithVariedSizes) {
    LA::TwoDArray rows1 = {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2}};
    LA::Matrix matrix1(rows1);
    LA::TwoDArray rows2 =
        {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2},{1.2,3.2,4.6}};
    LA::Matrix matrix2(rows2);

    ASSERT_ANY_THROW(matrix1 + matrix2);
    ASSERT_ANY_THROW(matrix2 + matrix1);
    ASSERT_ANY_THROW(matrix1 += matrix2);
    ASSERT_ANY_THROW(matrix2 += matrix1);
  }

  TEST(MatrixAddTests, shouldAddMatrixToItself) {
    LA::TwoDArray rows = {{1.5, 1.5, 1.5},{1.5, 1.5, 1.5},{1.5, 1.5, 1.5}};
    LA::Matrix matrix(rows);
    LA::TwoDArray rowsResult =
        {{3.0, 3.0, 3.0},{3.0, 3.0, 3.0},{3.0, 3.0, 3.0}};
    LA::Matrix matrixResult(rowsResult);

    ASSERT_EQ(matrixResult, matrix + matrix);
    ASSERT_EQ(matrixResult, matrix += matrix);
  }

  TEST(MatrixAddTests, shouldAddTwoUniformMatrices) {
    LA::TwoDArray rows = {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2}};
    LA::Matrix matrix1(rows);
    LA::Matrix matrix2(rows);
    
    LA::TwoDArray rowsResult =
        {{2.4,7.32,4.0},{-4.68,18,0.0},{15.6,-10.0,-36.4}};
    LA::Matrix matrixResult(rowsResult);

    ASSERT_EQ(matrixResult, matrix1 + matrix2);
    ASSERT_EQ(matrixResult, matrix2 + matrix1);
    ASSERT_EQ(matrixResult, matrix1 += matrix2);
  }

  TEST(MatrixAddTests, shouldAddTwoNonUniformMatrices) {
    LA::TwoDArray rows = {{1.2,3.66,2.0},{-2.34,9,0.0}};
    LA::Matrix matrix1(rows);
    LA::Matrix matrix2(rows);

    LA::TwoDArray rowsResult = {{2.4,7.32,4.0},{-4.68,18,0.0}};
    LA::Matrix matrixResult(rowsResult);

    ASSERT_EQ(matrixResult, matrix1 + matrix2);
    ASSERT_EQ(matrixResult, matrix2 + matrix1);
    ASSERT_EQ(matrixResult, matrix1 += matrix2);
  }

  TEST(MatrixAddTests, shouldAddTwoSingleElementMatrices) {
    LA::TwoDArray rows = {{1.2}};
    LA::Matrix matrix1(rows);
    LA::Matrix matrix2(rows);

    LA::TwoDArray resultRows = {{2.4}};
    LA::Matrix matrixResult(resultRows);

    ASSERT_EQ(matrixResult, matrix1 + matrix2);
    ASSERT_EQ(matrixResult, matrix2 + matrix1);
    ASSERT_EQ(matrixResult, matrix1 += matrix2);
  }

  TEST(MatrixAddTests, shouldAddTwoLargeMatrices) {
    LA::OneDArray row(100, 13.7);
    LA::TwoDArray rows(100, row);

    LA::Matrix matrix1(rows);
    LA::Matrix matrix2(rows);

    LA::OneDArray resultRow(100, 27.4);
    LA::TwoDArray resultRows(100, resultRow);

    LA::Matrix matrixResult(resultRows);

    ASSERT_EQ(matrixResult, matrix1 + matrix2);
    ASSERT_EQ(matrixResult, matrix2 + matrix1);
    ASSERT_EQ(matrixResult, matrix1 += matrix2);
  }

  TEST(MatrixAddTests, shouldAddTwoNegativeMatrices) {
    LA::OneDArray row(10, -10.5);
    LA::TwoDArray rows(10, row);

    LA::Matrix matrix1(rows);
    LA::Matrix matrix2(rows);

    LA::OneDArray resultRow(10, -21.0);
    LA::TwoDArray resultRows(10, resultRow);

    LA::Matrix matrixResult(resultRows);

    ASSERT_EQ(matrixResult, matrix1 + matrix2);
    ASSERT_EQ(matrixResult, matrix2 + matrix1);
    ASSERT_EQ(matrixResult, matrix1 += matrix2);
  }

  TEST(MatrixAddTests, shouldAddTwoZeroMatrices) {
    LA::OneDArray row(10, 0.0);
    LA::TwoDArray rows(10, row);

    LA::Matrix matrix1(rows);
    LA::Matrix matrix2(rows);

    LA::OneDArray resultRow(10, 0.0);
    LA::TwoDArray resultRows(10, resultRow);

    LA::Matrix matrixResult(resultRows);

    ASSERT_EQ(matrixResult, matrix1 + matrix2);
    ASSERT_EQ(matrixResult, matrix2 + matrix1);
    ASSERT_EQ(matrixResult, matrix1 += matrix2);
  }

  TEST(MatrixAddTests, shouldAddTwoPositiveMatrices) {
    LA::OneDArray row(10, 5.5);
    LA::TwoDArray rows(10, row);

    LA::Matrix matrix1(rows);
    LA::Matrix matrix2(rows);

    LA::OneDArray resultRow(10, 11.0);
    LA::TwoDArray resultRows(10, resultRow);

    LA::Matrix matrixResult(resultRows);

    ASSERT_EQ(matrixResult, matrix1 + matrix2);
    ASSERT_EQ(matrixResult, matrix2 + matrix1);
    ASSERT_EQ(matrixResult, matrix1 += matrix2);
  }

  TEST(MatrixAddTests, shouldAddZeroMatrixToPositiveMatrix) {
    LA::OneDArray row1(10, 0.0);
    LA::TwoDArray rows1(10, row1);

    LA::Matrix matrix1(rows1);

    LA::OneDArray row2(10, 5.5);
    LA::TwoDArray rows2(10, row2);

    LA::Matrix matrix2(rows2);

    LA::OneDArray resultRow(10, 5.5);
    LA::TwoDArray resultRows(10, resultRow);

    LA::Matrix matrixResult(resultRows);

    ASSERT_EQ(matrixResult, matrix1 + matrix2);
    ASSERT_EQ(matrixResult, matrix2 + matrix1);
    ASSERT_EQ(matrixResult, matrix1 += matrix2);
  }

  TEST(MatrixAddTests, shouldAddZeroMatrixToNegativeMatrix) {
    LA::OneDArray row1(10, 0.0);
    LA::TwoDArray rows1(10, row1);

    LA::Matrix matrix1(rows1);

    LA::OneDArray row2(10, -5.5);
    LA::TwoDArray rows2(10, row2);

    LA::Matrix matrix2(rows2);

    LA::OneDArray resultRow(10, -5.5);
    LA::TwoDArray resultRows(10, resultRow);

    LA::Matrix matrixResult(resultRows);

    ASSERT_EQ(matrixResult, matrix1 + matrix2);
    ASSERT_EQ(matrixResult, matrix2 + matrix1);
    ASSERT_EQ(matrixResult, matrix1 += matrix2);
  }

  TEST(MatrixAddTests, shouldAddPositiveMatrixToNegativeMatrix) {
    LA::OneDArray row1(10, 7.5);
    LA::TwoDArray rows1(10, row1);

    LA::Matrix matrix1(rows1);

    LA::OneDArray row2(10, -2.5);
    LA::TwoDArray rows2(10, row2);

    LA::Matrix matrix2(rows2);

    LA::OneDArray resultRow(10, 5.0);
    LA::TwoDArray resultRows(10, resultRow);

    LA::Matrix matrixResult(resultRows);

    ASSERT_EQ(matrixResult, matrix1 + matrix2);
    ASSERT_EQ(matrixResult, matrix2 + matrix1);
    ASSERT_EQ(matrixResult, matrix1 += matrix2);
  }
}
