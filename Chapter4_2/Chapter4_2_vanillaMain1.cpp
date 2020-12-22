//
//  main.cpp
//  Chapter4_2
//
//  Created by Rong Wang on 2020-12-17.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC3.hpp"
#include "DoubleDigital.hpp"
#include "Vanilla1.hpp"
#include <iostream>
using namespace std;

int main()
{
    double Expiry;
    double Spot;
    double Lower, Upper;
    double r, Vol;
    unsigned long NumOfPaths;
    
    cout << "\nChapter4_2\n";
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
    VanillaOption theVanillaOption(thePayoff, Expiry);
    
    double price = SimpleMonteCarlo3_2(theVanillaOption, Spot, r, Vol, NumOfPaths);
    
    cout << "\nPrice\n";
    cout << price;
    
    double tmp;
    cin >> tmp;
    
    return 0;
}

