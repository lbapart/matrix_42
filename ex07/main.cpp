#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void test_matrix_multiplication() {
    // Test 1: Matrix multiplication
    {
        Matrix<double> mat1 = {{1.0, 2.0}, {3.0, 4.0}};
        Matrix<double> mat2 = {{2.0, 0.0}, {1.0, 2.0}};
        Matrix<double> result = mat1.mul_mat(mat2);
        Matrix<double> expected = {{4.0, 4.0}, {10.0, 8.0}};

        if (result.get_matrix() == expected.get_matrix()) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: Matrix multiplication with incompatible sizes (should throw an exception)
    {
        Matrix<double> mat1 = {{2.0, 0.0, 1.0}, {1.0, 2.0, 3.0}};
        Matrix<double> mat2 = {{1.0, 2.0}, {3.0, 4.0}};
        try {
            Matrix<double> result = mat1.mul_mat(mat2);
            std::cout << "Test 2 failed." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Test 2 passed." << std::endl;
        }
    }

    // Test 3: Matrix-vector multiplication
    {
        Matrix<double> mat = {{1.0, 2.0}, {3.0, 4.0}};
        Vector<double> vec = {2.0, 1.0};
        Vector<double> result = mat.mul_vec(vec);
        Vector<double> expected = {4.0, 10.0};

        if (result.get_vector() == expected.get_vector()) {
            std::cout << "Test 3 passed." << std::endl;
        } else {
            std::cout << "Test 3 failed." << std::endl;
        }
    }

    // Test 4: Matrix-vector multiplication with incompatible sizes (should throw an exception)
    {
        Matrix<double> mat = {{1.0, 2.0}, {3.0, 4.0}};
        Vector<double> vec = {2.0, 1.0, 3.0};
        try {
            Vector<double> result = mat.mul_vec(vec);
            std::cout << "Test 4 failed." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Test 4 passed." << std::endl;
        }
    }
}

int main() {
    test_matrix_multiplication();
    return 0;
}