//
//  DoubleDigital.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-16.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef DoubleDigital_hpp
#define DoubleDigital_hpp

#include "Payoff2.hpp"
#include <stdio.h>

class PayoffDoubleDigital : public Payoff
{
public:
    PayoffDoubleDigital(double Lowerleve_, double UpperLevel);
    virtual double operator() (double Spot) const;
    virtual ~PayoffDoubleDigital(){};
    
private:
    double LowerLevel;
    double UpperLevel;
};

#endif /* DoubleDigital_hpp */
