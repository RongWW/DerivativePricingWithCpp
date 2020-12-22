//
//  Vanilla.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-18.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef Vanilla2_hpp
#define Vanilla2_hpp

#include "Payoff3.hpp"
#include <stdio.h>

class VanillaOption2
{
public:
    VanillaOption2(const Payoff3& ThePayoff_, double Expiry_);
    VanillaOption2(const VanillaOption2& original);
    VanillaOption2& operator=(const VanillaOption2& original);
    ~VanillaOption2();
    
    double GetExpiry() const;
    double OptionPayoff(double Spot) const;
    
private:
    double Expiry;
    Payoff3* ThePayoffPtr;
};

#endif /* Vanilla2_hpp */
