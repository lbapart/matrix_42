#include "Matrix.hpp"
#include <iostream>

void test_matrix_rank() {
    // Test 1: Rank of a 3x3 matrix with full rank
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {0.0, 1.0, 4.0}, {5.0, 6.0, 0.0}};
        size_t result = mat.rank();
        size_t expected = 3;

        if (result == expected) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: Rank of a 3x3 matrix with rank 2
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {2.0, 4.0, 6.0}, {1.0, 1.0, 1.0}};
        size_t result = mat.rank();
        size_t expected = 2;

        if (result == expected) {
            std::cout << "Test 2 passed." << std::endl;
        } else {
            std::cout << "Test 2 failed." << std::endl;
        }
    }

    // Test 3: Rank of a 2x3 matrix
    {
        Matrix<double> mat = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
        size_t result = mat.rank();
        size_t expected = 2;

        if (result == expected) {
            std::cout << "Test 3 passed." << std::endl;
        } else {
            std::cout << "Test 3 failed." << std::endl;
        }
    }

    // Test 4: Rank of a 3x2 matrix
    {
        Matrix<double> mat = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
        size_t result = mat.rank();
        size_t expected = 2;

        if (result == expected) {
            std::cout << "Test 4 passed." << std::endl;
        } else {
            std::cout << "Test 4 failed." << std::endl;
        }
    }

    // Test 5: Rank of a 1x1 matrix
    {
        Matrix<double> mat = {{42.0}};
        size_t result = mat.rank();
        size_t expected = 1;

        if (result == expected) {
            std::cout << "Test 5 passed." << std::endl;
        } else {
            std::cout << "Test 5 failed." << std::endl;
        }
    }

    // Test 6: Rank of a 0x0 matrix
    {
        Matrix<double> mat;
        size_t result = mat.rank();
        size_t expected = 0;

        if (result == expected) {
            std::cout << "Test 6 passed." << std::endl;
        } else {
            std::cout << "Test 6 failed." << std::endl;
        }
    }
}

int main() {
    test_matrix_rank();
    return 0;
}