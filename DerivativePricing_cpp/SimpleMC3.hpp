//
//  SimpleMC3.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-17.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef SimpleMC3_hpp
#define SimpleMC3_hpp

#include "Vanilla1.hpp"
#include <stdio.h>

double SimpleMonteCarlo3_2(const VanillaOption& TheVanillaOption,
                           double Spot,
                           double r,
                           double Vol,
                           unsigned long NumOfPaths);

#endif /* SimpleMC3_hpp */
