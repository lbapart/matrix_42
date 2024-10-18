#include "Vector.hpp"
#include <iostream>

void test_dot_product() {
    // Test 1: Basic dot product
    {
        Vector<double> v1({1.0, 2.0, 3.0});
        Vector<double> v2({4.0, 5.0, 6.0});
        double result = v1.dot(v2);
        double expected = 32.0; // 1*4 + 2*5 + 3*6

        if (result == expected) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: Dot product with zero vector
    {
        Vector<double> v1({1.0, 2.0, 3.0});
        Vector<double> v2({0.0, 0.0, 0.0});
        double result = v1.dot(v2);
        double expected = 0.0;

        if (result == expected) {
            std::cout << "Test 2 passed." << std::endl;
        } else {
            std::cout << "Test 2 failed." << std::endl;
        }
    }

    // Test 3: Dot product with negative values
    {
        Vector<double> v1({1.0, -2.0, 3.0});
        Vector<double> v2({-4.0, 5.0, -6.0});
        double result = v1.dot(v2);
        double expected = -32.0; // 1*(-4) + (-2)*5 + 3*(-6)

        if (result == expected) {
            std::cout << "Test 3 passed." << std::endl;
        } else {
            std::cout << "Test 3 failed." << std::endl;
        }
    }

    // Test 4: Dot product with different sizes (should throw an exception)
    {
        Vector<double> v1({1.0, 2.0, 3.0});
        Vector<double> v2({4.0, 5.0});
        try {
            double result = v1.dot(v2);
            std::cout << "Test 4 failed." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Test 4 passed." << std::endl;
        }
    }
}

int main() {
    test_dot_product();
    return 0;
}