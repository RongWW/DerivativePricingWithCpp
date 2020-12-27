//
//  Random2.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-25.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Random2.hpp"
#include "Normals.hpp"
#include <cstdlib>

RandomBase::RandomBase(unsigned long Dimensionality_) : Dimensionality(Dimensionality_)
{}

// transform each element in variates to uniforms, and then inverse it from cdf of standard normal
void RandomBase::GetGaussian(MJArray &variates)
{
    GetUniforms(variates);
    
    for(unsigned long i=0; i<variates.size(); i++)
    {
        double x = variates[i];
        variates[i] = InverseCDFStandardNormal(x);
    }
}

void RandomBase::ResetDimensionality(unsigned long NewDimensionality)
{
    Dimensionality = NewDimensionality;
}
