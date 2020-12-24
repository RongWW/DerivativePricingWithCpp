//
//  PayoffBridge.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-21.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef PayoffBridge_hpp
#define PayoffBridge_hpp

#include "Payoff3.hpp"
#include <stdio.h>

class PayoffBridge
{
public:
    PayoffBridge(const PayoffBridge& original);
    PayoffBridge(const Payoff3& innerPayoff);
    
    inline double operator() (double Spot) const;
    ~PayoffBridge();
    PayoffBridge& operator=(const PayoffBridge& original);
    
private:
    Payoff3* ThePayoffPtr;
};

inline double PayoffBridge::operator() (double Spot) const
{
    return ThePayoffPtr->operator () (Spot);
}

#endif /* PayoffBridge_hpp */
