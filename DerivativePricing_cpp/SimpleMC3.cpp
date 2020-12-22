//
//  SimpleMC3.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-17.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC3.hpp"
#include "Random1.hpp"
#include <cmath>
using namespace std;

double SimpleMonteCarlo3_2(const VanillaOption& TheVanillaOption,
                           double Spot,
                           double r,
                           double Vol,
                           unsigned long NumOfPaths)
{
    double Expiry = TheVanillaOption.GetExpiry();
    
    double spot_curr;
    double payoff_sum = 0;
    for (unsigned long i=0; i<NumOfPaths; i++)
    {
        double gaussian = GetOneGaussianByBoxMuller();
        spot_curr = Spot * exp((r-0.5*Vol*Vol)*Expiry - sqrt(Expiry)*Vol*gaussian);
        double payoff = TheVanillaOption.OptionPayoff(spot_curr);
        payoff_sum += payoff;
    }
    double price = payoff_sum / NumOfPaths * exp(-r*Expiry);
    return price;
}
