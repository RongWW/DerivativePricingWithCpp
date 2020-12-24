//
//  SimpleMC6.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-24.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Random1.hpp"
#include "SimpleMC6.hpp"
#include <cmath>

double SimpleMonteCarlo(const VanillaOption3& TheVanillaOption,
                        double Spot,
                        const Parameters& r,
                        const Parameters& Vol,
                        unsigned long NumOfPaths)
{
    double Expiry = TheVanillaOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    
    
    double spot_curr;
    double payoffSum=0;
    for (unsigned long i=0; i<NumOfPaths; i++)
    {
        double gaussian = GetOneGaussianByBoxMuller();
        spot_curr = Spot * exp(r.Integral(0, Expiry) - 0.5*variance + rootVariance*gaussian);
        double payoff_curr = TheVanillaOption.OptionPayoff(spot_curr);
        payoffSum += payoff_curr;
    }
    double price = payoffSum / NumOfPaths * exp(-r.Integral(0, Expiry));
    return price;
}
