//
//  Chapter2_simpleMC2.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-14.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    double Strike;
    double Expiry;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    cout << "\nChapter 2\n";
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter strike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;
    
    Payoff callPayoff(Strike, Payoff::call);
    Payoff putPayoff(Strike, Payoff::put);
    
    double callPrice = SimpleMonteCarlo2(callPayoff, Expiry, Spot, Vol, r, NumberOfPaths);
    double putPrice = SimpleMonteCarlo2(putPayoff, Expiry, Spot, Vol, r, NumberOfPaths);
    
    cout << "Call price is " << callPrice << "\nPut price is " << putPrice;
    
    double tmp;
    cin >> tmp;
    
    return 0;
}
