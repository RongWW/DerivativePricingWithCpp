//
//  Payoff1.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-13.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Payoff1.hpp"
#include <iostream> 

Payoff::Payoff(double Strike_, OptionType TheOptionType_)
: Strike(Strike_), TheOptionType(TheOptionType_)
{
}

double Payoff::operator ()(double spot) const
{
    switch (TheOptionType) {
        case call:
            return spot-Strike>0 ? spot-Strike:0;
            
        case put:
            return Strike-spot>0 ? Strike-spot:0;
            
        default:
            throw("unknown option type.");
    }
}
