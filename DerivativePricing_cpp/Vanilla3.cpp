//
//  Vanilla3.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-23.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Vanilla3.hpp"

VanillaOption3::VanillaOption3(const PayoffBridge& ThePayoff_, double Expiry_) : ThePayoff(ThePayoff_), Expiry(Expiry_)
{
}

double VanillaOption3::OptionPayoff(double Spot) const
{
    return ThePayoff(Spot);
}

double VanillaOption3::GetExpiry() const
{
    return Expiry;
}
