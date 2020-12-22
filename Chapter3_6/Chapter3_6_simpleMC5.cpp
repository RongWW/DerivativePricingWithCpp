//
//  main.cpp
//  Chapter3_6
//
//  Created by Rong Wang on 2020-12-16.
//  Copyright © 2020 RW. All rights reserved.
//

#include "DoubleDigital.hpp"
#include "SimpleMC2.hpp"
#include <iostream>
using namespace std;

int main()
{
    double Expiry;
    double Spot;
    double Lower, Upper;
    double r, Vol;
    unsigned long NumOfPaths;
    
    cout << "\nExpiry\n";
    cin >> Expiry;
    cout << "\nSpot\n";
    cin >> Spot;
    cout << "\nUpperLevel\n";
    cin >> Upper;
    cout << "\nLowerLevel\n";
    cin >> Lower;
    cout << "\nr\n";
    cin >> r;
    cout << "\nVol\n";
    cin >> Vol;
    cout << "\nNumber of Paths\n";
    cin >> NumOfPaths;
    
    PayoffDoubleDigital thePayoff(Lower, Upper);
    
    double price = SimpleMonteCarlo3(thePayoff, Expiry, Spot, Vol, r, NumOfPaths);
    
    cout << "\nPrice\n";
    cout << price;
    
    double tmp;
    cin >> tmp;
    
    return 0;
}
