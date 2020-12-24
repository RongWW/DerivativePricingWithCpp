//
//  PayoffBridge.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-21.
//  Copyright © 2020 RW. All rights reserved.
//

#include "PayoffBridge.hpp"

PayoffBridge::PayoffBridge(const PayoffBridge& original)
{
    ThePayoffPtr = original.ThePayoffPtr->clone();
}

PayoffBridge::PayoffBridge(const Payoff3& innerPayoff)
{
    ThePayoffPtr = innerPayoff.clone();
}

PayoffBridge::~PayoffBridge()
{
    delete ThePayoffPtr;
}

PayoffBridge& PayoffBridge::operator=(const PayoffBridge& original)
{
    if (this != &original)
    {
        delete ThePayoffPtr;
        ThePayoffPtr = original.ThePayoffPtr->clone();
    }
    return *this;
}



