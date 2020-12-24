//
//  SimpleMC5.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-23.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef SimpleMC5_hpp
#define SimpleMC5_hpp

#include "Vanilla3.hpp"
#include <stdio.h>

double SimpleMonteCarlo5(const VanillaOption3& TheVanillaOption,
                         double Spot,
                         double r,
                         double Vol,
                         unsigned long NumOfPaths);

#endif /* SimpleMC5_hpp */
