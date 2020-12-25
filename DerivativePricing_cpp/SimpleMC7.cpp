//
//  SimpleMC7.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-24.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Random1.hpp"
#include "SimpleMC7.hpp"
#include <cmath>

void SimpleMonteCarlo7(const VanillaOption3& TheVanillaOption,
                       double Spot,
                       const Parameters& r,
                       const Parameters& Vol,
                       unsigned long NumOfPaths,
                       StatisticsMC& gatherer)
{
    // note that gatherer is not const
    double Expiry = TheVanillaOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    
    
    double spot_curr;
    for (unsigned long i=0; i<NumOfPaths; i++)
    {
        double gaussian = GetOneGaussianByBoxMuller();
        spot_curr = Spot * exp(r.Integral(0, Expiry) - 0.5*variance + rootVariance*gaussian);
        double payoff_curr = TheVanillaOption.OptionPayoff(spot_curr);
        //statistics routine
        gatherer.DumpOneResult(payoff_curr * exp(-r.Integral(0, Expiry)));
    }
    return;
}
