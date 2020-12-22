//
//  Vanilla.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-18.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Vanilla2.hpp"

VanillaOption2::VanillaOption2(const Payoff3& ThePayoff_, double Expiry_) : Expiry(Expiry_)
{
    ThePayoffPtr = ThePayoff_.clone();
}

double VanillaOption2::GetExpiry() const
{
    return Expiry;
}

double VanillaOption2::OptionPayoff(double Spot) const
{
    return (*ThePayoffPtr)(Spot);
}

VanillaOption2::VanillaOption2(const VanillaOption2& original)
{
    Expiry = original.Expiry;
    ThePayoffPtr = original.ThePayoffPtr -> clone();
}

// assignment
VanillaOption2& VanillaOption2::operator=(const VanillaOption2& original)
{
    if (this != &original)
    {
        Expiry = original.Expiry;
        delete ThePayoffPtr;
        ThePayoffPtr = original.ThePayoffPtr -> clone();
    }
    
    return *this;
}

// deconstructor
VanillaOption2::~VanillaOption2()
{
    delete ThePayoffPtr;
}
