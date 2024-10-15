#pragma once

#include <iostream>
#include <vector>
#include "Vector.hpp"
#include <stdexcept>
#include <iomanip>

#define NOT_RECTANGLE "Matrix should be a rectangle"
#define WIDTH 10

using namespace std;

class Matrix
{
    private:
        vector<vector<double>> _matrix;
    public:
        Matrix();
        Matrix(const vector<vector<double>> &from);
        Matrix operator=(const Matrix &other);
        ~Matrix();
        const pair<size_t, size_t>    get_shape() const;
        bool                          is_square() const;
        void                          print() const;
        const vector<vector<double>>  get_matrix() const;
};