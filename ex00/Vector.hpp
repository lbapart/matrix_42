#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Matrix.hpp"

using namespace std;

class Vector
{
    private:
        vector<double> _vector;
    public:
        Vector();
        Vector(const vector<double> &from);
        Vector operator=(const Vector &other);
        ~Vector();
        size_t                  get_size() const;
        void                    print() const;
        const vector<double>    get_vector() const;
        friend ostream& operator<<(ostream &os, const Vector &vector);
};