#include "Matrix.hpp"


Matrix::Matrix()
{
    
}

Matrix::Matrix(const vector<vector<double>> &from)
{
    if (from.size() == 0)
        return ;
    size_t row_size = from[0].size();

    for (size_t i = 0; i < from.size(); ++i)
    {
        if (row_size != from[i].size())
            throw std::runtime_error(NOT_RECTANGLE);
    }
    this->_matrix = from;
}

Matrix::Matrix(const std::initializer_list<std::initializer_list<double>> &list)
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

Matrix::~Matrix()
{
    this->_matrix.clear();
}

Matrix Matrix::operator=(const Matrix &other)
{
    this->_matrix = other._matrix;
    return *this;
}

const pair<size_t, size_t>    Matrix::get_shape() const
{
    if (this->_matrix.size() == 0)
        return make_pair(0, 0);
    return make_pair(this->_matrix.size(), this->_matrix[0].size());
}

bool    Matrix::is_square() const
{
    if (this->_matrix.size() == 0)
        return true;
    return this->_matrix.size() == this->_matrix[0].size();
}

void    Matrix::print() const
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

const vector<vector<double>>  Matrix::get_matrix() const
{
    return this->_matrix;
}

ostream& operator<<(ostream &os, const Matrix &matrix)
{
    for (size_t i = 0; i < matrix._matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix._matrix[i].size(); ++j)
        {
            os << setw(WIDTH) << matrix._matrix[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

void Matrix::add(const Matrix &other)
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

void Matrix::sub(const Matrix &other)
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

void Matrix::scl(const double multiplier)
{    
    for (size_t i = 0; i < this->_matrix.size(); ++i)
    {
        for (size_t j = 0; j < this->_matrix[i].size(); ++j)
        {
            this->_matrix[i][j] *= multiplier;
        }
    }
}