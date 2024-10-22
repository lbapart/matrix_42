#include "Matrix.hpp"
#include <iostream>

void test_matrix_row_echelon() {
    // Test 1: Row echelon form of a 3x3 matrix
    {
        Matrix<double> mat = {{1.0, 2.0, -1.0}, {2.0, 3.0, 1.0}, {3.0, 5.0, 2.0}};
        Matrix<double> result = mat.row_echelon();
        Matrix<double> expected = {{1.0, 2.0, -1.0}, {0.0, -1.0, 3.0}, {0.0, 0.0, 2.0}};
        if (result.get_matrix() == expected.get_matrix()) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: Row echelon form of a 2x3 matrix
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
        Matrix<double> result = mat.row_echelon();
        Matrix<double> expected = {{1.0, 2.0, 3.0}, {0.0, -3.0, -6.0}};

        if (result.get_matrix() == expected.get_matrix()) {
            std::cout << "Test 2 passed." << std::endl;
        } else {
            std::cout << "Test 2 failed." << std::endl;
        }
    }

    // Test 3: Row echelon form of a 3x2 matrix
    {
        Matrix<double> mat = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
        Matrix<double> result = mat.row_echelon();
        Matrix<double> expected = {{1.0, 2.0}, {0.0, -2.0}, {0.0, 0.0}};
        if (result.get_matrix() == expected.get_matrix()) {
            std::cout << "Test 3 passed." << std::endl;
        } else {
            std::cout << "Test 3 failed." << std::endl;
        }
    }

    // Test 4: Row echelon form of a 1x1 matrix
    {
        Matrix<double> mat = {{42.0}};
        Matrix<double> result = mat.row_echelon();
        Matrix<double> expected = {{42.0}};

        if (result.get_matrix() == expected.get_matrix()) {
            std::cout << "Test 4 passed." << std::endl;
        } else {
            std::cout << "Test 4 failed." << std::endl;
        }
    }

}

int main() {
    test_matrix_row_echelon();
    return 0;
}