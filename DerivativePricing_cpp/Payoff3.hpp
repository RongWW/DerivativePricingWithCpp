//
//  Payoff3.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-18.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef Payoff3_hpp
#define Payoff3_hpp

#include <stdio.h>

class Payoff3
{
public:
    Payoff3(){};
    virtual double operator() (double Spot) const=0;
    virtual ~Payoff3(){}
    virtual Payoff3* clone() const=0;
    
private:
};

class PayoffCall3 : public Payoff3
{
public:
    PayoffCall3(double Strike_);
    virtual double operator() (double Spot) const;
    virtual ~PayoffCall3(){}
    virtual Payoff3* clone() const;
    
private:
    double Strike;
};

class PayoffPut3 : public Payoff3
{
public:
    PayoffPut3(double Strike_);
    virtual double operator() (double Spot) const;
    virtual ~PayoffPut3(){}
    virtual Payoff3* clone() const;
    
private:
    double Strike;
};

#endif /* Payoff3_hpp */
