#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include "Matrix.hpp"

#define DIFF_VECTOR_SIZES "Sizes of vectors should be equal"

using namespace std;

class Vector
{
    private:
        vector<double> _vector;
    public:
        Vector();
        Vector(const vector<double> &from);
        Vector(const std::initializer_list<double> &from);
        Vector operator=(const Vector &other);
        ~Vector();
        size_t                  get_size() const;
        void                    print() const;
        const vector<double>    get_vector() const;
        void                    add(const Vector &other);
        void                    sub(const Vector &other);
        void                    scl(const double multiplier);

        friend ostream& operator<<(ostream &os, const Vector &vector);
};