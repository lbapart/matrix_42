#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>

#define NOT_RECTANGLE "Matrix should be a rectangle"
#define DIFF_MATRIX_SIZES "Sizes of the matrices should be equal"
#define WIDTH 10

using namespace std;

template<typename T>
class Matrix
{
    private:
        vector<vector<T>> _matrix;

    public:
        Matrix();
        Matrix(const vector<vector<T>> &from);
        Matrix(const std::initializer_list<std::initializer_list<T>> &list);
        Matrix(const Matrix &other);
        Matrix &operator=(const Matrix &other);
        Matrix operator+(const Matrix &other) const;
        Matrix &operator+=(const Matrix &other);
        Matrix operator*(const T scalar) const;
        Matrix &operator*=(const T scalar);
        ~Matrix();
        const pair<size_t, size_t> get_shape() const;
        bool is_square() const;
        void print() const;
        const vector<vector<T>> get_matrix() const;
        void add(const Matrix &other);
        void sub(const Matrix &other);
        void scl(const T multiplier);

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
Matrix<T>::~Matrix()
{
    this->_matrix.clear();
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