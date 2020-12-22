//
//  Vanilla1.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-17.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef Vanilla1_hpp
#define Vanilla1_hpp

#include "Payoff2.hpp"
#include <stdio.h>

class VanillaOption
{
public:
    VanillaOption(Payoff& ThePayoff_, double Expiry_);
    double GetExpiry() const;
    double OptionPayoff(double Spot) const;
    
private:
    double Expiry;
    Payoff& ThePayoff;
};

#endif /* Vanilla1_hpp */
