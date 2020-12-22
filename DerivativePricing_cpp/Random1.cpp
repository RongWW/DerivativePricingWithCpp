//
//  Random1.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-11-28.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Random1.hpp"
#include <cstdlib>
#include <cmath>

// using namespace std if it is not VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

double GetOneGaussianBySummation()
{
    double result=0;
    
    for (unsigned long j=0; j < 12; j++)
        result += rand()/static_cast<double>(RAND_MAX);
    
    result -= 6.0;
    
    return result;
    
}

double GetOneGaussianByBoxMuller()
{
    double result;
    double x, y, sizeSquared;
    
    do{
        x = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
        sizeSquared = x*x + y*y;
    }
    while (sizeSquared >= 1.0);
    
    result = x*sqrt(-2*log(sizeSquared)/sizeSquared);
    
    
    
    return result;
}
