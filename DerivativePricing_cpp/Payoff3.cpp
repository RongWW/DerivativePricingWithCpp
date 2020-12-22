//
//  Payoff3.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-18.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Payoff3.hpp"

PayoffCall3::PayoffCall3(double Strike_) : Strike(Strike_)
{}

double PayoffCall3::operator() (double Spot) const
{
    return Spot-Strike>0 ? Spot-Strike : 0;
}

Payoff3* PayoffCall3::clone() const
{
    return new PayoffCall3(*this);
}

PayoffPut3::PayoffPut3(double Strike_) : Strike(Strike_)
{}

double PayoffPut3::operator() (double Spot) const
{
    return Strike-Spot>0 ? Strike-Spot : 0;
}

Payoff3* PayoffPut3::clone() const
{
    return new PayoffPut3(*this);
}
