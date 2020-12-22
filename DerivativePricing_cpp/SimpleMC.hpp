//
//  SimpleMC.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-14.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef SimpleMC_hpp
#define SimpleMC_hpp

#include "Payoff1.hpp"

double SimpleMonteCarlo2(const Payoff& thePayoff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumOfPaths);


#endif /* SimpleMC_hpp */
