#include "Vector.hpp"
#include <iostream>

void test_norm_functions() {
    // Test 1: norm_1
    {
        Vector<double> v({1.0, -2.0, 3.0});
        double result = v.norm_1();
        double expected = 6.0; // |1| + |-2| + |3|

        if (result == expected) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: norm
    {
        Vector<double> v({1.0, -2.0, 3.0});
        double result = v.norm();
        double expected = std::sqrt(14.0); // 1^2 + (-2)^2 + 3^2

        if (result == expected) {
            std::cout << "Test 2 passed." << std::endl;
        } else {
            std::cout << "Test 2 failed." << std::endl;
        }
    }

    // Test 3: norm_inf
    {
        Vector<double> v({1.0, -2.0, 3.0});
        double result = v.norm_inf();
        double expected = 3.0; // max(|1|, |-2|, |3|)

        if (result == expected) {
            std::cout << "Test 3 passed." << std::endl;
        } else {
            std::cout << "Test 3 failed." << std::endl;
        }
    }

    // Test 4: norm_1 with zero vector
    {
        Vector<double> v({0.0, 0.0, 0.0});
        double result = v.norm_1();
        double expected = 0.0;

        if (result == expected) {
            std::cout << "Test 4 passed." << std::endl;
        } else {
            std::cout << "Test 4 failed." << std::endl;
        }
    }

    // Test 5: norm with zero vector
    {
        Vector<double> v({0.0, 0.0, 0.0});
        double result = v.norm();
        double expected = 0.0;

        if (result == expected) {
            std::cout << "Test 5 passed." << std::endl;
        } else {
            std::cout << "Test 5 failed." << std::endl;
        }
    }

    // Test 6: norm_inf with zero vector
    {
        Vector<double> v({0.0, 0.0, 0.0});
        double result = v.norm_inf();
        double expected = 0.0;

        if (result == expected) {
            std::cout << "Test 6 passed." << std::endl;
        } else {
            std::cout << "Test 6 failed." << std::endl;
        }
    }
}

int main() {
    test_norm_functions();
    return 0;
}