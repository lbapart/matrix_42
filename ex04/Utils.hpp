#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include <stdexcept>

#define RUNTIME_ERROR "Runtime error"

namespace utils
{
    template<typename T>
    T lerp(const T &first, const T &second, const double t)
    {
        if (t < 0 || t > 1)
            throw std::runtime_error(RUNTIME_ERROR);
        
        double first_scalar = 1 - t;
        double second_scalar = t;

        try {
            T result(first);

            result *= first_scalar;
            result += second_scalar * second;
            return result;
        } catch (const std::runtime_error& e){
            throw e;
        }
    }

    template<typename T>
    T abs(const T num)
    {
        return num > 0 ? num : -num;
    }
}
