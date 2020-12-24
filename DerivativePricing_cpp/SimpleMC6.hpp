//
//  SimpleMC6.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-24.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef SimpleMC6_hpp
#define SimpleMC6_hpp

#include "Vanilla3.hpp"
#include "Parameters.hpp"
#include <stdio.h>

double SimpleMonteCarlo6(const VanillaOption3& TheVanillaOption,
                         double Spot,
                         const Parameters& r,
                         const Parameters& Vol,
                         unsigned long NumOfPaths);

#endif /* SimpleMC6_hpp */
