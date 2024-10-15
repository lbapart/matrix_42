#include "Vector.hpp"

Vector::Vector()
{

}

Vector::Vector(const vector<double> &from)
{
    this->_vector = from;
}

Vector::~Vector()
{
    this->_vector.clear();
}

Vector  Vector::operator=(const Vector &other)
{
    this->_vector = other._vector;
}

size_t  Vector::get_size() const
{
    return this->_vector.size();
}

void    Vector::print() const
{
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        std::cout << this->_vector[i] << " ";
    }
    std::cout << std::endl;
}

const vector<double>  Vector::get_vector() const
{
    return this->_vector;
}
