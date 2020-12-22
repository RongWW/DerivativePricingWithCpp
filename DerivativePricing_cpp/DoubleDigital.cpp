//
//  DoubleDigital.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-16.
//  Copyright © 2020 RW. All rights reserved.
//

#include "DoubleDigital.hpp"

PayoffDoubleDigital::PayoffDoubleDigital(double LowerLevel_, double UpperLevel_)
                    : LowerLevel(LowerLevel_),
                      UpperLevel(UpperLevel_)
{
}

double PayoffDoubleDigital::operator() (double Spot) const
{
    if (Spot < LowerLevel)
        return 0;
    if (Spot > UpperLevel)
        return 0;
    
    return 1;
}
