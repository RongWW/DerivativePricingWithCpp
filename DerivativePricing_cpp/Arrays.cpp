//
//  Arrays.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-25.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Arrays.hpp"
#include <algorithm>
#include <numeric>

MJArray::MJArray(unsigned long size) : Size(size), Capacity(size)
{
    if (Size>0)
    {
        ValuePtr = new double [size];
        EndPtr = ValuePtr;
        EndPtr += size;
    }
    else
    {
        ValuePtr = 0;
        EndPtr = 0;
    }
}

MJArray::MJArray(const MJArray& original) : Size(original.Size), Capacity(original.Size)
{
    if (Size > 0)
    {
        ValuePtr = new double [Size];
        EndPtr = ValuePtr;
        EndPtr += Size;
        std::copy(original.ValuePtr, original.EndPtr, ValuePtr);
    }
    else
    {
        ValuePtr = 0;
        EndPtr = 0;
    }
}

MJArray::~MJArray()
{
    if (ValuePtr != 0)
        delete [] ValuePtr;
}

MJArray& MJArray::operator=(const MJArray &original)
{
    if (&original == this)
        return *this;
    
    if (original.Size > Capacity)
    {
        if (Capacity > 0)
            delete [] ValuePtr;
        ValuePtr = new double[original.Size];
        Capacity = original.Size;
    }
    
    Size = original.Size;
    EndPtr = ValuePtr;
    EndPtr += Size;
    
    std::copy(original.ValuePtr, original.EndPtr, ValuePtr);
    
    return *this;
}

void MJArray::resize(unsigned long newSize)
{
    if (newSize > Capacity)
    {
        if (Capacity > 0)
            delete [] ValuePtr;
        
        ValuePtr = new double[newSize];
        Capacity = newSize;
    }
    
    Size = newSize;
    EndPtr = ValuePtr + Size;
}

MJArray& MJArray::operator+=(const MJArray& operand)
{
#ifdef RANGE_CHECKING
    if (Size != operand.size())
    {
        throw("to apply += two arrays must be of same size");
    }
#endif
    for (unsigned long i=0; i<Size; i++)
        ValuePtr[i] += operand[i];
    
    return *this;
}

MJArray& MJArray::operator-=(const MJArray& operand)
{
#ifdef RANGE_CHECKING
    if (Size != operand.size())
    {
        throw("to apply -= two arrays must be of same size");
    }
#endif
    for (unsigned long i=0; i<Size; i++)
        ValuePtr[i] -= operand[i];
    
    return *this;
}

MJArray& MJArray::operator*=(const MJArray& operand)
{
#ifdef RANGE_CHECKING
    if (Size != operand.size())
    {
        throw("to apply *= two arrays must be of same size");
    }
#endif
    for (unsigned long i=0; i<Size; i++)
        ValuePtr[i] *= operand[i];
    
    return *this;
}

MJArray& MJArray::operator/=(const MJArray& operand)
{
#ifdef RANGE_CHECKING
    if (Size != operand.size())
    {
        throw("to apply /= two arrays must be of same size");
    }
#endif
    for (unsigned long i=0; i<Size; i++)
        ValuePtr[i] /= operand[i];
    
    return *this;
}

MJArray& MJArray::operator+=(const double& operand)
{
    for (unsigned long i=0; i<Size; i++)
        ValuePtr[i] += operand;
    
    return *this;
}

MJArray& MJArray::operator-=(const double& operand)
{
    for (unsigned long i=0; i<Size; i++)
        ValuePtr[i] -= operand;
    
    return *this;
}

MJArray& MJArray::operator*=(const double& operand)
{
    for (unsigned long i=0; i<Size; i++)
        ValuePtr[i] *= operand;
    
    return *this;
}

MJArray& MJArray::operator/=(const double& operand)
{
    for (unsigned long i=0; i<Size; i++)
        ValuePtr[i] /= operand;
    
    return *this;
}

MJArray& MJArray::operator=(const double& val)
{
    for (unsigned long i=0; i<Size; i++)
        ValuePtr[i] = val;
    
    return *this;
}

double MJArray::sum() const
{
    return std::accumulate(ValuePtr, EndPtr, 0.0);
}

double MJArray::min() const
{
#ifdef RANGE_CHECKING
    if (Size == 0)
    {
        throw("cannot take min of empty array");
    }
#endif
    double* tmp = ValuePtr;
    double* endTmp = EndPtr;
    
    return *std::min_element(tmp, endTmp);
}

double MJArray::max() const
{
#ifdef RANGE_CHECKING
    if (Size == 0)
    {
        throw("cannot take max of empty array");
    }
#endif
    double* tmp = ValuePtr;
    double* endTmp = EndPtr;
    
    return *std::max_element(tmp, endTmp);
}

MJArray MJArray::apply(double f(double)) const
{
    MJArray result(size());
    
    std::transform(ValuePtr, EndPtr, result.ValuePtr, f);
    
    return result;
}
