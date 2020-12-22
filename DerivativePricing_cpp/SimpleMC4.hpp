//
//  SimpleMC4.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-18.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef SimpleMC4_hpp
#define SimpleMC4_hpp

#include "Vanilla2.hpp"
#include <stdio.h>

double SimpleMonteCarlo4(const VanillaOption2& TheVanillaOption,
                           double Spot,
                           double r,
                           double Vol,
                           unsigned long NumOfPaths);


#endif /* SimpleMC4_hpp */
