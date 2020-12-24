//
//  SimpleMC5.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-23.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC5.hpp"
#include "Random1.hpp"
#include <cmath>

double SimpleMonteCarlo5(const VanillaOption3& TheVanillaOption,
                         double Spot,
                         double r,
                         double Vol,
                         unsigned long NumOfPaths)
{
    double Expiry = TheVanillaOption.GetExpiry();
    
    double spot_curr;
    double Payoff_sum = 0;
    
    for (unsigned long i=0; i<NumOfPaths; i++)
    {
        double gaussian = GetOneGaussianByBoxMuller();
        spot_curr = Spot * exp((r-0.5*Vol*Vol)*Expiry - sqrt(Expiry)*Vol*gaussian);
        double payoff_curr = TheVanillaOption.OptionPayoff(spot_curr);
        Payoff_sum += payoff_curr;
    }
    
    double price = Payoff_sum / NumOfPaths * exp(-r*Expiry);
    return price;
}
