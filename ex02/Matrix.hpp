#pragma once

#include <iostream>
#include <vector>
#include "Vector.hpp"
#include <stdexcept>
#include <iomanip>
#include <initializer_list>

#define NOT_RECTANGLE "Matrix should be a rectangle"
#define DIFF_MATRIX_SIZES "Sizes of the matrixes should be equal"
#define WIDTH 5

using namespace std;

class Matrix
{
    private:
        vector<vector<double> > _matrix;
    public:
        Matrix();
        Matrix(const vector<vector<double> > &from);
        Matrix(const std::initializer_list<std::initializer_list<double> > &list);
        Matrix(const Matrix &other);
        Matrix operator=(const Matrix &other);
        Matrix operator+(const Matrix &other) const;
        Matrix& operator+=(const Matrix &other);
        Matrix operator*(const double scalar) const;
        Matrix& operator*=(const double scalar);
        ~Matrix();
        const pair<size_t, size_t>    get_shape() const;
        bool                          is_square() const;
        void                          print() const;
        const vector<vector<double> >  get_matrix() const;
        void                          add(const Matrix &other);
        void                          sub(const Matrix &other);
        void                          scl(const double multiplier);
        friend ostream& operator<<(ostream &os, const Matrix &matrix);
};

Matrix operator*(const double scalar, const Matrix &matrix);