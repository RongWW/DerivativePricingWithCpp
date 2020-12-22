//
//  SimpleMC1.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-09.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC1.hpp"
#include "Random1.hpp"
#include <iostream>
#include <cmath>
using namespace std;

double SimpleMonteCarlo1(double strike,
                         double expiry,
                         double spot,
                         double vol,
                         double r,
                         unsigned long numOfPaths)
{
    double spot_curr;
    double payoffSum=0;
    for (unsigned long i=0; i<numOfPaths; i++)
    {
        double gaussian = GetOneGaussianByBoxMuller();
        spot_curr = spot * exp((r-0.5*vol*vol)*expiry + vol*sqrt(expiry)*gaussian);
        double payoff_curr = (spot_curr-strike)>0 ? (spot_curr-strike) : 0;
        payoffSum += payoff_curr;
    }
    double price = (payoffSum/numOfPaths) * exp(-r*expiry);
    return price;
}



