#include "Vector.hpp"

using namespace std;

void test_linear_combination() {
    // Test 1: Basic linear combination
    {
        Vector v1({1.0, 2.0});
        Vector v2({3.0, 4.0});
        vector<Vector<double>> vectors;
        vectors.push_back(v1);
        vectors.push_back(v2);
        initializer_list<double> scalars = {2.0, 3.0};
        Vector result = linear_combination(vectors, scalars);
        vector<double> expected = {11.0, 16.0};

        if (result.get_vector() == expected) {
            cout << "Test 1 passed." << endl;
        } else {
            cout << "Test 1 failed." << endl;
        }
    }


    // Test 2: Different sizes of vectors and scalars
    {
        Vector v1({1.0, 2.0});
        Vector v2({3.0, 4.0});
        vector<Vector<double>> vectors = {v1, v2};
        initializer_list<double> scalars = {2.0};

        try {
            linear_combination(vectors, scalars);
            cout << "Test 2 failed." << endl;
        } catch (const std::runtime_error& e) {
            cout << "Test 2 passed." << endl;
        }
    }

    // Test 3: Vector size mismatch
    {
        Vector v1({1.0, 2.0});
        Vector v2({3.0, 4.0, 5.0});
        vector<Vector<double>> vectors = {v1, v2};
        initializer_list<double> scalars = {2.0, 3.0};

        try {
            linear_combination(vectors, scalars);
            cout << "Test 3 failed." << endl;
        } catch (const std::runtime_error& e) {
            cout << "Test 3 passed." << endl;
        }
    }
}

int main() {
    test_linear_combination();
    return 0;
}