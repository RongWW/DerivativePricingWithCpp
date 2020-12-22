//
//  SimpleMC.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-14.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC.hpp"
#include "Random1.hpp"
#include <cmath>
using namespace std;

double SimpleMonteCarlo2(const Payoff& thePayoff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumOfPaths)
{
    double spot_curr;
    double payoffSum = 0;
    for (unsigned long i=0; i<NumOfPaths; i++)
    {
        double gaussian = GetOneGaussianByBoxMuller();
        spot_curr = Spot * exp((r-0.5*Vol*Vol)*Expiry - sqrt(Expiry)*Vol*gaussian);
        double payoff_curr = thePayoff(spot_curr);
        payoffSum += payoff_curr;
    }
    double price = (payoffSum / NumOfPaths) * exp(-r*Expiry);
    return price;
}
