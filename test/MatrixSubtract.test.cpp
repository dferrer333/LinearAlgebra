#include "gtest/gtest.h"
#include "../src/Matrix.h"

namespace {
  namespace LA = LinearAlgebra;

  TEST(MatrixSubtractTests, shouldNotSubtractMatricesWithoutColumns) {
    LA::TwoDArray rows = {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2}};
    LA::Matrix matrix1(rows);
    LA::Matrix matrix2(rows);

    matrix2[0] = LA::OneDArray();
    matrix2[1] = LA::OneDArray();
    matrix2[2] = LA::OneDArray();

    ASSERT_ANY_THROW(matrix1 - matrix2);
    ASSERT_ANY_THROW(matrix2 - matrix1);
    ASSERT_ANY_THROW(matrix1 -= matrix2);
    ASSERT_ANY_THROW(matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldNotSubtractMatricesWithVariedSizes) {
    LA::TwoDArray rows1 = {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2}};
    LA::Matrix matrix1(rows1);
    LA::TwoDArray rows2 =
        {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2},{1.2,3.2,4.6}};
    LA::Matrix matrix2(rows2);

    ASSERT_ANY_THROW(matrix1 - matrix2);
    ASSERT_ANY_THROW(matrix2 - matrix1);
    ASSERT_ANY_THROW(matrix1 -= matrix2);
    ASSERT_ANY_THROW(matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldSubtractMatrixFromItself) {
    LA::TwoDArray rows = {{1.5, 1.5, 1.5},{1.5, 1.5, 1.5},{1.5, 1.5, 1.5}};
    LA::Matrix matrix(rows);
    LA::TwoDArray rowsResult =
        {{0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0}};
    LA::Matrix matrixResult(rowsResult);

    ASSERT_EQ(matrixResult, matrix - matrix);
    ASSERT_EQ(matrixResult, matrix -= matrix);
  }

  TEST(MatrixSubtractTests, shouldSubtractTwoUniformMatrices) {
    LA::TwoDArray rows1 = {{1.2,3.66,2.0},{-2.34,9,0.0},{7.8,-5.0,-18.2}};
    LA::Matrix matrix1(rows1);

    LA::TwoDArray rows2 =
        {{14.2,78.999,-13.7},{23.76,19.0,9.347},{6.6,-10.3,-30.0}};
    LA::Matrix matrix2(rows2);

    LA::TwoDArray rowsResult1 =
        {{-13.0,-75.33,15.7},{-26.1,-10.0,-9.347},{1.2,5.3,11.8}};
    LA::Matrix matrixResult1(rowsResult1);

    LA::TwoDArray rowsResult2 =
        {{13.0,75.33,-15.7},{26.1,10.0,9.347},{-1.2,-5.3,-11.8}};
    
    ASSERT_EQ(rowsResult1, matrix1 - matrix2);
    ASSERT_EQ(rowsResult2, matrix2 - matrix1);
    ASSERT_EQ(rowsResult2, matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldSubtractTwoNonUniformMatrices) {
    LA::TwoDArray rows1 = {{1.2,3.66,2.0},{-2.34,9,0.0}};
    LA::Matrix matrix1(rows1);

    LA::TwoDArray rows2 =
        {{14.2,78.999,-13.7},{23.76,19.0,9.347}};
    LA::Matrix matrix2(rows2);

    LA::TwoDArray rowsResult1 =
        {{-13.0,-75.33,15.7},{-26.1,-10.0,-9.347}};
    LA::Matrix matrixResult1(rowsResult1);

    LA::TwoDArray rowsResult2 =
        {{13.0,75.33,-15.7},{26.1,10.0,9.347}};
    LA::Matrix matrixResult2(rowsResult2);
    
    ASSERT_EQ(matrixResult1, matrix1 - matrix2);
    ASSERT_EQ(matrixResult2, matrix2 - matrix1);
    ASSERT_EQ(matrixResult2, matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldSubtractTwoSingleElementMatrices) {
    LA::Matrix matrix1 = LA::TwoDArray(1, (LA::OneDArray(1, 1.78)));
    LA::Matrix matrix2 = LA::TwoDArray(1, (LA::OneDArray(1, 0.34)));
    LA::Matrix matrixResult1 = LA::TwoDArray(1, LA::OneDArray(1, 0.44));
    LA::Matrix matrixResult2 = LA::TwoDArray(1, LA::OneDArray(1, -0.44));

    ASSERT_EQ(matrixResult1, matrix1 - matrix2);
    ASSERT_EQ(matrixResult2, matrix2 - matrix1);
    ASSERT_EQ(matrixResult2, matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldSubtractTwoLargeMatrices) {
    LA::Matrix matrix1 = LA::TwoDArray(100, (LA::OneDArray(100, 10.78)));
    LA::Matrix matrix2 = LA::TwoDArray(100, (LA::OneDArray(100, 0.34)));
    LA::Matrix matrixResult1 = LA::TwoDArray(100, LA::OneDArray(100, 10.44));
    LA::Matrix matrixResult2 = LA::TwoDArray(100, LA::OneDArray(100, -10.44));
  
    ASSERT_EQ(matrixResult1, matrix1 - matrix2);
    ASSERT_EQ(matrixResult2, matrix2 - matrix1);
    ASSERT_EQ(matrixResult2, matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldSubtractTwoNegativeMatrices) {
    LA::Matrix matrix1 = LA::TwoDArray(5, (LA::OneDArray(5, -10.78)));
    LA::Matrix matrix2 = LA::TwoDArray(5, (LA::OneDArray(5, -0.34)));
    LA::Matrix matrixResult1 = LA::TwoDArray(5, LA::OneDArray(5, -10.44));
    LA::Matrix matrixResult2 = LA::TwoDArray(5, LA::OneDArray(5, 10.44));
  
    ASSERT_EQ(matrixResult1, matrix1 - matrix2);
    ASSERT_EQ(matrixResult2, matrix2 - matrix1);
    ASSERT_EQ(matrixResult2, matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldSubtractTwoZeroMatrices) {
    LA::Matrix matrix1 = LA::TwoDArray(5, (LA::OneDArray(5, 0.0)));
    LA::Matrix matrix2 = LA::TwoDArray(5, (LA::OneDArray(5, 0.0)));
    LA::Matrix matrixResult1 = LA::TwoDArray(5, LA::OneDArray(5, 0.0));
  
    ASSERT_EQ(matrixResult1, matrix1 - matrix2);
    ASSERT_EQ(matrixResult1, matrix2 - matrix1);
    ASSERT_EQ(matrixResult1, matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldSubtractTwoPositiveMatrices) {
    LA::Matrix matrix1 = LA::TwoDArray(5, (LA::OneDArray(5, 120.78)));
    LA::Matrix matrix2 = LA::TwoDArray(5, (LA::OneDArray(5, 13.34)));
    LA::Matrix matrixResult1 = LA::TwoDArray(5, LA::OneDArray(5, 107.44));
    LA::Matrix matrixResult2 = LA::TwoDArray(5, LA::OneDArray(5, -107.44));
  
    ASSERT_EQ(matrixResult1, matrix1 - matrix2);
    ASSERT_EQ(matrixResult2, matrix2 - matrix1);
    ASSERT_EQ(matrixResult2, matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldSubtractPositiveMatrixFromZeroMatrix) {
    LA::Matrix matrix1 = LA::TwoDArray(5, (LA::OneDArray(5, 120.78)));
    LA::Matrix matrix2 = LA::TwoDArray(5, (LA::OneDArray(5, 0.0)));
    LA::Matrix matrixResult1 = LA::TwoDArray(5, LA::OneDArray(5, 120.78));
    LA::Matrix matrixResult2 = LA::TwoDArray(5, LA::OneDArray(5, -120.78));
  
    ASSERT_EQ(matrixResult1, matrix1 - matrix2);
    ASSERT_EQ(matrixResult2, matrix2 - matrix1);
    ASSERT_EQ(matrixResult2, matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldSubtractNegativeMatrixFromZeroMatrix) {
    LA::Matrix matrix1 = LA::TwoDArray(5, (LA::OneDArray(5, -120.78)));
    LA::Matrix matrix2 = LA::TwoDArray(5, (LA::OneDArray(5, 0.0)));
    LA::Matrix matrixResult1 = LA::TwoDArray(5, LA::OneDArray(5, -120.78));
    LA::Matrix matrixResult2 = LA::TwoDArray(5, LA::OneDArray(5, 120.78));
  
    ASSERT_EQ(matrixResult1, matrix1 - matrix2);
    ASSERT_EQ(matrixResult2, matrix2 - matrix1);
    ASSERT_EQ(matrixResult2, matrix2 -= matrix1);
  }

  TEST(MatrixSubtractTests, shouldSubtractNegativeMatrixFromPositiveMatrix) {
    LA::Matrix matrix1 = LA::TwoDArray(5, (LA::OneDArray(5, -120.78)));
    LA::Matrix matrix2 = LA::TwoDArray(5, (LA::OneDArray(5, 50.24)));
    LA::Matrix matrixResult1 = LA::TwoDArray(5, LA::OneDArray(5, -171.02));
    LA::Matrix matrixResult2 = LA::TwoDArray(5, LA::OneDArray(5, 171.02));
  
    ASSERT_EQ(matrixResult1, matrix1 - matrix2);
    ASSERT_EQ(matrixResult2, matrix2 - matrix1);
    ASSERT_EQ(matrixResult2, matrix2 -= matrix1);
  }
}
