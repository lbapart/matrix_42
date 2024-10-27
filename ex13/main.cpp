#include "Matrix.hpp"
#include <iostream>

void test_matrix_inverse() {
    // Test 1: Inverse of a 2x2 matrix
    {
        Matrix<double> mat = {{4.0, 7.0}, {2.0, 6.0}};
        Matrix<double> result = mat.inverse();
        Matrix<double> expected = {{0.6, -0.7}, {-0.2, 0.4}};

        // fails because of small difference
        if (result.get_matrix() == expected.get_matrix()) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: Inverse of a 3x3 matrix
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {0.0, 1.0, 4.0}, {5.0, 6.0, 0.0}};
        Matrix<double> result = mat.inverse();
        Matrix<double> expected = {{-24.0, 18.0, 5.0}, {20.0, -15.0, -4.0}, {-5.0, 4.0, 1.0}};

        if (result.get_matrix() == expected.get_matrix()) {
            std::cout << "Test 2 passed." << std::endl;
        } else {
            std::cout << "Test 2 failed." << std::endl;
        }
    }

    // Test 3: Inverse of a singular matrix (should throw an exception)
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
        try {
            Matrix<double> result = mat.inverse();
            std::cout << "Test 3 failed." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Test 3 passed." << std::endl;
        }
    }

    // Test 4: Inverse of a 1x1 matrix
    {
        Matrix<double> mat = {{42.0}};
        Matrix<double> result = mat.inverse();
        Matrix<double> expected = {{1.0 / 42.0}};

        if (result.get_matrix() == expected.get_matrix()) {
            std::cout << "Test 4 passed." << std::endl;
        } else {
            std::cout << "Test 4 failed." << std::endl;
        }
    }

    // Test 5: Inverse of a non-square matrix (should throw an exception)
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
        try {
            Matrix<double> result = mat.inverse();
            std::cout << "Test 5 failed." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Test 5 passed." << std::endl;
        }
    }
}

int main() {
    test_matrix_inverse();
    return 0;
}