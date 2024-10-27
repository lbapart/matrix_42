#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include "Vector.hpp"

#define NOT_RECTANGLE "Matrix should be a rectangle"
#define DIFF_MATRIX_SIZES "Sizes of the matrices should be equal"
#define WIDTH 10

using namespace std;

template<typename T>
class Matrix
{
    private:
        vector<vector<T>>   _matrix;
        void                _add_row(size_t affected, size_t to_add, double scalar);
        void                _put_non_zero_rows_on_top(size_t row, size_t col);

    public:
        Matrix();
        Matrix(size_t row, size_t col);
        Matrix(const vector<vector<T>> &from);
        Matrix(const std::initializer_list<std::initializer_list<T>> &list);
        Matrix(const Matrix &other);
        Matrix &operator=(const Matrix &other);
        Matrix operator+(const Matrix &other) const;
        Matrix &operator+=(const Matrix &other);
        Matrix operator*(const T scalar) const;
        Matrix &operator*=(const T scalar);
        ~Matrix();
        Vector<T>                   to_vector();
        const pair<size_t, size_t>  get_shape() const;
        bool                        is_square() const;
        void                        print() const;
        const vector<vector<T>>     get_matrix() const;
        void                        add(const Matrix &other);
        void                        sub(const Matrix &other);
        void                        scl(const T multiplier);
        Matrix                      mul_mat(const Matrix& other);
        Vector<T>                   mul_vec(const Vector<T>& other);
        const T                     trace() const;
        Matrix                      transpose() const;
        Matrix                      row_echelon() const;
        const T                     determinant() const;

        template<typename U>
        friend ostream &operator<<(ostream &os, const Matrix<U> &matrix);
};

template<typename T>
Matrix<T>::Matrix()
{
}

template<typename T>
Matrix<T>::Matrix(const vector<vector<T>> &from)
{
    if (from.size() == 0)
        return;
    size_t row_size = from[0].size();

    for (size_t i = 0; i < from.size(); ++i)
    {
        if (row_size != from[i].size())
            throw std::runtime_error(NOT_RECTANGLE);
    }
    this->_matrix = from;
}

