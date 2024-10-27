#include "Matrix.hpp"
#include <iostream>

void test_matrix_determinant() {
    // Test 1: Determinant of a 1x1 matrix
    {
        Matrix<double> mat = {{42.0}};
        double result = mat.determinant();
        double expected = 42.0;

        if (result == expected) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: Determinant of a 2x2 matrix
    {
        Matrix<double> mat = {{1.0, 2.0}, {3.0, 4.0}};
        double result = mat.determinant();
        double expected = -2.0;

        if (result == expected) {
            std::cout << "Test 2 passed." << std::endl;
        } else {
            std::cout << "Test 2 failed." << std::endl;
        }
    }

    // Test 3: Determinant of a 3x3 matrix
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {0.0, 1.0, 4.0}, {5.0, 6.0, 0.0}};
        double result = mat.determinant();
        double expected = 1.0;

        if (result == expected) {
            std::cout << "Test 3 passed." << std::endl;
        } else {
            std::cout << "Test 3 failed." << std::endl;
        }
    }

    // Test 4: Determinant of a 4x4 matrix
    {
        Matrix<double> mat = {
            {1.0, 2.0, 3.0, 4.0},
            {5.0, 6.0, 7.0, 8.0},
            {9.0, 10.0, 11.0, 12.0},
            {13.0, 14.0, 15.0, 16.0}
        };
        double result = mat.determinant();
        double expected = 0.0;

        if (result == expected) {
            std::cout << "Test 4 passed." << std::endl;
        } else {
            std::cout << "Test 4 failed." << std::endl;
        }
    }

    // Test 5: Determinant of a non-square matrix (should throw an exception)
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
        try {
            double result = mat.determinant();
            std::cout << "Test 5 failed." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Test 5 passed." << std::endl;
        }
    }
}

int main() {
    test_matrix_determinant();
    return 0;
}