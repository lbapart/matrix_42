#include "Vector.hpp"

Vector::Vector()
{

}

Vector::Vector(const vector<double> &from)
{
    this->_vector = from;
}

Vector::Vector(const initializer_list<double> &from)
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
    return *this;
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

ostream& operator<<(ostream &os, const Vector &vector)
{
    for (size_t i = 0; i < vector._vector.size(); ++i)
    {
        os << vector._vector[i] << " ";
    }
    os << std::endl;
    return os;
}

void Vector::add(const Vector& other)
{
    if (this->get_size() != other.get_size())
        throw std::runtime_error(DIFF_VECTOR_SIZES);
    
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        this->_vector[i] += other._vector[i];
    }
}

void Vector::sub(const Vector& other)
{
    if (this->get_size() != other.get_size())
        throw std::runtime_error(DIFF_VECTOR_SIZES);
    
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        this->_vector[i] -= other._vector[i];
    }
}

void Vector::scl(const double multiplier)
{    
    for (size_t i = 0; i < this->_vector.size(); ++i)
    {
        this->_vector[i] *= multiplier;
    }
}