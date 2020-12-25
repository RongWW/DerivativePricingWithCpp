//
//  SimpleMC7.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-24.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef SimpleMC7_hpp
#define SimpleMC7_hpp

#include "Vanilla3.hpp"
#include "Parameters.hpp"
#include "MCStatistics.hpp"

void SimpleMonteCarlo7(const VanillaOption3& TheVanillaOption,
                       double Spot,
                       const Parameters& r,
                       const Parameters& Vol,
                       unsigned long NumOfPaths,
                       StatisticsMC& gatherer);

#endif /* SimpleMC7_hpp */
