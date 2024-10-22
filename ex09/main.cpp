#include "Matrix.hpp"
#include <iostream>

void test_matrix_trace() {
    // Test 1: Trace of a 2x2 matrix
    {
        Matrix<double> mat = {{1.0, 2.0}, {3.0, 4.0}};
        double result = mat.trace();
        double expected = 5.0; // 1 + 4

        if (result == expected) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: Trace of a 3x3 matrix
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
        double result = mat.trace();
        double expected = 15.0; // 1 + 5 + 9

        if (result == expected) {
            std::cout << "Test 2 passed." << std::endl;
        } else {
            std::cout << "Test 2 failed." << std::endl;
        }
    }

    // Test 3: Trace of a non-square matrix (should throw an exception)
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
        try {
            double result = mat.trace();
            std::cout << "Test 3 failed." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Test 3 passed." << std::endl;
        }
    }

    // Test 4: Trace of a 1x1 matrix
    {
        Matrix<double> mat = {{42.0}};
        double result = mat.trace();
        double expected = 42.0;

        if (result == expected) {
            std::cout << "Test 4 passed." << std::endl;
        } else {
            std::cout << "Test 4 failed." << std::endl;
        }
    }

}

int main() {
    test_matrix_trace();
    return 0;
}
