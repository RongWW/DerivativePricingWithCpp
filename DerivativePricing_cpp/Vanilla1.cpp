//
//  Vanilla1.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-17.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Vanilla1.hpp"

VanillaOption::VanillaOption(Payoff& ThePayoff_, double Expiry_) : ThePayoff(ThePayoff_), Expiry(Expiry_)
{
    
}

double VanillaOption::GetExpiry() const
{
    return Expiry;
}

double VanillaOption::OptionPayoff(double Spot) const
{
    return ThePayoff(Spot);
}
