//
//  SimpleMC2.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-14.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef SimpleMC2_hpp
#define SimpleMC2_hpp

#include "Payoff2.hpp"
#include <stdio.h>

double SimpleMonteCarlo3(const Payoff& thePayoff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long numOfPaths);

#endif /* SimpleMC2_hpp */
