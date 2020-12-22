//
//  SimpleMC1.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-09.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef SimpleMC1_hpp
#define SimpleMC1_hpp

#include <stdio.h>

double SimpleMonteCarlo1(double strike,
                         double expiry,
                         double spot,
                         double vol,
                         double r,
                         unsigned long numOfPaths);

#endif /* SimpleMC1_hpp */
