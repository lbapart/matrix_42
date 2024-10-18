#include "Utils.hpp"
#include <iostream>
#include <vector>

void test_lerp() {
    // Test 1: lerp with double
    {
        double a = 0.0;
        double b = 10.0;
        double t = 0.5;
        double result = utils::lerp(a, b, t);
        double expected = 5.0;

        if (result == expected) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: lerp with Vector
    {
        Vector v1({1.0, 2.0});
        Vector v2({3.0, 4.0});
        double t = 0.5;
        Vector result = utils::lerp(v1, v2, t);
        Vector expected({2.0, 3.0});

        if (result.get_vector() == expected.get_vector()) {
            std::cout << "Test 2 passed." << std::endl;
        } else {
            std::cout << "Test 2 failed." << std::endl;
        }
    }

    // Test 3: lerp with Matrix
    {
        Matrix m1({{1.0, 2.0}, {3.0, 4.0}});
        Matrix m2({{5.0, 6.0}, {7.0, 8.0}});
        double t = 0.5;
        Matrix result = utils::lerp(m1, m2, t);
        Matrix expected({{3.0, 4.0}, {5.0, 6.0}});

        if (result.get_matrix() == expected.get_matrix()) {
            std::cout << "Test 3 passed." << std::endl;
        } else {
            std::cout << "Test 3 failed." << std::endl;
        }
    }

    // Test 4: lerp with t out of bounds
    {
        double a = 0.0;
        double b = 10.0;
        double t = 1.5;

        try {
            double result = utils::lerp(a, b, t);
            std::cout << "Test 4 failed." << std::endl;
        } catch (const std::runtime_error& e) {
            if (std::string(e.what()) == RUNTIME_ERROR) {
                std::cout << "Test 4 passed." << std::endl;
            } else {
                std::cout << "Test 4 failed." << std::endl;
            }
        }
    }
}

int main() {
    test_lerp();
    return 0;
}