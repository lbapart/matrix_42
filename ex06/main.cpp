#include "Vector.hpp"
#include <iostream>

void test_cross_product() {
    // Test 1: Basic cross product
    {
        Vector<double> v1({1.0, 0.0, 0.0});
        Vector<double> v2({0.0, 1.0, 0.0});
        Vector<double> result = cross_product(v1, v2);
        Vector<double> expected({0.0, 0.0, 1.0});

        if (result.get_vector() == expected.get_vector()) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cout << "Test 1 failed." << std::endl;
        }
    }

    // Test 2: Cross product with parallel vectors
    {
        Vector<double> v1({1.0, 2.0, 3.0});
        Vector<double> v2({2.0, 4.0, 6.0});
        Vector<double> result = cross_product(v1, v2);
        Vector<double> expected({0.0, 0.0, 0.0});

        if (result.get_vector() == expected.get_vector()) {
            std::cout << "Test 2 passed." << std::endl;
        } else {
            std::cout << "Test 2 failed." << std::endl;
        }
    }

    // Test 3: Cross product with anti-parallel vectors
    {
        Vector<double> v1({1.0, 2.0, 3.0});
        Vector<double> v2({-1.0, -2.0, -3.0});
        Vector<double> result = cross_product(v1, v2);
        Vector<double> expected({0.0, 0.0, 0.0});

        if (result.get_vector() == expected.get_vector()) {
            std::cout << "Test 3 passed." << std::endl;
        } else {
            std::cout << "Test 3 failed." << std::endl;
        }
    }

    // Test 4: Cross product with zero vector
    {
        Vector<double> v1({0.0, 0.0, 0.0});
        Vector<double> v2({1.0, 2.0, 3.0});
        Vector<double> result = cross_product(v1, v2);
        Vector<double> expected({0.0, 0.0, 0.0});

        if (result.get_vector() == expected.get_vector()) {
            std::cout << "Test 4 passed." << std::endl;
        } else {
            std::cout << "Test 4 failed." << std::endl;
        }
    }

    // Test 5: Cross product with non-3D vectors (should throw an exception)
    {
        Vector<double> v1({1.0, 2.0});
        Vector<double> v2({3.0, 4.0});
        try {
            Vector<double> result = cross_product(v1, v2);
            std::cout << "Test 5 failed." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Test 5 passed." << std::endl;
        }
    }
}

int main() {
    test_cross_product();
    return 0;
}