template<typename T>
Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>> &list)
{
    if (list.size() == 0)
        return;
    for (const auto& row : list)
    {
        this->_matrix.push_back(row);
    }
    size_t row_size = this->_matrix[0].size();

    for (size_t i = 0; i < this->_matrix.size(); ++i)
    {
        if (row_size != this->_matrix[i].size())
        {
            this->_matrix.clear();
            throw std::runtime_error(NOT_RECTANGLE);
        }
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix &other)
{
    this->_matrix = other._matrix;
}

template<typename T>
Matrix<T>::Matrix(size_t row, size_t col)
{
    this->_matrix = vector<vector<T>>(row, vector<T>(col));
}

template<typename T>
Matrix<T>::~Matrix()
{
    this->_matrix.clear();
}

template<typename T>
Vector<T> Matrix<T>::to_vector()
{
    auto shape = this->get_shape();
    if (shape.second != 1)
        throw std::runtime_error(RUNTIME_ERROR);

    vector<T> init_list;
    for (size_t i = 0; i < shape.first; ++i)
    {
        init_list.push_back(this->_matrix[i][0]);
    }
    return Vector(init_list);
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix &other)
{
    if (this == &other)
        return *this; // Handle self-assignment
    this->_matrix = other._matrix;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &other) const
{
    if (other.get_shape() != this->get_shape())
        throw std::runtime_error(DIFF_MATRIX_SIZES);

    Matrix result(*this);
    for (size_t i = 0; i < this->_matrix.size(); ++i)
    {
        for (size_t j = 0; j < this->_matrix[i].size(); ++j)
        {
            result._matrix[i][j] += other._matrix[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix &other)
{
    if (other.get_shape() != this->get_shape())
        throw std::runtime_error(DIFF_MATRIX_SIZES);

    for (size_t i = 0; i < this->_matrix.size(); ++i)
    {
        for (size_t j = 0; j < this->_matrix[i].size(); ++j)
        {
            this->_matrix[i][j] += other._matrix[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T scalar) const
{
    Matrix result(*this);
    for (size_t i = 0; i < result._matrix.size(); ++i)
    {
        for (size_t j = 0; j < result._matrix[i].size(); ++j)
        {
            result._matrix[i][j] *= scalar;
        }
    }
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T scalar)
{
    for (size_t i = 0; i < this->_matrix.size(); ++i)
    {
        for (size_t j = 0; j < this->_matrix[i].size(); ++j)
        {
            this->_matrix[i][j] *= scalar;
        }
    }
    return *this;
}

template<typename T>
const pair<size_t, size_t> Matrix<T>::get_shape() const
{
    if (this->_matrix.size() == 0)
        return make_pair(0, 0);
    return make_pair(this->_matrix.size(), this->_matrix[0].size());
}

template<typename T>
bool Matrix<T>::is_square() const
{
    if (this->_matrix.size() == 0)
        return true;
    return this->_matrix.size() == this->_matrix[0].size();
}

template<typename T>
void Matrix<T>::print() const
{
    for (size_t i = 0; i < this->_matrix.size(); ++i)
    {
        for (size_t j = 0; j < this->_matrix[i].size(); ++j)
        {
            std::cout << std::setw(WIDTH) << this->_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
const vector<vector<T>> Matrix<T>::get_matrix() const
{
    return this->_matrix;
}

template<typename T>
ostream& operator<<(ostream &os, const Matrix<T> &matrix)
{
    for (size_t i = 0; i < matrix._matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix._matrix[i].size(); ++j)
        {
            os << std::setw(WIDTH) << matrix._matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

template<typename T>
Matrix<T> operator*(const T scalar, const Matrix<T> &matrix)
{
    return matrix * scalar;
}

template<typename T>
void Matrix<T>::add(const Matrix &other)
{
    if (this->get_shape() != other.get_shape())
        throw std::runtime_error(DIFF_MATRIX_SIZES);
    
    for (size_t i = 0; i < this->_matrix.size(); ++i)
    {
        for (size_t j = 0; j < this->_matrix[i].size(); ++j)
        {
            this->_matrix[i][j] += other._matrix[i][j];
        }
    }
}

template<typename T>
void Matrix<T>::sub(const Matrix &other)
{
    if (this->get_shape() != other.get_shape())
        throw std::runtime_error(DIFF_MATRIX_SIZES);
    
    for (size_t i = 0; i < this->_matrix.size(); ++i)
    {
        for (size_t j = 0; j < this->_matrix[i].size(); ++j)
        {
            this->_matrix[i][j] -= other._matrix[i][j];
        }
    }
}

template<typename T>
void Matrix<T>::scl(const T multiplier)
{    
    for (size_t i = 0; i < this->_matrix.size(); ++i)
    {
        for (size_t j = 0; j < this->_matrix[i].size(); ++j)
        {
            this->_matrix[i][j] *= multiplier;
        }
    }
}

template<typename T>
Matrix<T> Matrix<T>::mul_mat(const Matrix<T>& other)
{
    auto this_shape = this->get_shape();
    auto other_shape = other.get_shape();

    if (this_shape.second != other_shape.first)
        throw std::runtime_error(RUNTIME_ERROR);

    Matrix<T> result(this_shape.first, other_shape.second);

    for (size_t i = 0; i < this_shape.first; ++i)
    {
        for (size_t j = 0; j < other_shape.second; ++j)
        {
            for (size_t k = 0; k < this_shape.second; ++k)
            {
                result._matrix[i][j] += this->_matrix[i][k] * other._matrix[k][j];
            }
        }
    }
    return result;
}

template<typename T>
Vector<T> Matrix<T>::mul_vec(const Vector<T>& other)
{
    auto shape = this->get_shape();
    if (shape.second != other.get_size())
        throw std::runtime_error(RUNTIME_ERROR);
    
    Matrix<T> result(shape.first, 1);

    for (size_t i = 0; i < shape.first; ++i)
    {
        for (size_t k = 0; k < shape.second; ++k)
        {
            result._matrix[i][0] += this->_matrix[i][k] * other.get_vector()[k];
        }
    }

    return result.to_vector();
}

template<typename T>
const T Matrix<T>::trace() const
{
    auto shape = this->get_shape();
    if (shape.first != shape.second)
        throw std::runtime_error(RUNTIME_ERROR);

    T result = 0;
    for (size_t i = 0; i < shape.first; ++i)
    {
        result += this->_matrix[i][i];
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const
{
    auto shape = this->get_shape();
    Matrix result(shape.second, shape.first);

    for (size_t i = 0; i < shape.second; ++i)
    {
        for (size_t j = 0; j < shape.first; ++j)
        {
            result._matrix[i][j] = this->_matrix[j][i];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::row_echelon() const
{
    auto shape = this->get_shape();
    double scalar;

    Matrix result(*this);
    for (size_t i = 0; i < shape.first && i < shape.second; ++i)
    {
        result._put_non_zero_rows_on_top(i, i);
        for (size_t j = i + 1; j < shape.first; ++j)
        {
            if (result._matrix[j][i] == 0)
                continue;
            scalar = -result._matrix[j][i] / result._matrix[i][i];
            result._add_row(j, i, scalar);
        }
    }
    return result;
}

template<typename T>
void Matrix<T>::_put_non_zero_rows_on_top(size_t row, size_t col)
{
    size_t first = row;
    size_t last = this->_matrix.size() - 1;

    while (first < last)
    {
        if (this->_matrix[first][col] == 0)
        {
            std::swap(this->_matrix[first], this->_matrix[last]);
            --last;
        }
        else
        {
            ++first;
        }
    }
}

template<typename T>
void Matrix<T>::_add_row(size_t affected, size_t to_add, double scalar)
{
    for (size_t i = 0; i < this->_matrix[affected].size(); ++i)
    {
        this->_matrix[affected][i] += this->_matrix[to_add][i] * scalar; 
    }
}

template<typename T>
const T Matrix<T>::determinant() const
{
    auto shape = this->get_shape();
    T result = 0;
    if (shape.first != shape.second)
        throw std::runtime_error(RUNTIME_ERROR);
    if (shape.first > 4 || shape.first == 0)
        throw std:: runtime_error(RUNTIME_ERROR);
    
    if (shape.first == 1)
        return this->_matrix[0][0];
    if (shape.first == 2)
        return this->_matrix[0][0] * this->_matrix[1][1] - this->_matrix[0][1] * this->_matrix[1][0];
    if (shape.first == 3)
    {
        Matrix *a = new Matrix({
            {this->_matrix[1][1], this->_matrix[1][2]},
            {this->_matrix[2][1], this->_matrix[2][2]}
        });
        Matrix *b = new Matrix({
            {this->_matrix[1][0], this->_matrix[1][2]},
            {this->_matrix[2][0], this->_matrix[2][2]}
        });
        Matrix *c = new Matrix({
            {this->_matrix[1][0], this->_matrix[1][1]},
            {this->_matrix[2][0], this->_matrix[2][1]}
        });
        result = this->_matrix[0][0] * a->determinant()
                - this->_matrix[0][1] * b->determinant()
                + this->_matrix[0][2] * c->determinant();
        delete a;
        delete b;
        delete c;
        return result;
    }
    if (shape.first == 4)
    {
        Matrix *a = new Matrix({
            {this->_matrix[1][1], this->_matrix[1][2], this->_matrix[1][3]},
            {this->_matrix[2][1], this->_matrix[2][2], this->_matrix[2][3]},
            {this->_matrix[3][1], this->_matrix[3][2], this->_matrix[3][3]}
        });
        Matrix *b = new Matrix({
            {this->_matrix[1][0], this->_matrix[1][2], this->_matrix[1][3]},
            {this->_matrix[2][0], this->_matrix[2][2], this->_matrix[2][3]},
            {this->_matrix[3][0], this->_matrix[3][2], this->_matrix[3][3]}
        });
        Matrix *c = new Matrix({
            {this->_matrix[1][0], this->_matrix[1][1], this->_matrix[1][3]},
            {this->_matrix[2][0], this->_matrix[2][1], this->_matrix[2][3]},
            {this->_matrix[3][0], this->_matrix[3][1], this->_matrix[3][3]}
        });
        Matrix *d = new Matrix({
            {this->_matrix[1][0], this->_matrix[1][1], this->_matrix[1][2]},
            {this->_matrix[2][0], this->_matrix[2][1], this->_matrix[2][2]},
            {this->_matrix[3][0], this->_matrix[3][1], this->_matrix[3][2]},
        });
        result = this->_matrix[0][0] * a->determinant()
                - this->_matrix[0][1] * b->determinant()
                + this->_matrix[0][2] * c->determinant()
                - this->_matrix[0][3] * d->determinant();
        delete a;
        delete b;
        delete c;
        delete d;
        return result;
    }
    return result;
}