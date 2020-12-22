//
//  main.cpp
//  Chapter_3_2
//
//  Created by Rong Wang on 2020-12-16.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC2.hpp"
#include <iostream>
using namespace std;

int main()
{
    double Expiry, Strike, Spot, r, Vol;
    unsigned long NumOfPaths;
    unsigned int OptionType;
    
    cout << "\nChapter 3_2\n";
    cout << "\nExpiry\n";
    cin >> Expiry;
    cout << "\nStrike\n";
    cin >> Strike;
    cout << "\nSpot\n";
    cin >> Spot;
    cout << "\nr\n";
    cin >> r;
    cout << "\nVol\n";
    cin >> Vol;
    cout << "\nNumber of Paths\n";
    cin >> NumOfPaths;
    cout << "\n0 for Call, 1 for Put\n";
    cin >> OptionType;
    
    Payoff* thePayoffPtr;
    
    if (OptionType == 0)
        thePayoffPtr = new PayoffCall(Strike);
    else
        thePayoffPtr = new PayoffPut(Strike);
    
    double price = SimpleMonteCarlo3(*thePayoffPtr,
                                     Expiry,
                                     Spot,
                                     Vol,
                                     r,
                                     NumOfPaths);
    
    cout << "\nPrice is\n";
    cout << price;
    double tmp;
    cin >> tmp;
    
    delete thePayoffPtr;
    
    return 0;
}
