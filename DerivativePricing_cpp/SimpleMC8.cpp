//
//  SimpleMC8.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-27.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC8.hpp"
#include "Arrays.hpp"
#include <cmath>

void SimpleMonteCarlo8(const VanillaOption3& TheVanillaOption,
                       double Spot,
                       const Parameters& r,
                       const Parameters& Vol,
                       unsigned long NumOfPaths,
                       StatisticsMC& gatherer,
                       RandomBase& generator)
{
    double Expiry = TheVanillaOption.GetExpiry();
    double spot_curr;
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    
    MJArray variate(1);
    for (unsigned long i=0; i<NumOfPaths; i++)
    {
        generator.GetUniforms(variate);
        spot_curr = Spot * exp(r.Integral(0, Expiry)+0.5*variance-rootVariance*variate[0]);
        double payoff_curr = TheVanillaOption.OptionPayoff(spot_curr);
        gatherer.DumpOneResult(payoff_curr * r.Integral(0, Expiry));
    }
    return;
}
