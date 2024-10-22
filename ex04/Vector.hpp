#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <cmath>
#include "Matrix.hpp"
#include "Utils.hpp"

#define DIFF_VECTOR_SIZES "Sizes of vectors should be equal"
#define DIFF_SCALAR_AND_VECTOR "Number of vectors should be the same as number of scalars"

using namespace std;

template<typename T>
class Vector
{
    private:
        vector<T>   _vector;
        T           _get_greatest_element_abs() const;
    public:
        Vector();
        Vector(const vector<T> &from);
        Vector(const std::initializer_list<T> &from);
        Vector(const size_t length);
        Vector(const Vector &other);
        Vector &operator=(const Vector &other);
        Vector operator+(const Vector &other) const;
        Vector &operator+=(const Vector &other);
        Vector operator*(const T scalar) const;
        Vector &operator*=(const T scalar);
        ~Vector();
        size_t get_size() const;
        void print() const;
        const vector<T> get_vector() const;
        void add(const Vector &other);
        void sub(const Vector &other);
        void scl(const T multiplier);
        double norm_1() const;
        double norm() const;
        double norm_inf() const;
        T dot(const Vector &other) const;

        template<typename U>
        friend ostream &operator<<(ostream &os, const Vector<U> &vector);
};

template<typename T>
Vector<T>::Vector()
{
}

template<typename T>
Vector<T>::Vector(const vector<T> &from)
{
    this->_vector = from;
}

template<typename T>
Vector<T>::Vector(const initializer_list<T> &from)
{
    this->_vector = from;
}

template<typename T>
Vector<T>::Vector(const size_t length)
{
    this->_vector = vector<T>(length, 0);
}

template<typename T>
Vector<T>::Vector(const Vector &other)
{
    this->_vector = other._vector;
}

template<typename T>
Vector<T>::~Vector()
{
    this->_vector.clear();
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector &other)
{
    if (this == &other)
        return *this; // Handle self-assignment
    this->_vector = other._vector;
    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector &other) const
{
    if (this->get_size() != other.get_size())
        throw std::runtime_error(DIFF_VECTOR_SIZES);
    
    Vector result(*this);
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        result._vector[i] += other._vector[i];
    }
    return result;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector &other)
{
    if (this->get_size() != other.get_size())
        throw std::runtime_error(DIFF_VECTOR_SIZES);

    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        this->_vector[i] += other._vector[i];
    }
    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator*(const T scalar) const
{
    Vector result(*this);

    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        result._vector[i] *= scalar;
    }
    return result;
}

template<typename T>
Vector<T>& Vector<T>::operator*=(const T scalar)
{
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        this->_vector[i] *= scalar;
    }
    return *this;
}

template<typename T>
size_t Vector<T>::get_size() const
{
    return this->_vector.size();
}

template<typename T>
void Vector<T>::print() const
{
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        std::cout << this->_vector[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
const vector<T> Vector<T>::get_vector() const
{
    return this->_vector;
}

template<typename T>
ostream& operator<<(ostream &os, const Vector<T> &vector)
{
    for (size_t i = 0; i < vector._vector.size(); ++i)
    {
        os << vector._vector[i] << " ";
    }
    os << std::endl;
    return os;
}

template<typename T>
Vector<T> operator*(const T scalar, const Vector<T>& vec)
{
    return vec * scalar;
}

template<typename T>
void Vector<T>::add(const Vector& other)
{
    if (this->get_size() != other.get_size())
        throw std::runtime_error(DIFF_VECTOR_SIZES);
    
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        this->_vector[i] += other._vector[i];
    }
}

template<typename T>
void Vector<T>::sub(const Vector& other)
{
    if (this->get_size() != other.get_size())
        throw std::runtime_error(DIFF_VECTOR_SIZES);
    
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        this->_vector[i] -= other._vector[i];
    }
}

template<typename T>
void Vector<T>::scl(const T multiplier)
{    
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        this->_vector[i] *= multiplier;
    }
}

template<typename T>
T Vector<T>::dot(const Vector<T> &other) const
{
    if (this->get_size() != other.get_size())
        throw std::runtime_error(DIFF_VECTOR_SIZES);
    T result = 0;
    
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        result += this->_vector[i] * other._vector[i];
    }
    return result;
}

template<typename T>
double Vector<T>::norm_1() const
{
    double result = 0;

    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        result += this->_vector[i];
    }
    return result;
}

template<typename T>
double Vector<T>::norm() const
{
    double summ = 0;
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        summ += pow(this->_vector[i], 2);
    }
    return pow(summ, 0.5);
}

template<typename T>
double Vector<T>::norm_inf() const
{
    return this->_get_greatest_element_abs();
}

template<typename T>
Vector<T> linear_combination(const vector<Vector<T>> &vectors, const initializer_list<T> &scalars)
{
    if (vectors.size() == 0 && scalars.size() == 0)
        return Vector<T>();
    if (vectors.size() != scalars.size())
        throw std::runtime_error(DIFF_SCALAR_AND_VECTOR);
    vector<T> vec_scalars(scalars);
    size_t vector_size = vectors[0].get_size();
    Vector<T> result(vector_size);
    for (size_t i = 0; i < vectors.size(); ++i)
    {
        if (vector_size != vectors[i].get_size())
            throw std::runtime_error(DIFF_VECTOR_SIZES);
        auto cur_vector = Vector<T>(vectors[i]);
        cur_vector.scl(vec_scalars[i]);
        result.add(cur_vector);
    }
    return result;
}

template<typename T>
T Vector<T>::_get_greatest_element_abs() const
{
    T greatest = 0;
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        if (abs(this->_vector[i]) > abs(greatest))
            greatest = abs(this->_vector[i]);
    }
    return greatest;
}
