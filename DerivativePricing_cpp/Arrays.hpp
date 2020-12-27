//
//  Arrays.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-25.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef MJArrays
#define MJArrays

#include <valarray>
#ifdef USE_VAL_ARRAY

typedef std::valarray<double> MJArray;

#else

class MJArray
{
public:
    explicit MJArray(unsigned long size=0);
    MJArray(const MJArray& original);
    ~MJArray();
    
    MJArray& operator=(const MJArray& original);
    MJArray& operator=(const double& val);
    
    MJArray& operator+=(const MJArray& operand);
    MJArray& operator-=(const MJArray& operand);
    MJArray& operator*=(const MJArray& operand);
    MJArray& operator/=(const MJArray& operand);
    MJArray& operator+=(const double& operand);
    MJArray& operator-=(const double& operand);
    MJArray& operator*=(const double& operand);
    MJArray& operator/=(const double& operand);
    
    MJArray apply(double f(double)) const;
    
    inline double operator[](unsigned long i) const;
    inline double& operator[](unsigned long i);
    inline unsigned long size() const;
    
    void resize(unsigned long newSize);
    
    double sum() const;
    double min() const;
    double max() const;
    
private:
    double* ValuePtr;
    double* EndPtr;
    
    unsigned long Size;
    unsigned long Capacity;
};

inline double MJArray::operator[](unsigned long i) const
{
#ifdef RANGE_CHECKING
    if (i>=Size)
    {
        throw("Index out of bounds");
    }
#endif
    return ValuePtr[i];
}

inline double& MJArray::operator[](unsigned long i)
{
#ifdef RANGE_CHECKING
    if (i>=Size)
    {
        throw("Index out of bounds");
    }
#endif
    return ValuePtr[i];
}

inline unsigned long MJArray::size() const
{
    return Size;
}

#endif // ifdef USE_VAL_ARRAY
#endif // ifndef MJArrays
