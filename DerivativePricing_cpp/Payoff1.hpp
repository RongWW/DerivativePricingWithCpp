//
//  Payoff1.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-13.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef Payoff1_hpp
#define Payoff1_hpp

#include <stdio.h>

class Payoff
{
public:
    enum OptionType {call, put};
    Payoff(double Strike_, OptionType TheOptionType_);
    double operator()(double Spot) const;
    
private:
    double Strike;
    OptionType TheOptionType;
};

#endif /* Payoff1_hpp */
