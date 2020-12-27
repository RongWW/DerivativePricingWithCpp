//
//  SimpleMC8.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-27.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef SimpleMC8_hpp
#define SimpleMC8_hpp

#include "Vanilla3.hpp"
#include "Parameters.hpp"
#include "Random2.hpp"
#include "MCStatistics.hpp"

void SimpleMonteCarlo8(const VanillaOption3& TheVanillaOption,
                       double Spot,
                       const Parameters& r,
                       const Parameters& Vol,
                       unsigned long NumOfPaths,
                       StatisticsMC& gatherer,
                       RandomBase& generator);

#endif /* SimpleMC8_hpp */
