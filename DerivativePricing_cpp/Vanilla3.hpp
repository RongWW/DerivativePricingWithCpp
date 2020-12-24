//
//  Vanilla3.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-23.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef Vanilla3_hpp
#define Vanilla3_hpp

#include "PayoffBridge.hpp"
#include <stdio.h>

class VanillaOption3
{
public:
    VanillaOption3(const PayoffBridge& ThePayoff_, double Expiry_);
    double OptionPayoff(double Spot) const;
    double GetExpiry() const;
    
private:
    double Expiry;
    PayoffBridge ThePayoff;
};

#endif /* Vanilla3_hpp */
