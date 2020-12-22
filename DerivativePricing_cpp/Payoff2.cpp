//
//  Payoff2.cpp
//  
//
//  Created by Rong Wang on 2020-12-14.
//

#include "Payoff2.hpp"

PayoffCall::PayoffCall(double Strike_) : Strike(Strike_)
{}

double PayoffCall::operator () (double Spot) const
{
    return Strike-Spot>0 ? Strike-Spot : 0;
}

PayoffPut::PayoffPut(double Strike_) : Strike(Strike_)
{}

double PayoffPut::operator () (double Spot) const
{
    return Spot-Strike>0 ? Spot-Strike : 0;
}
