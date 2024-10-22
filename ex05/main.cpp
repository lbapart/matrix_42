#include "Vector.hpp"
#include <iostream>
#include <cmath>

void test_angle_cos() {
    // Test 1: Basic angle cosine
    {
        Vector<double> v1({1.0, 0.0});
        Vector<double> v2({0.0, 1.0});
        double result = angle_cos(v1, v2);
        double expected = 0.0; // Cosine of 90 degrees

        if (std::abs(result - expected) < 1e-9) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: Angle cosine with same vectors
    {
        Vector<double> v1({1.0, 2.0, 3.0});
        Vector<double> v2({1.0, 2.0, 3.0});
        double result = angle_cos(v1, v2);
        double expected = 1.0; // Cosine of 0 degrees

        if (std::abs(result - expected) < 1e-9) {
            std::cout << "Test 2 passed." << std::endl;
        } else {
            std::cout << "Test 2 failed." << std::endl;
        }
    }

    // Test 3: Angle cosine with opposite vectors
    {
        Vector<double> v1({1.0, 2.0, 3.0});
        Vector<double> v2({-1.0, -2.0, -3.0});
        double result = angle_cos(v1, v2);
        double expected = -1.0; // Cosine of 180 degrees

        if (std::abs(result - expected) < 1e-9) {
            std::cout << "Test 3 passed." << std::endl;
        } else {
            std::cout << "Test 3 failed." << std::endl;
        }
    }

    // Test 4: Angle cosine with zero vector (should throw an exception)
    {
        Vector<double> v1({0.0, 0.0, 0.0});
        Vector<double> v2({1.0, 2.0, 3.0});
        try {
            double result = angle_cos(v1, v2);
            std::cout << "Test 4 failed." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Test 4 passed." << std::endl;
        }
    }
}

int main() {
    test_angle_cos();
    return 0;
}