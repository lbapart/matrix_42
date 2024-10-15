#include "Vector.hpp"
#include "Matrix.hpp"

int main() {
    Vector u = {2., 3.};
    Vector v = {5., 7.};
    u.add(v);
    std::cout << u << std::endl;
    // 7 10

    u = {2., 3.};
    v = {5., 7.};
    u.sub(v);
    std::cout << u << std::endl;
    // -3 -4

    u = {2., 3.};
    u.scl(2.);
    std::cout << u << std::endl;
    // 4 6

    Matrix mu = {{1., 2.}, {3., 4.}};
    Matrix mv = {{7., 4.}, {-2., 2.}};
    mu.add(mv);
    std::cout << mu << std::endl;
    // [8, 6]
    // [1, 6]

    mu = {{1., 2.}, {3., 4.}};
    mv = {{7., 4.}, {-2., 2.}};
    mu.sub(mv);
    std::cout << mu << std::endl;
    // [-6, -2]
    // [5, 2]

    mu = {{1., 2.}, {3., 4.}};
    mu.scl(2.);
    std::cout << mu;
    // [2, 4]
    // [6, 8]
}